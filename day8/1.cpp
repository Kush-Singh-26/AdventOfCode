#include <bits/stdc++.h>
using namespace std;

bool is_valid(int nx, int ny, vector<string>& grid)
{
    return(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size());
}

int count_antennas(vector<string> &grid, unordered_map<char, vector<pair<int,int>>> & mp)
{
    int ans = 0;
    for(auto &x : mp)
    {
        for(int i = 0;i<x.second.size();i++)
        {
            for(int j  = i+1;j<x.second.size();j++)
            {
                int dx = x.second[j].first - x.second[i].first;
                int dy = x.second[j].second - x.second[i].second;

                int nx = x.second[i].first - dx;
                int ny = x.second[i].second -dy;
                if(is_valid(nx,ny,grid) && grid[nx][ny] != '#')
                {
                    ans++;
                    grid[nx][ny] = '#';
                }

                nx = x.second[j].first + dx;
                ny = x.second[j].second + dy;
                if(is_valid(nx,ny,grid) && grid[nx][ny] != '#')
                {
                    ans++;
                    grid[nx][ny] = '#';
                }


            }
        }
    }

    return ans;
}

int main() {
    ifstream file("indata.txt");
    if (!file) {
        cerr << "Error: Unable to open file.\n";
        return 1;
    }

    string line;
    vector<string> grid;
    unordered_map<char, vector<pair<int, int>>> mp; 
    int row = 0;

    while (getline(file, line)) {
        grid.push_back(line);
        int col = 0;
        for (char x : line) {
            if (x != '.') {
                mp[x].push_back({row, col});
            }
            col++;
        }
        row++;
    }

    file.close();

    
    cout << count_antennas(grid,mp);

    

    return 0;
}
