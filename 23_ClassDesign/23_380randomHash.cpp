#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> mp; // num,idx
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (mp.count(val)) return false;
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!mp.count(val)) return false;
        // delete val
        int idx = mp[val];
        mp[arr.back()] = idx;
        mp.erase(val);
        swap(arr[idx], arr[arr.size() - 1]);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        int randidx = rand() % arr.size();
        return arr[randidx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */