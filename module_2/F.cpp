#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <algorithm>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;

bool strips_comp(string s1, string s2) {
    return s1 + s2 > s2 + s1;
}

int main() {
    io_boost;
    string str;
    vector<string> strips;
    while (cin >> str) {
        strips.push_back(str);
    }
    sort(strips.begin(), strips.end(), strips_comp);
    for (auto &strip: strips) {
        cout << strip;
    }
    cout << endl;
    return 0;
}
