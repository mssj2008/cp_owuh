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

enum tdir
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum et
{
    H,
    P,
    N
};

struct Edge
{
    
}

bool is_up(coord c)
{
    return c.x % 2 == c.y % 2;
}


int move(map<coord,int> &t,coord &p,int mt,int pn)
{

}


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    // Main Prog
    int p,m;
    map<coord,int> triangles;
    coord top_left = {0,0};
    triangles[{0,0}] = 5;
    vector<coord> players;
    vector<tdir> pdir;
    vector<int> pmt;
    vector<int> score;
    cin >> p >> m;
    for(int i = 0; i < p; i++)
    {
        int mt;
        cin >> mt;
        players.pb({-1,0},{0,0});
        pdir.pb(RIGHT);
        pmt.pb(mt);
        score.pb(0);
    }
    for(int i = 0; i < m; i++)
    {
        score[i%p] += move(triangles,players[i%p],pmt[i%p],(i%p)+1);
    }
    return 0;
}

