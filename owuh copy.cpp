#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n,m,t;
    cin >> n >> m >> t;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    auto r = p.end();
    auto l = p.begin();
    int tot = 0;
    while(m)
    {
        // get next creature from both l & r, proceed with the better one
        auto rr = r;
        auto ll = l;
        int c1 = 0;
        int c2 = 0;
        int tt = t;
        int tt2 = t;
        while(tt > 0)
        {
            if(ll == p.end())
            {
                cout << "-1\n";
                return;
            }
            c1 += *ll;
            tt-=*ll;
            ll++;
        }
        while(tt2 > 0)
        {
            if(rr == p.begin())
            {
                cout << "-1\n";
                return;
            }
            rr--;
            c2 += *rr;
            tt2-=*rr;
        }
        if(tot+c2 < tot+c1) // less -ve
            r = rr;
        else
            l = ll;
        if(distance(l,r) < 0)
        {
            cout << "-1\n";
            return;
        }
        m--;
    }
    int ans = 0;
    for(auto i = l; i != r; ++i)
    {
        ans+=*i;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}