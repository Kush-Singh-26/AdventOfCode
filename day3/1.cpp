#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file("indata.txt"); 

    if (!file.is_open()) {
    cout << "Error: Could not open file indata.txt\n";
    return 1;
}


    string str((istreambuf_iterator<char>(file)), 
                    istreambuf_iterator<char>());

    file.close();
    int n = str.size();
    int i = 0;
    long long sum = 0;
    while(i < n)
    {
        i = str.find("mul(", i);
        if (i == string::npos) break;
        
        i += 4;
        
        int a = 0;
        while(i < n && isdigit(str[i]))
        {
            a = a * 10 + (str[i] - '0');
            i++;
        }
        
        if(i < n && str[i] == ',')
            i++;
        
        int b = 0;
        while(i < n && isdigit(str[i]))
        {
            b = b * 10 + (str[i] - '0');
            i++;
        }
        
        if(i < n && str[i] == ')')
        {
            sum += (long long)a * b;
        }
        
        i++;
    }

    cout << sum << "\n";
    return 0;
}