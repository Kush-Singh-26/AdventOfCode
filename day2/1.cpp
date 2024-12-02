#include<bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;
    string line;
    while(getline(cin, line))
    {
        if(line.empty())
            break;
        vector<int> numline;
        istringstream iss(line);
        int number;
        while(iss >> number)
            numline.push_back(number);
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
                count++;       
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
                count++;       
            }
        }
    }

    cout << count;


    return 0;
}