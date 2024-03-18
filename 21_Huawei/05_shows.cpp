#include <iostream>
#include <vector>
using namespace std;

// one can see one show, 15min then next show
int maxshows(vector<vector<int>>& shows, int spacetime) {
    int res = 0;
    sort(shows.begin(), shows.end(), [](vector<int>&a, vector<int>&b){
        if (a[1] == b[1]) return a[0] > b[0];  // b0 - a0
        else return a[1] < b[1];  //b1 - a1
        // if (a[1] == b[1]) return b[0] - a[0];
        // else return b[1] - a[1];
    });
    cout << endl;
    for (auto ele: shows) {
        cout << ele[0] << " " << ele[1] << endl;
    }
    int lastend = shows[0][1];
    res = 1;
    for (int i = 1; i < shows.size(); i++) {
        if (shows[i][0] - lastend > 15) {
            res++;
            lastend = shows[i][1];
        }
    }
    return res;
}

int main() {
    int N, i = 0;
    vector<vector< int >> shows;
    cin >> N;
    while(i < N) {
        int start, duration;
        cin >> start >> duration;
        //int temp = start + duration;
        shows.push_back({start, start+duration});
        i++;
    }
    int space = 15;
    cout << maxshows(shows, space);
    return 0;
}