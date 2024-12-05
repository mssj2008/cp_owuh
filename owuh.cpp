#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define  inrange(x) ((x)>=0 && (x)<=7)
#define cinrange(x) (inrage((x).first) && inrange((x).second))
typedef long long ll;
typedef unsigned long long ull;

ull tpow(int x)
{
    ull n = 1;
    for(int i = 0; i < x; i++)
        n*= 10;
    return n;
}

int tlog(ull n)
{
    string s = to_string(n);
    return s.length()-1;
}

char getlastch(ull n)
{
    string s = to_string(n);
    return s[s.length()-1];
}

ull get_chars(ull s,ull c)
{
    ull ans = 0;
    c+=s-1;
    while(tlog(s) != tlog(c))
    {
        ull a = (tpow(tlog(s)+1)-s)*(tlog(s)+1);
        ans += a;
        s = tpow(tlog(s)+1);
    }
    ans += (c-s+1)*(tlog(s)+1);
    return ans;
}


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ull x,y;
    cin >> x >> y;
    ull c = 0x100000000000000ULL;
    while(y > tlog(x))
    {
        while(get_chars(x,c) > y)
            c = c >> 1;
        y-=get_chars(x,c);
        x = x+c;
    }
    if(y == 0)
    {
        cout << getlastch(x-1) << endl;
        return 0;
    }
    string s = to_string(x);
    cout << s[y-1] << endl;
    return 0;
}