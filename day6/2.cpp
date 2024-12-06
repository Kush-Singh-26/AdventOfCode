#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> grid;
    ifstream file("indata.txt");
    string line;
    int xcor, ycor;
    int row = 0;

    if (!file.is_open())
    {
        cerr << "Error opening file" << endl;
        return 1;
    }

    while (getline(file, line))
    {
        int col = 0;
        for (char x : line)
        {
            if (x == '^')
            {
                xcor = row;
                ycor = col;
            }
            col++;
        }
        row++;
        grid.push_back(line);
    }

    file.close();

    grid[xcor][ycor] = '.';
    int x = xcor, y = ycor;

    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    char direc = 'u';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == x && j == y)
                continue;

            if (grid[i][j] != '.')
                continue;

            vector<string> modified_grid = grid;
            modified_grid[i][j] = '#';
            
            int cx = x, cy = y;
            int wctr = 0;
            direc = 'u';

            while (cx >= 0 && cy >= 0 && cx < n && cy < m)
            {
                switch (direc)
                {
                case 'u':
                    if (cx > 0 && modified_grid[cx - 1][cy] == '#')
                        direc = 'r';
                    else
                        cx--;
                    break;
                case 'r':
                    if (cy < m - 1 && modified_grid[cx][cy + 1] == '#')
                        direc = 'd';
                    else
                        cy++;
                    break;
                case 'd':
                    if (cx < n - 1 && modified_grid[cx + 1][cy] == '#')
                        direc = 'l';
                    else
                        cx++;
                    break;
                case 'l':
                    if (cy > 0 && modified_grid[cx][cy - 1] == '#')
                        direc = 'u';
                    else
                        cy--;
                    break;
                }

                if (++wctr > 10000) {
                    count++;
                    break;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}