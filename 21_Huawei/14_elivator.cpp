#include "21_header.h"
#include <numeric>

vector<int> addnumlist;
int m; // 加法数集合的数字个数
int target, len;

int getAddNum(vector<int>& ops, int curSum) {
    if (addnumlist.size() == m && curSum <= target) {
        return curSum;
    }
    int addSum = 0;
    vector<int> tempaddnumlist;
    vector<int> copytemplist;
    for (int i = 0; i < ops.size(); i++) {
        int num = ops[i];
        if (curSum + num > target) {
            continue;
        }

        addnumlist.push_back(num);
        ops.erase(ops.begin() + i);

        int temp = getAddNum(ops, curSum + num);
        if (temp == -1) {
            addnumlist.pop_back();
            ops[i] = num;
            continue;
        }
        if (temp == target) {
            return target;
        } else if (temp > addSum && temp < target) {
            addSum = temp;
            tempaddnumlist = addnumlist;
            copytemplist = ops;
        }
        addnumlist.pop_back();
        ops[i] = num;
    }

    if (addSum == -1) return -1;
    addnumlist = tempaddnumlist;
    ops = copytemplist;
    return addSum;
}

vector<int> getFinal(vector<int>& ops) {
    vector<int> finalres;
    for (int i = 0; i < addnumlist.size(); i++) {
        finalres.push_back(addnumlist[i]);
        if (i < ops.size()) {
            finalres.push_back(ops[i]);
        }
    }
    return finalres;
}

int main() {
    cin >> target >> len;
    vector<int> ops;
    int input;
    while (cin >> input) {
        ops.push_back(input);
        if (std::cin.get() == '\n') break;
    }

    sort(ops.begin(), ops.end(), [](int& a, int& b){
        return a > b;
    });
    //for (auto ele : ops) cout << ele << ",";

    int sum = std::accumulate(ops.begin(), ops.end(), 0);
    m = ops.size() / 2;
    if (ops.size() % 2 == 1) m += 1;

    target = sum / 2;
    getAddNum(ops, 0);

    // vector<int> res = getFinal(ops);
    // for (auto ele : res) cout << ele << " ";
    return 0;
}