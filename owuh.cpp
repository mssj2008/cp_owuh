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



int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //Main Prog
    int tt; cin >> tt;
    while(tt--)
    {
    int n,m;
    vector<int> words;
    cin >> n >> m;
    while(n--)
    {
        string s; cin>>s;
        words.push_back(s.size());
    }
    //sort(words.begin(),words.end());
    int x = 0;
    for(int i = 0; i < words.size(); i++)
    {
        m -= words[i];
        if(m >= 0)
            x++;
        else
            break;
    }
    cout << x << "\n";
    }
    return 0;
}

