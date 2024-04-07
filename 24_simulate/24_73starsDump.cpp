#include <vector>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        res.push_back(asteroids[0]);
        for (int i = 1; i < asteroids.size(); i++) {
            if (!res.empty() && res.back() > 0 && asteroids[i] < 0) {
                if (res.back() > -asteroids[i]) continue;
                if (res.back() == -asteroids[i]) {
                    res.pop_back();
                    continue;
                }
                while (!res.empty() && res.back() > 0 && res.back() < -asteroids[i]) {
                    res.pop_back();
                }
                if (!res.empty() && res.back() > 0 && res.back() == -asteroids[i]) {
                    res.pop_back();
                    continue;
                }
                if (!res.empty() && res.back() > 0 && res.back() > -asteroids[i]) continue;
                res.push_back(asteroids[i]);
            }
            else res.push_back(asteroids[i]);    
        }
        return res;
    }
};

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> res;
    
    for (int i = 0; i < asteroids.size(); i++) {
        bool exist = true;
        while (exist && asteroids[i] < 0 && !res.empty() && res.back() > 0) {
            if (res.back() < -asteroids[i]) {
                exist = true;
            }
            if (res.back() >= -asteroids[i]) {
                exist = false;
            }
            if (res.back() <= -asteroids[i]) res.pop_back();
        }
        if (exist) res.push_back(asteroids[i]);
    }
    return res;
}