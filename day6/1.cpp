#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<string> grid;
    ifstream file("indata.txt");
    string line;
    int xcor, ycor;
    int row = 0;

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    while (getline(file, line)) {
        int col = 0;
        for (char x : line) {
            if (x == '^') {
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

    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    char direc = 'u';

    while (true) {
        if (xcor < 0 || ycor < 0 || xcor >= n || ycor >= m) {
            break;
        }

        if (grid[xcor][ycor] == '.') {
            grid[xcor][ycor] = 'X'; 
            count++;
        }

        switch (direc) {
            case 'u':
                if (xcor > 0 && grid[xcor - 1][ycor] == '#') {
                    direc = 'r';
                } else {
                    xcor--;
                }
                break;
            case 'r':
                if (ycor < m - 1 && grid[xcor][ycor + 1] == '#') {
                    direc = 'd';
                } else {
                    ycor++;
                }
                break;
            case 'd':
                if (xcor < n - 1 && grid[xcor + 1][ycor] == '#') {
                    direc = 'l';
                } else {
                    xcor++;
                }
                break;
            case 'l':
                if (ycor > 0 && grid[xcor][ycor - 1] == '#') {
                    direc = 'u';
                } else {
                    ycor--;
                }
                break;
        }
    }

    cout << count << endl;
    return 0;
}