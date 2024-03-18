#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int ipv4(string ip) {
    vector<int> nums;
    int res = 0;
    int lastIndex = 0;
    string sub;
    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] == '#') {
            sub = ip.substr(lastIndex, i - lastIndex);
            nums.push_back(stoi(sub));
            lastIndex = i + 1;
        }
    }
    sub = ip.substr(lastIndex, ip.size() - lastIndex);
    nums.push_back(stoi(sub));

    for (int i = 0; i < nums.size(); i++) {
        if (i == 0 && (nums[i] < 1 || nums[i] > 128)) {
            cout << "Invalid IP" << endl;
            return -1;
        }
        else if (i > 0 && (nums[i] < 0 || nums[i] > 255)) {
            cout << "Invalid IP" << endl;
            return -1;
        }
        // bit num left move
        res += nums[i] << (8 * (3 - i));
    }
    return res;
}

void splitstr(string s, char deli) {
    vector<string> tokens;
    std::stringstream tokenStream(s);
    //std::istringstream tokenStream(s);
    string token;

    while (std::getline(tokenStream, token, deli)) {
        tokens.push_back(token);
    }
    for (auto ele: tokens) cout << ele << "," << endl;
}

int main() {
    string temp;
    cin >> temp;
    splitstr(temp,'#');
    cout << ipv4(temp) << endl;
    return 0;
}