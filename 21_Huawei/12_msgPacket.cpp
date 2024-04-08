#include "21_header.h"
using namespace std;

// 4
// D1 D2
// D2 D3
// D3 D2
// D2 D1
// true
bool msgPacket(vector<string>& packets) {
    // key is pair<D1,D2>, value is times
    unordered_map<string, int> mp;
    for (auto routes: packets) {
        if (!mp.count(routes)) {
            mp[routes] = 1;
        } else {
            mp[routes]++;
        }
    }
    unordered_map<string, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        string sub1 = (it->first).substr(0,2);
        string sub2 = (it->first).substr(3,2);
        string k = sub2 + "_" + sub1;
        if(it->second != mp[k]) return false;
    }
    return true;
}

int main() {
    int N, i = 0;
    cin >> N;
    vector<string> packets;
    while (i < N) {
        string s1, s2;
        cin >> s1 >> s2;
        string ele = s1 + "_" + s2;
        //cout << ele << endl;
        packets.push_back(ele);
        i++; 
    }
    if (msgPacket(packets)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}