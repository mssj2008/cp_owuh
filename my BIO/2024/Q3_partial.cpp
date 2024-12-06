#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define  inrange(x) ((x)>=0 && (x)<=7)
#define cinrange(x) (inrage((x).first) && inrange((x).second))
#define p2(R,L,i) Parse(R,Parse(L,Parse(R,i)))
#define glp(s) get_letter_profile((s))
#define wt wordtarget
#define st scoretarget
#define sl(a) ((a)-'A'+1)
typedef long long ll;
typedef unsigned long long ull;

string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<int> target(26);
string wordtarget = "";
int scoretarget = 0;
ull order_count = 0;


vector<int> get_letter_profile(string s)
{
    vector<int> profile(26);
    for(char c : s)
    {
        profile[c-'A']++;
    }
    return profile;
}

int get_score(string s)
{
    int score = 0;
    for(char c : s)
    {
        score += c-'A'+1;
    }
    return score;
}

void get_order(string cur,int curs = 0) // current score
{
    for(char c : letters)
    {
        if(cur.back() == c)
            continue;
        int ns = curs+sl(c);
        if(ns > st)
        {
            return;
        }
        else if(ns == st)
        {
            order_count++;
            string s = cur;
            s += c;
            //cout << order_count << " " << s << endl;
            if(s == wt)
            {
                cout << order_count << endl;
                exit(0);
            }
            return;
        }
        else
        {
            string s = cur;
            s+=c;
            get_order(s,ns);
        }
    }
    return;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    cin >> wt;
    st = get_score(wt);
    get_order("",0);
    cout << st << endl;
//
//
//  ~30 min 
//  Algorithm wroks but very very very slooow...
//

    //cout << Parse(s,i);
    return 0;
}