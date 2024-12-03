#include <bits/stdc++.h>

using namespace std;

#define endl "\n";

void solve()
{
    int n;
    cin >> n;
    multiset<int> s;
    int ans = 0;
    while(n--)
    {
        int a;
        cin >> a;
        s.insert(a);
        ans++;
    }
    ans-=2;
    vector<pair<int,int>> facts;
    for(int i = 1; i*i < ans+1; i++)
    {
        if(ans % i == 0)
        {
            facts.push_back({i,ans/i});
        }
    }
    for(auto i : facts)
    {
        if(i.first == i.second && s.count(i.first) >= 2)
        {
            cout << i.first << " " << i.first << endl;
            return;
        }
        if(i.first != i.second && s.count(i.first) && s.count(i.second))
        {
            cout << i.first << " " << i.second << endl;
            return;
        }
    }
    //cout << "1" << " " << ans << endl; 
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