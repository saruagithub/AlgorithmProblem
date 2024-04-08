#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

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
    string s1;
    char ch;
    int res = 0;
    getline(cin, s1); // read whole line

    if (isdigit(ch)) res++;  // tolower(s1[i]) 大写变小写
    return 0;
}