#include <iostream>
#include <cmath>
#include <queue>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;

typedef struct sign_and_index {
    int cnt;
    int index;

    bool operator<(const struct sign_and_index &sign2) const {
        return cnt < sign2.cnt;
    }
} sign;

void print_pair(int s1, int s2, int cnt) {
    for (int i = 0; i < cnt; ++i) {
        cout << s1 << ' ' << s2 << ' ';
    }
}

void print_one(int s, int cnt) {
    for (int i = 0; i < cnt; ++i) {
        cout << s << ' ';
    }
}

int main() {
    io_boost;
    int k, n = 0;
    cin >> k;
    priority_queue<sign> signs;
    for (int i = 0; i < k; ++i) {
        int cnt;
        cin >> cnt;
        n += cnt;
        signs.push({.cnt = cnt, .index = i + 1});
    }
    while (!signs.empty()) {
        if (signs.size() == 1) {
            print_one(signs.top().index, signs.top().cnt);
            break;
        }
        sign sg = signs.top();
        signs.pop();

        sign second = signs.top();
        signs.pop();

        print_pair(sg.index, second.index, 1);
        sg.cnt -= 1;
        second.cnt -= 1;

        if (sg.cnt > 0)
            signs.push(sg);
        if (second.cnt > 0)
            signs.push(second);
    }
    return 0;
}
