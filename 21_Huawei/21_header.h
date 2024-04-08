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

// int nRead = 0;
// std::vector<int> vecIn;
// while (std::cin >> nRead)
// {    
//     vecIn.push_back(nRead);
//     if (std::cin.get() == '\n') {
//         break;
//     }
// }

