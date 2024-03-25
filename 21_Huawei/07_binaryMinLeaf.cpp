#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

// node's leaf leaf in 2N, right leaf in 2N+1
// output the path from min leaf to parent ... root
void minLeaf(vector<int> &treenodes) {
    // find the min
    vector<int> res;
    int min = INT_MAX, index = 0;
    for (int i = 0; i < treenodes.size(); i++) {
        if (treenodes[i] > 0 && treenodes[i] < min) {
            min = treenodes[i];
            index = i + 1;
        }
    }
    res.push_back(treenodes[index - 1]);
    while (index > 1) {
        // back find its parent node
        int nodeVal = treenodes[index / 2 - 1];
        if (nodeVal > 0) res.push_back(nodeVal);
        index /= 2;
    }
    reverse(res.begin(), res.end());
    for (auto ele: res) cout << ele << " " << endl;
}

int main() {
    string line;
    std::getline(cin, line);

    vector<int> numbers;
    string num;
    std::istringstream iss(line);
    while (iss >> num) {
        numbers.push_back(stoi(num));
    }
    minLeaf(numbers);
    return 0;
}