#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define inrange(x) ((x)>=-25 && (x)<=25)
#define cinrange(x) (inrange((x).first) && inrange((x).second))
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

vector<string> F = {
    ".##",
    "##.",
    ".#."
};

vector<string> G = {
    "##.",
    ".##",
    ".#."
};

vector<string> I = {
    "#",
    "#",
    "#",
    "#",
    "#"
};

vector<string> L = {
    "#.",
    "#.",
    "#.",
    "##"
};

vector<string> J = {
    ".#",
    ".#",
    ".#",
    "##"
};

vector<string> N = {
    ".#",
    "##",
    "#.",
    "#."
};

vector<string> M = {
    "#.",
    "##",
    ".#",
    ".#"
};

vector<string> P = {
    "##",
    "##",
    "#."
};

vector<string> Q = {
    "##",
    "##",
    ".#"
};

vector<string> T = {
    "###",
    ".#.",
    ".#."
};

vector<string> U = {
    "#.#",
    "###"
};

vector<string> V = {
    "#..",
    "#..",
    "###"
};

vector<string> W = {
    "#..",
    "##.",
    ".##"
};

vector<string> X = {
    ".#.",
    "###",
    ".#."
};

vector<string> Z = {
    "##.",
    ".#.",
    ".##"
};

vector<string> S = {
    ".##",
    ".#.",
    "##."
};

vector<string> Y = {
    ".#",
    "##",
    ".#",
    ".#"
};

vector<string> A = {
    "#.",
    "##",
    "#.",
    "#."
};

vector<string> select_shape(char c)
{
    switch(c)
    {
        case 'F':
            return F;
            break;

        case 'G':
            return G;
            break;

        case 'I':
            return I;
            break;

        case 'L':
            return L;
            break;

        case 'J':
            return J;
            break;

        case 'N':
            return N;
            break;

        case 'M':
            return M;
            break;

        case 'P':
            return P;
            break;

        case 'Q':
            return Q;
            break;

        case 'T':
            return T;
            break;

        case 'U':
            return U;
            break;

        case 'V':
            return V;
            break;

        case 'W':
            return W;
            break;

        case 'X':
            return X;
            break;

        case 'Z':
            return Z;
            break;

        case 'S':
            return S;
            break;

        case 'Y':
            return Y;
            break;

        case 'A':
            return A;
            break;
    }
    return A;
}

bool is_adj(set<coord> &sac,vector<string> &SB,coord bc)
{
    for(int i = 0; i < SB.size(); i++)
    {
        for(int j = 0; j < SB[i].length(); j++)
        {
            if(SB[i][j] == '.') continue;
            if(sac.count({bc.x+j+1,bc.y-i}) != 0)
                return true;
            if(sac.count({bc.x+j-1,bc.y-i}) != 0)
                return true;
            if(sac.count({bc.x+j,bc.y-i+1}) != 0)
                return true;
            if(sac.count({bc.x+j,bc.y-i-1}) != 0)
                return true;
        }
    }
    return false;
}

//char fetch_pt()

vector<string> cons_s(set<coord> &sac,vector<string> &SB,coord bc)
{
    set<coord> sbc;
    int maxx=-1000,maxy=-1000,minx=1000,miny=1000;
    for(int i = 0; i < SB.size(); i++)
    {
        for(int j = 0; j < SB[i].length(); j++)
        {
            if(SB[i][j] != '.')
                sbc.insert({bc.x+j,bc.y-i});
        }
    }
    //cout << sac.size() << endl; 
    cout << bc.x << " " << bc.y << endl;
    cout << endl;
    for(auto s : sac)
    {
        cout << s.x << " " << s.y << endl;
        if(s.x < minx)
            minx = s.x;
        if(s.x > maxx)
            maxx = s.x;
        if(s.y < miny)
            miny = s.y;
        if(s.y > maxy)
            maxy = s.y;
    }
    cout << endl;
    for(auto s : sbc)
    {
        cout << s.x << " " << s.y << endl;
        if(s.x < minx)
            minx = s.x;
        if(s.x > maxx)
            maxx = s.x;
        if(s.y < miny)
            miny = s.y;
        if(s.y > maxy)
            maxy = s.y;
    }
    cout << endl;
    cout << maxx << endl; 
    cout << minx << endl; 
    cout << maxy << endl; 
    cout << miny << endl; 

    vector<string> shape;
    for(int i = 0; i < maxy-miny+1; i++)
    {
        shape.push_back("");
        for(int j = 0; j < maxx-minx+1; j++)
        {
            coord c = {j+minx,maxy-i};
            if(sbc.count(c) != 0 || sac.count(c) != 0)
            {
                shape[i]+='#';
            }
            else
            {
                shape[i] += '.';
            }
        }
    }
    return shape;
}
//vector<string> 
vector<string> c_shape(vector<string> &SA,vector<string> &SB,coord bc,coord dir)
{
    set<coord> sac;
    for(int i = 0; i < SA.size(); i++)
    {
        for(int j = 0; j < SA[i].length(); j++)
        {
            if(SA[i][j] != '.')
                sac.insert({j,-i});
        }
    }
    //cout << sac.size() << endl; 
    while(cinrange(bc))
    {
        if(is_adj(sac,SB,bc))
        {
            return cons_s(sac,SB,bc);
        }
        bc.x += dir.x;
        bc.y += dir.y;
    }
    return SA;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //Main Prog
    /*
    if(c_shape(F,F,{20,0},{-1,0}) == true)
    {
        cout << "mmph" << endl;
    }
    else
    {
        cout << "no mmph" << endl;
    }
    */
    
    vector<string> sh = c_shape(P,T,{-20,0},{1,0});
    for(auto s : sh)
    {
        cout << s << endl;
    }
    
    return 0;
}

