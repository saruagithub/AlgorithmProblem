#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

vector<int> nodup(vector<int> numbers) {
    vector<int> res;
    unordered_map<int, int> times; // key = num, ele = times
    for (int i = 0; i < numbers.size(); i++) {
        if (!times.count(numbers[i])) times[numbers[i]] = 1;
        else times[numbers[i]]++;
    }
    // sort vector
    sort(numbers.begin(), numbers.end(), [&times](int& n1, int& n2){
        return times[n1] > times[n2];
    });
    // remove dup ele
    res.push_back(numbers[0]);
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] != res.back()) res.push_back(numbers[i]);
    }

    // for (unordered_map<int,int>::iterator it = times.begin(); it != times.end(); it++) {
    //     cout << it->first << " ";
    // }
    // for (auto& ele: times) cout << ele.first << " ";
    for (auto num : res) {
        cout << num << " " << endl;
    }
    return res;
}

int main() {
    vector<int> test = {1,1,1,2,2,2,2,4,3};
    nodup(test);
    return 0;
}