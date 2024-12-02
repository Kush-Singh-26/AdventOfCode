#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> list1;
    vector<int> list2;
    int temp1,temp2;
    while(cin >> temp1 >> temp2)
    {
        list1.push_back(temp1);
        list2.push_back(temp2);
    }
    unordered_map<int,int> mp;
    for(int x : list2)
    {
        mp[x]++;
    }

    int n = list1.size();
    int sum = 0;
    for(int i =0 ;i<n;i++)
    {
        int ele1 = list1[i];
        auto it = mp.find(ele1);
        if(it != mp.end())
        {
            int similarity_score = ele1 * (*it).second;
            sum += similarity_score;
        }
    }

    cout << sum << "\n";
}