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


vector<vector<ull>> get_combos(string park)
{
    vector<vector<ull>> combos;
    string park2(park.length(),' ');
    vector<int> cpark(park.length());
    for(int i = 0; i < park.length(); i++)
    {
        cpark[park[i]-'a'] = i;
    }
    combos.push_back({cpark[0]});
    park2[cpark[0]] = 'a';
    //cout << cpark[0] << " ";
    for(int c = 1; c < cpark.size(); c++)
    {
        //cout << cpark[c] << " ";
        combos.push_back({cpark[c]});
        for(int i = cpark[c]-1; park2[i]!=' ' && i >= 0; i--)
        {
            combos.back().push_back(i);
        }
        sort(combos.back().begin(),combos.back().end());
        park2[cpark[c]] = c+'a';
    }
    //cout << endl;
    return combos;
}

vector<ull> get_multi(vector<vector<ull>> &combos)
{
    vector<ull> multi(combos.size());
    ull cur = 1;
    multi[multi.size()-1] = 1;
    for(int i = combos.size()-2; i >= 0; i--)
    {
        //cout << i << endl;
        multi[i] = combos[i+1].size()*cur;
        cur = multi[i];
    }
    return multi;
}

vector<int> get_path(vector<vector<ull>> &combos,vector<ull> &multi,ull index,ull cur = -1)
{
    cur = 1;
    int depth = 0;
    vector<int> path(multi.size(),0);
    while(depth < multi.size())
    {
        int ii = 0;
        while(ii < combos[depth].size() && index-cur >= multi[depth])
        {
            cur += multi[depth];
            ii++;
        }
        path[depth] = combos[depth][ii];
        depth++;
    }
    return path;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    string s;
    ull idx;
    cin >> s >> idx;
    vector<vector<ull>> combos = get_combos(s);
    //for(auto i : combos)
    //{
        //for(auto j : i)
            //cout << j << " ";
        //cout << endl;
    //}
    //cout << endl;
    //cout << "combo done" << endl;
    vector<ull> multi = get_multi(combos);
    //for(ull i : multi)
    //{
        //cout << i << " ";
    //}
    //cout << endl;
    //cout << "multi done" << endl;
    vector<int> path = get_path(combos,multi,idx);
    //cout << "path generated" << endl;
    string com;
    for(int i : path)
    {
        //cout << i << " ";
        com+=(i+'A');
    }
    //cout << endl;
    cout << com << endl;
    return 0;
}

/*

didnt track time... :/ XD
the osltuoin i saw from vid made me clock the idea
took to fucking long to imeplemnt idfk why... :/
but ye
My problem was i thought the ocmibnations would change dpending
on other car prefercens but really they dont(they come in order...)
you jsut have to look at the eariler cars in the que and form that
really jsut calcuate the number of possibilites of tht shit
then simply count em up until u get to the index the input asked for
(u start with early cars so the number are large so it does it qucikly no maatter wht)
***Very similar to the integer string from 2024 Q1...

*/
