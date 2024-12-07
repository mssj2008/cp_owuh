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

char hive[25][6];
pair<int,int> RDrone = {1,1};
pair<int,int> BDrone = {25,6};
int r,b;

int get_opposite_edge(int edge)
{
    switch (edge)
    {
    case 1:
        return 4;
    
    case 2:
        return 5;

    case 3:
        return 6;

    case 4:
        return 1;

    case 5:
        return 2;

    case 6:
        return 3;

    default:
        return -1;
    }
}

pair<int,int> get_adjacent_cell(pair<int,int> cell)
{
    if(cell.second == 2 && cell.first % 5 != 0)
        return {cell.first+1,get_opposite_edge(2)};
    else if(cell.second == 5 && cell.first % 5 != 1)
        return {cell.first-1,get_opposite_edge(5)};
    else if((((cell.first-1) / 5)+1) % 2 == 0) // even row
    {
        if(cell.second == 1 && cell.first%5 != 0)
            return {cell.first-5+1,get_opposite_edge(1)};
        if(cell.second == 6 && (cell.first-1)/5 != 0)
            return {cell.first-5,get_opposite_edge(6)};
        if(cell.second == 3 && cell.first % 5 != 0)
            return {cell.first+5+1,get_opposite_edge(3)};
        if(cell.second == 4 && (cell.first-1)/5 != 4)
            return {cell.first+5,get_opposite_edge(4)};
    }
    else
    {
        if(cell.second == 1 && (cell.first-1)/5 != 0 && (cell.first-1)/5 != 0)
            return {cell.first-5,get_opposite_edge(1)};
        if(cell.second == 6 && cell.first % 5 != 1 && (cell.first-1)/5 != 0)
            return {cell.first-5-1,get_opposite_edge(6)};
        if(cell.second == 3 && (cell.first-1)/5 != 4 && (cell.first-1)/5 != 4)
            return {cell.first+5,get_opposite_edge(3)};
        if(cell.second == 4 && cell.first % 5 != 1 && (cell.first-1)/5 != 4)
            return {cell.first+5-1,get_opposite_edge(4)};
    }
    return {-1,-1};
}

void init_hive()
{
    for(int i = 0; i < 25; i++)
        for(int j = 0; j < 6; j++)
        {
            hive[i][j] = ' ';
        }
}

void modify_edge(pair<int,int> cell,char val)
{
    if(cell.first == -1)
        return;
    hive[cell.first-1][cell.second-1] = val;
}

void skirmish()
{
    modify_edge(RDrone,'R');
    modify_edge(get_adjacent_cell(RDrone),'R');
    RDrone.second+=1;
    if(RDrone.second == 7)
        RDrone.second = 1;
    RDrone.first += r;
    if(RDrone.first > 25)
        RDrone.first -= 25;
    modify_edge(BDrone,'B');
    modify_edge(get_adjacent_cell(BDrone),'B');
    BDrone.second-=1;
    if(BDrone.second == 0)
        BDrone.second = 6;
    BDrone.first += b;
    if(BDrone.first > 25)
        BDrone.first -= 25;
}

pair<int,int> cell_stat(int cell)
{
    int rr = 0;
    int bb = 0;
    if(cell == -1)
        return {-1,-1};
    for(int i = 0; i < 6; i++)
    {
        if(hive[cell-1][i] == 'R')
        rr++;
        else if(hive[cell-1][i] == 'B')
        bb++;
    }
    return {rr,bb};
}

void feud()
{
    vector best_choice = {-1,-1,-1,-1}; // cell num , edge num , cells gained , cells taken
    // red
    for(int c = 1;  c< 26; c++)
    {
        for(int e = 1; e < 7; e++)
        {
            if(hive[c-1][e-1] != ' ')
                continue;
            pair<int,int> stat = cell_stat(c);
            pair<int,int> astat = cell_stat(get_adjacent_cell({c,e}).first);
            vector cur_choice = {c,e,0,0};
            if(stat.first == stat.second)
                cur_choice[2]++;
            else if(stat.first+1 == stat.second)
                cur_choice[3]++;
            if(astat.first!=-1)
            {
            if(astat.first == astat.second)
                cur_choice[2]++;
            else if(astat.first+1 == astat.second)
                cur_choice[3]++;
            }
            if(best_choice[2] > cur_choice[2])
                continue;
            if(best_choice[2] < cur_choice[2])
            {
                best_choice = cur_choice;
                continue;
            }
            if(best_choice[3] > cur_choice[3])
                continue;
            if(best_choice[3] < cur_choice[3])
            {
                best_choice = cur_choice;
                continue;
            }
        }
    }
    //cout << best_choice[0] << " " << best_choice[1] << endl;
    modify_edge({best_choice[0],best_choice[1]},'R');
    modify_edge(get_adjacent_cell({best_choice[0],best_choice[1]}),'R');
    // blue
    best_choice = {-1,-1,-1,-1};
    for(int c = 25;  c>=1; c--)
    {
        for(int e = 6; e >= 1; e--)
        {
            if(hive[c-1][e-1] != ' ')
                continue;
            pair<int,int> stat = cell_stat(c);
            pair<int,int> astat = cell_stat(get_adjacent_cell({c,e}).first);
            vector cur_choice = {c,e,0,0};
            if(stat.first == stat.second)
                cur_choice[2]++;
            else if(stat.first == stat.second+1)
                cur_choice[3]++;
            if(astat.first != -1)
            {
            if(astat.first == astat.second)
                cur_choice[2]++;
            else if(astat.first == astat.second+1)
                cur_choice[3]++;
            }
            if(best_choice[2] > cur_choice[2])
                continue;
            if(best_choice[2] < cur_choice[2])
            {
                best_choice = cur_choice;
                continue;
            }
            if(best_choice[3] > cur_choice[3])
                continue;
            if(best_choice[3] < cur_choice[3])
            {
                best_choice = cur_choice;
                continue;
            }
        }
    }
    //cout << best_choice[0] << " " << best_choice[1] << endl;
    modify_edge({best_choice[0],best_choice[1]},'B');
    modify_edge(get_adjacent_cell({best_choice[0],best_choice[1]}),'B');
}

pair<int,int> eval_hive()
{
    int rr=0;
    int bb=0;
    for(int i = 0; i < 25; i++)
    {
        pair<int,int> stat = cell_stat(i+1);
        //cout << stat.first << " " << stat.second << endl;
        if(stat.first > stat.second)
        rr++;
        else if(stat.first < stat.second)
        bb++;
    }
    return {rr,bb};
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    /*
    r = 9;
    b = 3;
    init_hive();
    for(int i = 0; i < 3; i++)
        skirmish();
    cout << hive[24][5] << endl;
    cout << hive[18][2] << endl;
    return 0;
    */
    cin >> r >> b;
    int s,f;
    cin >> s >> f;
    init_hive();
    for(int i = 0; i < s; i++)
    {
        skirmish();
    }
    //cout << hive[24][5] << hive[18][2] << endl;
    
    for(int i = 0; i < f; i++)
    {
        feud();
    }
    pair<int,int> scores = eval_hive();
    cout << scores.first << endl;
    cout << scores.second << endl;
    return 0;
}

/*

1hr 30
first 30 min was on mid night didnt rly count tht
but it waw technically done in lik 50 ish min if i didnt do gooofy shi
MAKE SURE WHENVER THERE IS DUPLCIATIOJN OF CODE AND THER IS
MODIFICATION EVEYR PART IS UUPDATED FFS
dont goof up < > and similar stuff as well :/


Extended mmph :/

*/