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

float tdp(float f)
{
    return f;
    //return ceil(100.0*f)/100.0;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //Main Prog
    float debt = 100.00;
    float i,r;
    cin >> i >> r;
    float tot = 0.00;
    r /= 100.00;
    i /= 100.00;
    //cout << debt << endl;
    while(debt > 0.00)
    {
        //cout << debt*i << endl;
        debt += tdp(debt*i);
        //cout << debt << endl;
        if(max((float)50.00,tdp(debt*r)) < debt)
            tot += max((float)50.00,tdp(debt*r));
        //cout << max((float)50.00,tdp(debt*r)) << endl;
        else
            tot += debt;
        debt -= max((float)50.00,tdp(debt*r));
    }
    cout << tot << endl;
    return 0;
}

