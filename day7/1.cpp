#include <bits/stdc++.h>
using namespace std;

bool check_valid(uint64_t ans , vector<uint64_t> nums)
{
    queue<uint64_t> possible_values;
    possible_values.push(0);

    for(int i =0;i<nums.size();i++)
    {
        int curr_size = possible_values.size();
        for(int j = 0; j <curr_size;j++)
        {
            uint64_t currval = possible_values.front();
            possible_values.pop();
            if(currval > ans)
                continue;
            uint64_t added = currval + nums[i];
            uint64_t multiplied = currval * nums[i];

            if (added <= ans) possible_values.push(added);
            if (multiplied <= ans) possible_values.push(multiplied);
        }
    }
    

    while(!possible_values.empty())
    {
        uint64_t currvalue = possible_values.front();
        possible_values.pop();
        if(currvalue == ans)
            return true;
    }

    return false;
}
int main() {
    ifstream file("indata.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    string line;
    long long count = 0;

    while (getline(file, line)) {
        vector<uint64_t> nums;
        uint64_t ans = 0;
        bool flag = true;
        string numstring = "";

        for (char x : line) {
            if (x != ':' && x != ' ') {
                numstring += x;
            } else if (x == ':' && flag) {
                ans = stoll(numstring); 
                flag = false;
                numstring = "";
            } else if (!flag && x == ' ') {
                if (!numstring.empty()) {
                    nums.push_back(stoi(numstring)); 
                    numstring = "";
                }
            }
        }

        if (!numstring.empty()) {
            nums.push_back(stoull(numstring));
        }

        if(check_valid(ans, nums))
            count+=ans;
    }

    file.close();

    cout << count;
    return 0;
}
