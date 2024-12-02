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

    sort(list1.begin(),list1.end());
    sort(list2.begin(),list2.end());

    int n = list1.size();
    int sum = 0;
    for(int i =0 ;i<n;i++)
    {
        int ele1 = list1[i], ele2 = list2[i];
        int diff = abs(ele1 - ele2);
        sum += diff;
    }

    cout << sum << "\n";
}