#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define  inrange(x) ((x)>=0 && (x)<=7)
#define cinrange(x) (inrage((x).first) && inrange((x).second))
#define p2(R,L,i) Parse(R,Parse(L,Parse(R,i)))
typedef long long ll;
typedef unsigned long long ull;

ull T(ull i)
{
    ull ans = 1;
    while(ans*(ans+1)/2 < i)
        ans++;
    return ans;
}

ull E(ull i)
{
    return 2*i;
}

ull O(ull i)
{
    return 2*i-1;
}



ull Parse(string s,ull i)
{
    if(s.length() == 1)
    {
        switch(s[0])
        {
            case 'E':
                return E(i);
                break;
            
            case 'O':
                return O(i);
                break;

            case 'T':
                return T(i);
                break;
        }
    }
    else
    {
        string R = "";
        R += s.back();
        if(R != ")")
        {
        string L = s;
        L.erase(s.length()-1,1);
        return p2(R,L,i);
        }
        else
        {
            int bc = 1; // bracket count;
            int bi = s.length()-2;
            int l = 1;
            while(bc && bi >= 0)
            {
                if(s[bi] == ')')
                    bc++;
                if(s[bi] == '(')
                    bc--;
                R+=s[bi];
                bi--;
                l++;
            }
            if(bi < 0)
            {
                reverse(R.begin(),R.end());
                R = R.substr(1,l-2);
                return Parse(R,i);
            }
            else
            {
                reverse(R.begin(),R.end());
                R = R.substr(1,l-2);
                string L = s.substr(0,bi+1);
                return p2(R,L,i);
            }
        }
        //cout << ss + " " + s2 << endl;
        //return 0;
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    // 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 6 6 6 6 6 6 7 7 7 7 7 7 7
    ull i;
    string s;
    cin >> s >> i;
    vector<string> ss = {s};
    cout << Parse(s,i);
    return 0;
}