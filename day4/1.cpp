#include<bits/stdc++.h>
using namespace std;

// directions include all 8 possible directions in which the sequece has to be searched
vector<pair<int,int>> directions=
    {
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
        {0,-1},
        {-1,-1},
        {-1,0},
        {-1,1}
    };

int count_xmas(int i,int j, int n, vector<string> grid)
{
    int count = 0;
    //check if the current index can be used to start , i.e, if legth 
    //of 3 in any dorection will be in range (n).
    for(pair<int,int> move :directions)
    {
        if(i + move.first*3 >= n || j + move.second*3 >= n ||  i + move.first*3 <0 || j + move.second*3 <0 ) 
           continue;
        string str = "MAS";
        string checkstr;
        for(int k =1; k<=3; k++)
        {
            checkstr += grid[i + move.first * k][j + move.second * k];
        }   
        if(str == checkstr)
            count++;
    }

    return count;
}

int main()
{
    ifstream file("indata.txt");

    if(!file.is_open())
    {
        cout << "File not opened\n";
        return 1;
    }

    vector<string> grid;
    string line;
    while(getline(file,line))
    grid.push_back(line);
    file.close();
    
    int total = 0;
    int n = grid.size();
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(grid[i][j] == 'X')
                total += count_xmas(i,j,n,grid);
        }
    }

    cout << total << "\n";
}

