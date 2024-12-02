#include <bits/stdc++.h>
using namespace std;

int check(vector<int> numline);
int check2(vector<int> numline);

int main()
{
    int count = 0;
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            break;
        vector<int> numline;
        istringstream iss(line);
        int number;
        while (iss >> number)
            numline.push_back(number);
        count += check(numline);
    }

    cout << count;

    return 0;
}

int check(vector<int> numline)
{
    if(check2(numline))
        return 1;
    
    else
    {
        for(int i =0;i<numline.size();i++)
        {
            vector<int> temp = numline;
            temp.erase(temp.begin()+i);

            if(check2(temp))
                return 1;
        }
    }

    return 0;
}


int check2(vector<int> numline)
{
    if(numline[0] < numline[1])
        {
            int flag = 0;
            for(int i =1;i<numline.size();i++)
            {
                if(numline[i] <= numline[i-1] || (numline[i] - numline[i-1] >3) || numline[i] - numline[i-1] <1)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                return 1;       
            }
        }
        else
        {
            int flag = 0;
            for(int i =1;i<numline.size();i++)
            {
                if(numline[i] >= numline[i-1] || (numline[i-1] - numline[i] >3) || numline[i-1] - numline[i] < 1)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                return 1;       
            }
        }

        return 0;    
}