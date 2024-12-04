#include<bits/stdc++.h>
using namespace std;

int count_xmas(int i,int j, int n, vector<string> &grid)
{
    int count = 0;

    if(((grid[i-1][j+1] == 'M' && grid[i+1][j-1] == 'S') || (grid[i-1][j+1] == 'S' && grid[i+1][j-1] == 'M')) &&
    ((grid[i+1][j+1] == 'M' && grid[i-1][j-1] == 'S') || (grid[i+1][j+1] == 'S' && grid[i-1][j-1] == 'M')))
        count++;
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
    for(int i =1;i<n-1;i++)
    {
        for(int j = 1;j<n-1;j++)
        {
            if(grid[i][j] == 'A')
                total += count_xmas(i,j,n,grid);
        }
    }

    cout << total << "\n";
}

