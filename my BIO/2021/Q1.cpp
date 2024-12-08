#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define inrange(x) ((x)>=0 && (x)<=7)
#define cinrange(x) (inrage((x).first) && inrange((x).second))
#define p2(R,L,i) Parse(R,Parse(L,Parse(R,i)))
#define glp(s) get_letter_profile((s))
#define wt wordtarget
#define st scoretarget
#define sl(a) ((a)-'A'+1)
typedef long long ll;
typedef unsigned long long ull;

bool alpha_order(string l,string r)
{
    char lmin = 'Z';
    char rmax = 'A';
    for(char c : l)
        if(lmin > c)
            lmin = c;
    for(char c : r)
        if(rmax < c)
            rmax = c;
    return lmin > rmax;
}

bool ispat(string s)
{
    if(s.length() == 1)
        return true;
    string r,l;
    for(int i = 1; i < s.length(); i++)
    {
        l = s.substr(0,i);
        r = s.substr(i,s.length()-i);
        string rl = l;
        string rr = r;
        reverse(rr.begin(),rr.end());
        reverse(rl.begin(),rl.end());
        if(alpha_order(l,r) && ispat(rl) && ispat(rr))
            return true;
    }
    return false;
}


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //Part B
/*
    string s = "ABCD";
    if(ispat(s))
        cout << s << endl;
    while(next_permutation(s.begin(),s.end()))
    {
        if(ispat(s))
            cout << s << endl;
    }
    return 0;
    ANS =
    BDCA
    CBDA
    CDAB
    DACB
    DBAC
*/
/*
    Part C
*/
    // Main Prog
    string s1,s2;
    cin >> s1 >> s2;

    if(ispat(s1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    if(ispat(s2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    if(ispat(s1+s2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

// 1a = 1b in 35 min
