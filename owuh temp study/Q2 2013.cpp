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

vector<coord> p1p;
vector<coord> p2p;
vector<int> p1o;
vector<int> p2o;
int o1 = 0,o2 = 0;
coord neutron = {3,3};
int turn = 1;
int win = 0;
vector<coord> mdir = {{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};


string board[5] = {
    ".....",
    ".....",
    ".....",
    ".....",
    "....."
};

void update_board()
{
    for(int i = 0; i < 5; i++)
    {
        board[i]= ".....";
    }
    for(auto s : p1p)
    {
        board[s.y-1][s.x-1] = 'F';
    }
    for(auto s : p2p)
    {
        board[s.y-1][s.x-1] = 'S';
    }
    board[neutron.y-1][neutron.x-1] = '*';
}

void dispb()
{
    for(int i = 0; i < 5; i++)
        cout << board[i] << endl;
}

coord can_m(coord start,coord dir)
{
    while(board[start.y+dir.y-1][start.x+dir.x-1] == '.')
        start = {start.x+dir.x,start.y+dir.y};
    return start;
}

bool is_stuck(coord piece)
{
    for(auto c : mdir)
        if(can_m(piece,c) != piece)
            return false;

    return true;
}

void firstm(coord &piece)
{
    for(auto c : mdir)
    {
        if(can_m(piece,c) != piece)
        {
            piece = can_m(piece,c);
            return;
        }
    }
}

void move()
{
    // self win move
    if(turn == 1)
    {
        if(can_m(neutron,mdir[7]).x == 1)
        {
            win = 1;
            neutron = can_m(neutron,mdir[7]);
            update_board();
            return;
        }
        if(can_m(neutron,mdir[0]).x == 1)
        {
            win = 1;
            neutron = can_m(neutron,mdir[0]);
            update_board();
            return;
        }
        if(can_m(neutron,mdir[1]).x == 1)
        {
            win = 1;
            neutron = can_m(neutron,mdir[1]);
            update_board();
            return;
        }
    }
    else
    {
        if(can_m(neutron,mdir[5]).x == 5)
        {
            win = 2;
            neutron = can_m(neutron,mdir[5]);
            update_board();
            return;
        }
        if(can_m(neutron,mdir[4]).x == 5)
        {
            win = 2;
            neutron = can_m(neutron,mdir[4]);
            update_board();
            return;
        }
        if(can_m(neutron,mdir[3]).x == 5)
        {
            win = 2;
            neutron = can_m(neutron,mdir[3]);
            update_board();
            return;
        }
    }
    // only oppon ent win
    vector<coord> mvs;
    for(auto c : mdir)
        if(can_m(neutron,c) != neutron)
            mvs.push_back(can_m(neutron,c));
    int f = 0;
    if(turn == 1)
    {
        if(mvs.size() == 0)
        {
            win = 2;
            return;
        }
        for(auto c : mvs)
        {
            if(c.y != 5)
                f = 1;
        }
        if(f == 0)
        {
            win = 2;
            neutron = mvs[0];
            update_board();
            return;
        }
    }
    else
    {
        if(mvs.size() == 0)
        {
            win = 1;
            return;
        }
        for(auto c : mvs)
        {
            if(c.y != 1)
                f = 1;
        }
        if(f == 0)
        {
            win = 1;
            neutron = mvs[0];
            update_board();
            return;
        }
    }
    // normal move
    coord prevn = neutron;
    f = 0;
    if(turn == 1)
    {
    for(auto c : mdir)
    {
        neutron = can_m(neutron,c);
        update_board();
        if(is_stuck(p1p[p1o[o1%5]]))
        {
            neutron = prevn;
            update_board();
            continue;
        }
        firstm(p1p[p1o[o1%5]]);
        update_board();
        f = 1;
        break;
    }
    }
    else
    {
    for(auto c : mdir)
    {
        neutron = can_m(neutron,c);
        update_board();
        if(is_stuck(p2p[p2o[o2%5]]))
        {
            neutron = prevn;
            update_board();
            continue;
        }
        firstm(p2p[p2o[o2%5]]);
        update_board();
        f = 1;
        break;
    }
    }
    if(f == 0)
    {
        if(turn == 1)
        {
            win = 2;
            return;
        }
        else
        {
            win = 2;
            return;
        }
    }
    if(turn == 1)
    {
        o1++;
    }
    else
    {
        o2++;
    }
}

void game()
{
    while(neutron.y > 1 && neutron.y < 5 && win == 0)
    {
    move();
    if(turn == 1)
        turn = 2;
    else
        turn = 1;
    }
    dispb();
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //Main Prog
    for(int i = 0; i < 5; i++)
    {
        int a; cin >> a;
        p1o.push_back(a-1);
        p1p.push_back({i+1,5});
    }
    for(int i = 0; i < 5; i++)
    {
        int a; cin >> a;
        p2o.push_back(a);
        p2p.push_back({i+1,1});
    }
    update_board();
    game();
    return 0;
}

