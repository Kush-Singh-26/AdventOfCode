#include<bits/stdc++.h>
using namespace std;

bool check_order(vector<pair<int,int>> &rules, vector<int> &line)
{
    bool valid = true;

    for(size_t i = 1;i<line.size(); i++)
    {
        auto prev = line[i-1];
        auto curr = line[i];
        bool found = false;

        for(auto& x : rules)
        {
            if(x.first == prev && x.second == curr)
            {
                found = true;
                break;
            }
        }

        if(!found)
        {
            valid = false;
            break;
        }
    }
    return valid;
}

vector<int> fix_update(vector<pair<int, int>> &rules, vector<int> &line) {
    vector<int> cpystr = line;
    bool swapped;

    do {
        swapped = false;
        for (size_t i = 1; i < cpystr.size(); i++) {
            auto prev = cpystr[i - 1];
            auto curr = cpystr[i];

            for (auto &rule : rules) {
                if (rule.second == prev && rule.first == curr) {
                    cpystr[i] = prev;
                    cpystr[i - 1] = curr;
                    swapped = true;
                    break;
                }
            }
        }
    } while (swapped); 

    return cpystr;
}


int main()
{
    ifstream file("indata.txt");
    vector<pair<int,int>> rules;
    vector<vector<int>> updates;

    string line;

    while(getline(file, line))
    {
        if(line.size() == 0)
            break;
        string left, right;
        bool is_left = true;
        for(size_t i = 0; i<line.size();i++)
        {
            if(line[i] == '|')
            {
                is_left = false;
                i++;
            }
            if(is_left)
                left.push_back(line[i]);
            if(!is_left)
                right.push_back(line[i]);
        }
        rules.push_back(pair<int,int>{stoi(left), stoi(right)});
    }

    while(getline(file,line))
    {
        vector<int> temp;
        string tempstr;
        for(size_t i = 0;i<line.size();i++)
        {
            if(line[i] == ',')
            {
                temp.push_back(stoi(tempstr));
                tempstr = "";
                continue;
            }
            tempstr += line[i];
        }
        temp.push_back(stoi(tempstr));
        updates.push_back(temp);
    }

    file.close();

    long long sum = 0;
    for(auto &x : updates)
    {
        bool valid = check_order(rules,x);
        if(!valid)
        {
            auto fixed_update = fix_update(rules,x);
            long long mid = floor(fixed_update.size()/2);
            sum += fixed_update[mid];
        }
    }

    cout << sum;
    
}