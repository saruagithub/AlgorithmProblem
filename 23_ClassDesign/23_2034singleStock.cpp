#include "../21_Huawei/21_header.h"

class StockPrice {
public:
    unordered_map<int, int> mp; // time,val
    multiset<int> prices;
    int curtime;

    StockPrice() {
        curtime = 0;
    }
    
    void update(int timestamp, int price) {
        curtime = max(curtime, timestamp);
        if (mp.count(timestamp)) {
            int prevprice = mp[timestamp];
            // update prices
            auto it = prices.find(prevprice);
            if (it != prices.end()) prices.erase(it);
        }
        mp[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return mp[curtime];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */