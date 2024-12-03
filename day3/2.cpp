#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file("indata.txt");

    if (!file.is_open()) {
        cout << "Error: Could not open file input.txt\n";
        return 1;
    }

    string str((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    int n = str.size();
    int i = 0;
    long long sum = 0;
    int enabled = 1;

    while (i < n)
    {
        size_t pos = str.find("do()",i);
        if(pos != string::npos && pos == i)
        {
            i += 4;
            enabled = 1;
            continue;
        }

        pos = str.find("don't()",i);
        if(pos != string::npos && pos == i)
        {
            i += 7;
            enabled = 0;
            continue;
        }

        pos = str.find("mul(",i);
        if(pos != string::npos && pos == i)
        {
            i += 4;  

            int a = 0, b = 0;

            while (i < n && isdigit(str[i]))
            {
                a = a * 10 + (str[i] - '0');
                i++;
            }

            if (i < n && str[i] == ',') i++;  

            while (i < n && isdigit(str[i]))
            {
                b = b * 10 + (str[i] - '0');
                i++;
            }

            if (i < n && str[i] == ')')  
            {
                sum += (long long)a * b * enabled;
                i++;
            }

            continue;

        }
        i++;
       
    }

    cout << sum << "\n";
    return 0;
}
