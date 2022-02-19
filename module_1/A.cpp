#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int left = 1, right, ma = 0;
    int flower, current = -1, count = 1, start_pos = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> flower;
        if (flower == current) {
            count++;
        } else {
            current = flower;
            count = 1;
        }
        if (count == 3) {
            if ((i - start_pos) > ma) {
                ma = i - start_pos;
                left = start_pos;
                right = i - 1;
            }
            start_pos = i - 1;
            current = flower;
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
