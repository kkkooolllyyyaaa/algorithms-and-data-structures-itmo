#include <iostream>
#include <deque>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;


int main() {
    io_boost;
    int n, cnt = 0;
    cin >> n;

    deque<int> q1;
    deque<int> q2;
    char oper;
    int number;

    for (int i = 0; i < n; ++i) {
        cin >> oper;
        if (oper == '-') {
            cout << q1.front() << endl;
            q1.pop_front();
            if (cnt % 2 == 0) {
                int mid = q2.front();
                q2.pop_front();
                q1.push_back(mid);
            }
            --cnt;
            continue;
        }
        cin >> number;
        if (oper == '+') {
            q2.push_back(number);
            if (cnt % 2 == 0) {
                int mid = q2.front();
                q2.pop_front();
                q1.push_back(mid);
            }
        } else {
            q2.push_front(number);
            if (cnt % 2 == 0) {
                int mid = q2.front();
                q2.pop_front();
                q1.push_back(mid);
            }
        }
        ++cnt;
    }
    return 0;
}
