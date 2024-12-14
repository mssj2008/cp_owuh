uses dos,crt;

const

highl : integer=32000;
lowl  : integer=3200;

var
units  : integer;
vals   : array [0..100] of longint;
sols   : array [0..100,0..100] of longint;
nsols  : integer;
limit  : integer;
fracd  : integer;
fracq  : integer;
fd, fq : longint;
fd2,fq2: longint;
a,b    : longint;
u,v,w,x,y,z : integer;
fr     : real;
calc   : real;
min    : integer;

procedure getfrac;
var
code: integer;
s1 : string;
begin;
write('Numerator: ');
readln(s1);
val(s1,fracq,code);
write('Denominator: ');
readln(s1);
val(s1,fracd,code);
end;



begin;
clrscr;
getfrac;
limit:=0;
fr:=fracq/fracd;
nsols:=0;
min:=-100;
units:=0;
if fracq=1 then
   begin;
   writeln('Already a unit fraction?!?!');
   readln;
   end;

repeat
if limit=0 then limit:=lowl else
  begin;
  limit:=highl;
  units:=0;
  end;
repeat
units:=units+1;
for x:=0 to 100 do vals[x]:=x+1;
dec(vals[units]);
limit:=lowl*units;
repeat

inc(vals[units]);
repeat
  u:=0;
  for v:=1 to units do if vals[v]>(limit-units+v) then
    begin;
    inc(vals[v-1]);
    for w:=v to units do vals[w]:=vals[w-1]+1;
    u:=1;
    end;
until u=0;

fd:=vals[1];
fq:=1;

for u:=2 to units-1 do
   begin;
   fq:=vals[u]*fq+fd;
   fd:=fd*vals[u];
   a:=fq; b:=fd;
   repeat
   if a>b then a:=a mod b
          else b:=b mod a;
   until (a=0) or (b=0) or (a<0) or (b<0);
   if a>0 then
       begin;
       fq:=round(fq/a);
       fd:=round(fd/a);
       end;
   if b>0 then
       begin;
       fq:=round(fq/b);
       fd:=round(fd/b);
       end;
   end;

if units>1 then
   begin
   fq2:=fd*fracq-fq*fracd;
   fd2:=fracd*fd;
   end
else
   begin
   fq2:=fracq;
   fd2:=fracd;
   end;

if fq2>0 then
   begin;
   if (frac(fd2/fq2)=0) and (round(fd2/fq2)>vals[units-1]) then
      begin;
      vals[units]:=round(fd2/fq2);
      if min=-100 then min:=units;
      nsols:=nsols+1;
      for w:=1 to units do sols[nsols,w]:=vals[w];
      sols[nsols,0]:=units;
      y:=sols[1,0];
        for x:=1 to nsols do
        if (sols[x,y]<sols[0,y]) or (sols[0,y]=0) then
        for w:=0 to y do sols[0,w]:=sols[x,w];
        gotoxy(1,3);
        write('                                                            ');
        gotoxy(1,3);
        write('Current Optimal Solution: ');
        for w:=1 to y do write(sols[0,w],' ');
      end;
   end;
vals[units]:=limit+1;

x:=0;
repeat
  inc(x);
  calc:=fr;
  for y:=1 to x do calc:=calc-1/vals[y];
  for y:=x+1 to units do calc:=calc-1/(limit-units+y);
until (calc<0) or (x=units);
if (calc<0) and (x<>units) then vals[x+1]:=limit+1;

x:=0;
repeat
  inc(x);
  calc:=fr;
  for y:=1 to x do calc:=calc-1/vals[y];
  for z:=x+1 to units do calc:=calc-1/(vals[y]+(z-y));
until (calc>0) or (x=units);
if (calc>0) and (x<>units) then vals[x+1]:=limit+1;


calc:=fr-1/vals[1];
for u:=1 to units-1 do calc:=calc-1/(vals[1]+u);
if calc>0 then vals[1]:=limit-units+1;

until vals[1]=limit-units+1;
until ((units=100) and (limit=highl)) or ((units=8) and (limit=lowl))or (min<>-100); {units repeat loop}
until ((units=100) and (limit=highl)) or (min<>-100);

y:=sols[1,0];
for x:=1 to nsols do
  if (sols[x,y]<sols[0,y]) or (sols[0,y]=0) then
  for w:=0 to y do sols[0,w]:=sols[x,w];

gotoxy(1,3);
write('                                                            ');
gotoxy(1,3);
writeln(' ');
write('Optimal Solution: ');
for w:=1 to y do write(sols[0,w],' ');



end.