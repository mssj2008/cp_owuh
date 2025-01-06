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

// can alternatively find the sum of interval(same odd/even parity with the power of powers...) and just check if thts even with n*(n+1)/2 :///
// did it this way cuz thts wht came to my mind first
void solve()
{
    int n,r; cin >> n >> r;
    int sum = 0;
    vector<int> fam(n);
    for(int i = 0; i < n; i++)
    {
        cin >> fam[i];
        sum += fam[i];
    }
    if(sum <= r)
    {
        cout << sum << "\n";
        return;
    }
    int parity = 0;
    int ans = 0;
    sort(fam.begin(),fam.end());
    for(auto i : fam)
    {
        if(sum <= r)
        {
            ans += sum;
            break;
        }
        if(parity == 0)
        {
            ans += i-(i%2);
            parity = i%2;
            r -= (i+(i%2))/2;
        }
        else
        {
            ans += i-2+(i%2);
            parity -= i%2;
            r -= ((i+(i%2))/2)-(i%2);
        }
        sum -= i;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //Main Prog
    int tt; cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}

