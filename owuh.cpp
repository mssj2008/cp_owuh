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

string parse_state(vector<string> &ps)
{
    return ps[0] + " " + ps[1] + " " + ps[2] + " " + ps[3];
}

vector<string> get_state(string &ps)
{
    stringstream ss(ps);
    vector<string> ans;
    string s;
    while(ss >> s)
        ans.push_back(s);
    return ans;
}

void move(vector<string> &ps, int take,int put)
{
    if(ps[put] == "0")
        ps[put].pop_back();
    ps[put].push_back(ps[take].back());
    ps[take].pop_back();
    if(ps[take].length() == 0)
        ps[take].push_back('0');
}

int main()
{
    vector<string> pegs(4);
    vector<string> target(4);
    vector<string> pegstmp(4);
    unordered_set<string> visited;
    //string s = "12";
    //s.push_back('3');
    //cout << s << endl;
    //return 0;
    //vector<vector<int>> moves = {{}}
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //Main Prg
    cin >> pegs[0] >> pegs[1] >> pegs[2] >> pegs[3];
    //string target;
    // cin >> target;
    cin >> target[0] >> target[1] >> target[2] >> target[3];
    visited.insert(parse_state(pegs));
    queue<vector<string>> bfs;
    queue<int> bfsmvs;
    bfs.push(pegs);
    bfsmvs.push(0);
    //cout << bfs.front()[0] << endl;
    while(!bfs.empty())
    {
        pegs = bfs.front();
        pegstmp = pegs;
        bfs.pop();
        int mv = bfsmvs.front()+1;
        bfsmvs.pop();
        for(int take = 0; take < 4; take++)
        {
            for(int put = 0; put < 4; put++)
            {   
                
                if(put == take)
                    continue;
                if(pegs[take] == "0")
                    continue;
                if(pegs[put].length() >= 4)
                    continue;
                //cout << "i wanna peg haveen" << endl;
                pegstmp = pegs;
                move(pegstmp,take,put);
                //cout << parse_state(pegstmp) << endl;
                if(visited.count(parse_state(pegstmp)) != 0)
                    continue;
                if(target == pegstmp)
                {
                    cout << mv << endl;
                    exit(0);
                }
                //pegs = pegstmp;
                visited.insert(parse_state(pegstmp));
                bfs.push(pegstmp);
                bfsmvs.push(mv);
            }
        }
    }
    
    return 0;
}

