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

string Decrypt(string s)
{
    for(int i = s.length()-1; i > 0; i--)
    {
        if(sl(s[i])-sl(s[i-1]) > 0)
            s[i] = sl(s[i])-sl(s[i-1])-1+'A';
        else
            s[i] = sl(s[i])-sl(s[i-1])+26-1+'A';
    }
    return s;
}

string Encrypt(string s)
{
    for(int i = 1; i < s.length(); i++)
    {
        s[i] = ((sl(s[i])+sl(s[i-1]))%26)-1+'A';
    }
    return s;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    //Main PRogrma
    //string s;
    //cin >> s;
    //cout << Decrypt(s);

    // PArt b : ZZZZZ

    // Part c
    /*string s = "OLYMPIAD";
    int count = 1;
    while(Encrypt(s) != "OLYMPIAD")
    {
        s = Encrypt(s);
        count++;
    }
    cout << count << endl;*/


    //  PArt D coudlnt do correctyl still dk the soltuion
    return 0;
}

/*

30 min
gd howver i tcouldve been MUCH better if u stoopeped goofing and went straight
to the right adn best sloltiuon first :/ like maybe 15 minutes even :/

Extneded stuff is still mmph :/ patten up
*/