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

int RN[7]={1000,500,100,50,10,5,1};
char RNC[7]={'M','D','C','L','X','V','I'};
int SRN[6] = {900,400,90,40,9,4};
string SRNS[6] = {"CM","CD","XC","XL","IX","IV"};

string NtoR(int n)
{
    string Rn = "";
    int ci = 0;
    int cn = 0;
    string draft = "";
    while(n)
    {
    cn = 0;
    draft = "";
    while(n >= RN[ci])
    {
        cn++;
        n-=RN[ci];
        draft+=RNC[ci];
    }
    Rn+=draft;
    ci++;
    if(n>=SRN[ci-1])
    {
        n -= SRN[ci-1];
        Rn += SRNS[ci-1];
    }
    if(ci > 8)
    return Rn;
    }
    return Rn;
}

int rls(char c)
{
    int s = 7;
    for(int i = 0; i < 7; i++)
    {
        if(c == RNC[i])
            return s;
        s--;
    }
    return s;
}

string romanlook(string s)
{
    if(s.length() == 1)
        return "I"+s[0];
    string result = "";
    char rc = s[0];
    int cn = 1;
    for(int i = 1; i < s.length(); i++)
    {
        if(s[i] != rc)
        {
            string rn = NtoR(cn);
            result += rn + rc;
            rc = s[i];
            cn = 1;
        }
        else
            cn++;
    }
    string r = NtoR(cn);
    result += r + rc;
    return result;
}

bool vc(char c1,char c2)
{
    string s = "";
    s+=c1;
    s+=c2;
    for(int i = 0; i < 6; i++)
    {
        if(SRNS[i] == s)
            return true;
    }
    return false;
}

bool is_roman(string s)
{
    if(s.length() == 1)
        return true;
    char rc = s[0];
    int cn = 1;
    int curs = rls(s[0]);
    if(rls(s[0]) < rls(s[1]))
        if(!vc(s[0],s[1]))
            return false;
    for(int i = 1; i < s.length(); i++)
    {
        if(s[i] == rc)
        {
            cn++;
            if(cn > 3)
                return false;
        }
        else
        {
            if(rls(s[i]) > curs)
                return false;
            if(rls(s[i]) > rls(s[i-1]))
            {
                if(!vc(s[i-1],s[i]))
                    return false;
                //if(i < s.length()-1 && rls(s[i+1]) >= rls(s[i]))
                    //return false;
            i++;
            if(i < s.length())
            {
                curs = rls(s[i])-1;
                rc = s[i];
                cn = 1;
            }
            continue;
            }
            curs = rls(s[i]);
            rc = s[i];
            cn = 1;
        }
    }
    return true;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //Part b
    //set<string
    //cout << rls('X') << endl;
    //cout << is_roman("XV") << endl;
    //cout << is_roman("IIMIIX") << endl;
    //cout << is_roman("MCXI") << endl;
    //cout << is_roman("MCDXCIV") << endl;
    //cout << is_roman("MMMDCCLXXXIX") << endl;
    //cout << is_roman("MMIXX") << endl;
    //return 0;
    //Part c
    /*
    set<string> rnl;
    for(int i = 1; i < 4000; i++)
    {
        string s = NtoR(i);
        s = romanlook(s);
        if(rnl.count(s) == 0)
            rnl.insert(s);
    }
    cout << rnl.size();
    return 0;
    */
    // Main Prog
    string s;
    int i;
    cin >> s >> i;
    for(int a = 0; a < i; a ++)
    {
        s = romanlook(s);
    }
    int in = 0;
    int vn = 0;
    //cout << s << endl;
    for(char c : s)
    {
        if(c == 'I')
            in++;
        else if(c == 'V')
            vn++;
    }
    cout << in << " " << vn << endl;
    return 0;
}

