#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define inrange(x) ((x)>=0 && (x)<=7)
#define cinrange(x) (inrage((x).first) && inrange((x).second))
#define p2(R,L,i) Parse(R,Parse(L,Parse(R,i)))
#define glp(s) get_letter_profile((s))
#define coord pair<int,int>
#define coord2 pair<coord,coord>
#define x first
#define y second
#define pb(x) push_back((x))
#define wt wordtarget
#define st scoretarget
#define sl(a) ((a)-'A'+1)
typedef long long ll;
typedef unsigned long long ull;

string _btar = "RRGBRGBB";

string nextr(string s)
{
    string r;
    for(int i = 0; i < s.length()-1; i++)
    {
        int a = s[i+1];
        int b = s[i];
        if(a==b)
            r+=s[i];
        else if(b+a=='B'+'R')
            r+='G';
        else if(b+a=='B'+'G')
            r+='R';
        else if(b+a=='R'+'G')
            r+='B';
    }
    return r;
}

int pp(int a,int b)
{
        if(a==b)
            return a; 
        else if(b+a=='B'+'R')
            return 'G';
        else if(b+a=='B'+'G')
            return 'R';
        else if(b+a=='R'+'G')
            return 'B';
}

void partb(string cur="",int depth=1)
{
    string cs = "RGB";
    //cout << cur << endl;
    if(cur.length() > 1 && (char)pp(cur[cur.length()-1],cur[cur.length()-2]) != _btar[cur.length()-2])
        return;
    if(cur.length() == 9)
    {
        cout << cur << endl;
        return;
    }
    for(char c : cs)
        partb(cur+c,depth+1);
}

string grr(int n)
{
    string cs = "RGB";
    string s;
    for(int i = 0; i < n; i++)
    {
        s+=cs[(rand() + i) % 3];
    }
    return s;
}

char parta(string s)
{
    while(s.length()>1)
    {
        s = nextr(s);
    }
    return s[0];
}

void partc()
{
    int length = 6;
    string combos[] = {"RR","RG","RB","GG","GB","BB"};
    while(true)
    {
        int f = 0;
        string m = grr(length-2);
        string m2 = grr(length-2);
        for(auto s : combos)
        {
            char cc = pp(s[0],s[1]);
            string t = s[0] + m + s[1];
            string t2 = s[1] + m + s[0];
            string t3 = s[0] + m2 + s[1];
            string t4 = s[1] + m2 + s[0];
            if(parta(t) != cc)
            {
                f = 1;
                break;
            }
            if(parta(t2) != cc)
            {
                f = 1;
                break;
            }
            if(parta(t3) != cc)
            {
                f = 1;
                break;
            }
            if(parta(t4) != cc)
            {
                f = 1;
                break;
            }
        }
        if(f == 0)
        {
        cout << length+2 << endl; // ADD THE FUCKING 2 !!!! >:(
        return;
        }
        length++;
    }
}


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //Part c
    partc();
    return 0;
    //Partb
    /*
    partb();
    //cout << (char)pp('R','R') << endl;
    return 0;
    */
    //Part b
    //Main Prog
    string s;
    cin >> s;
    while(s.length()>1)
    {
        s = nextr(s);
    }
    cout << s << endl;
    return 0;
}

