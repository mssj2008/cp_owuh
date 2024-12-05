#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define  inrange(x) ((x)>=0 && (x)<=7)
#define cinrange(x) (inrage((x).first) && inrange((x).second))


vector<string> board;
vector<string> sim;
char turn = '0';
pair<int,int> pvect[8] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};

//valid move
bool has_neighbours(int x,int y)
{
    if(x < 7 && board[x+1][y] != '.')
        return true;
    if(x > 0 && board[x-1][y] != '.')
        return true;
    if(y < 7 && board[x][y+1] != '.')
        return true;
    if(y > 0 && board[x][y-1] != '.')
        return true;
    if(x > 0 && y > 0 && board[x-1][y-1] != '.')
        return true;
    if(x > 0 && y < 7 && board[x-1][y+1] != '.')
        return true;
    if(x < 7 && y > 0 && board[x+1][y-1] != '.')
        return true;
    if(x < 7 && y < 7 && board[x+1][y+1] != '.')
        return true;
    return false;
}

// place a piece
void place(int x, int y,vector<string> &b = board)
{
    x--;
    y = 8 - y;
    if(b[y][x] == '.' && has_neighbours(x,y)) // if empty
        b[y][x] = turn;
}
// return the score gained by a move
// apply a move
int apply(int x,int y, vector<string> &b = board)
{
    int score = 0;
    x--;
    y = 8 - y;
    for(auto v : pvect)
    {
        pair<int,int> cord = {x+v.first,y+v.second};
        cout << v.first << " " << v.second << " " << cord.first << " " << cord.second << " " << b[cord.first][cord.second] << "\n";
        if(!(inrange(cord.second) && inrange(cord.second)))
            continue;
        if(b[cord.first][cord.second] == turn)
            continue;
        while(inrange(cord.second) && inrange(cord.second))
        {
            cout << ".";
            if(b[cord.first][cord.second] == '.')
                break;
            if(b[cord.first][cord.second] == turn)
            {
                cord.first -= v.first;
                cord.second -= v.second;
                cout << "x";
                while(!(cord.first == x && cord.second == y))
                {
                    cout << ".";
                    b[cord.first][cord.second] = turn;
                    cord.first -= v.first;
                    cord.second -= v.second;
                    score++;
                }
                break;
            }
            cord.first += v.first;
            cord.second += v.second;
        }
        cout << "\n";
    }
    return score;
}
// diplay board
void display_board()
{
    for(int i = 0; i < 8; i++)
    {
        cout << board[i] << "\n";
    }
}

void btos()
{
    for(int i = 0; i < 8; i++)
    {
        sim[i] = board[i];
    }
}
void stob()
{
    for(int i = 0; i < 8; i++)
    {
        board[i] = sim[i];
    }
}

void solve()
{

}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    /*int tt;
    cin >> tt;
    while(tt--)
        solve();*/
    for(int i = 0; i < 8; i++)
    {
        board.push_back("........");
        sim.push_back("........");
    }
    for(int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;
        board[i+2] = ".." + s + "..";
    }
    cout << "\n";
    display_board();
    int cmd;
    cin >> cmd;
    while(cmd != -1)
    {
        if(cmd == 0)
        {
            int x,y;
            cin >> x >> y;
            place(x,y);
            btos();
            cout << apply(x,y) << "\n";
            stob();
            display_board();
        }
        else
        {
            
        }
        cin >> cmd;
    }
    solve();
    return 0;
}