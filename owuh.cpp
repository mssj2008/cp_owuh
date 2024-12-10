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

int cl = 1;

int nn[10000];

void rn(int n,int i)
{
    for(int i = i+n; i<10000; i += n)
    {
        nn[i] = -1;
    }
}

void gnl()
{
while(cl < 10000)
{
    int i = cl/2;
    while(nn[i] == -1)
    {
        i++;
        if(i == 10000)
            return;
    }
    cl = nn[i];
    rn(cl,cl/2);
}
}


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //Main Prog
    for(int i = 0; i < 10000; i++)
        nn[i] = i*2+1;
    gnl();
    int num; cin >> num;
    for(int i=num-1; i > 0; i--)
    {
        if(i%2 == 0) continue;
        if(nn[i/2] != -1)
        {
        cout << nn[i/2] << " ";
        break;
        }
    }
    for(int i = num+1; i < 10000; i++)
    {
        if(i%2==0) continue;
        if(nn[i/2] != -1)
        {
            cout << nn[i/2] << endl;
            break;
        }
    }
    return 0;
}

