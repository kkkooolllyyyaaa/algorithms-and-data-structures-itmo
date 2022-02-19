#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool strips_comp(string s1, string s2) {
    return s1 + s2 > s2 + s1;
}

int main() {
    string str;
    vector<string> strips;

    while (cin >> str)
        strips.push_back(str);

    sort(strips.begin(), strips.end(), strips_comp);

    for (auto &strip: strips)
        cout << strip;
    return 0;
}
