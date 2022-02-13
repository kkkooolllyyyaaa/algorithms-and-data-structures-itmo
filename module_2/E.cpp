#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;

vector<int> stoyla;

bool can_be_placed(int potential_answer, int k) {
    int left = stoyla.front();
    k--;
    for (size_t i = 1; i < stoyla.size(); ++i) {
        if ((stoyla[i] - left) >= potential_answer) {
            left = stoyla[i];
            k--;
        }
        if (k == 0)
            return true;
    }
    return false;
}

int main() {
    io_boost;
    int n, k;
    cin >> n >> k;

    stoyla.resize(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> stoyla[i];
    }
    int left = 0, right = stoyla.back() - stoyla.front(), mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (can_be_placed(mid, k)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (can_be_placed(left, k)) {
        cout << left << endl;
    } else {
        cout << left - 1 << endl;
    }
    return 0;
}
