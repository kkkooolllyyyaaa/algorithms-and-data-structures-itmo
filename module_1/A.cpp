#include <iostream>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define MAX(x, y) ((x)>(y)?(x):(y))
#define MIN(x, y) ((x)>(y)?(y):(x))

using namespace std;

int main() {
    io_boost;
    int n;
    cin >> n;
    int left = 1, right, ma = 0;
    int x, current = -1, count = 1, start_pos = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x == current) {
            count++;
        } else {
            current = x;
            count = 1;
        }

        if (count == 3) {
            if ((i - start_pos) > ma) {
                ma = i - start_pos;
                left = start_pos;
                right = i - 1;
            }
            start_pos = i - 1;
            current = x;
            count = 2;
        }
    }
    if ((n - start_pos + 1) > ma) {
        left = start_pos;
        right = n;
    }
    cout << left << ' ' << right << endl;
    return 0;
}
