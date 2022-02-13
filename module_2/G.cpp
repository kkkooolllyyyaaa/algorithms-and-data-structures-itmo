#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;

typedef struct weight_and_char {
    int weight;
    char c;
    int cnt;
} element;

bool comp(element e1, element e2) {
    return e1.weight > e2.weight;
}

int main() {
    io_boost;
    string str;
    cin >> str;
    vector<element> weights;
    vector<char> ans(str.length());
    vector<int> char_cnt(26, 0);

    for (char i: str) {
        char_cnt[i - 'a']++;
    }

    for (int i = 0; i < 26; ++i) {
        int weight;
        cin >> weight;
        weights.push_back({.weight = weight, .c = char('a' + i), .cnt = char_cnt[i]});
    }
    sort(weights.begin(), weights.end(), comp);

    int left = 0, right = ans.size() - 1;
    for (int i = 0; i < 26; ++i) {
        if (weights[i].cnt > 1) {
            ans[left] = weights[i].c;
            ans[right] = weights[i].c;
            --right;
            ++left;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (weights[i].cnt == 1) {
            ans[left] = weights[i].c;
            ++left;
        } else if (weights[i].cnt > 2) {
            for (int j = 0; j < weights[i].cnt - 2; ++j) {
                ans[left] = weights[i].c;
                ++left;
            }
        }
    }
    for (char an: ans) {
        cout << an;
    }
    cout << endl;
    return 0;
}
