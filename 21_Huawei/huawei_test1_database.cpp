#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>  // double queue -> <-
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

// before call here s get by getline, getline(cin, ss);
vector<int> splitstr(string s, char deli) {
    //vector<string> tokens;
    vector<int> tokens;
    std::stringstream tokenStream(s);
    //std::istringstream tokenStream(s);
    string token;
    while (std::getline(tokenStream, token, deli)) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}

vector<string> splitstr1(string s, char deli) {
    vector<string> tokens;
    std::stringstream tokenStream(s);
    //std::istringstream tokenStream(s);
    string token;
    while (std::getline(tokenStream, token, deli)) {
        tokens.push_back(token);
    }
    return tokens;
}



//naive binary search
int binarySearch_basic(vector<pair<int,string>>& nums, int target) {
    if (nums.size() == 0) return -1;
    long int start = 0, end = nums.size() - 1, mid = 0;
    while (start <= end) {
        mid = start + ((end - start) >> 1);
        if (nums[mid].first == target) return mid;
        else if (nums[mid].first > target) {
            end = mid - 1;
        }
        else start = mid + 1;
    }
    return -1;
}

int main()
{
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    int cursize;
    cin >> cursize;
    int i = 0;
    vector<pair<int,string>> curTable;
    unordered_map<int, string> bakTable;
    int neid;
    string nename;
    int neflag;
    while(i < cursize) {
        cin >> neid >> nename >> neflag;
        curTable.push_back(make_pair(neid, nename+to_string(neflag)));
        i++;
    }
    int baksize;
    cin >> baksize;
    int j = 0;
    while(j < baksize) {
        cin >> neid >> nename;
        bakTable[neid] = nename;
        j++;
    }

    // sort curTable by neid
    sort(curTable.begin(), curTable.end(), [](pair<int,string>& a, pair<int,string>& b){
        return a.first < b.first;
    });
    //for (auto ele : curTable) cout << ele.first << " " << ele.second << " ";
    for(auto& [k,v] : bakTable) {
        int idx = binarySearch_basic(curTable, k);
        if (idx == -1) {
            curTable.push_back(make_pair(k, v + " " + "0")); 
        } else {
            char now_neflag = curTable[idx].second[curTable[idx].second.size() - 1];
            curTable[idx].second = v + " " + now_neflag;
        }
    }
    for (auto ele : curTable) {
        cout << ele.first << " " << ele.second << " ";
    }
    return 0;
}

// no insert, not right update
// 4
// 256 NE256 1
// 290 NE290 0
// 268 26800000 1
// 257 NE257 1
// 3
// 273 NE273
// 268 NE268
// 257 NE257

// 256 NE256 1
// 257 NE257 1
// 268 NE268 1
// 273 NE273 0
// 290 NE290 0