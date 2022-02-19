#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> positions;

bool can_be_placed(int potential_answer, int count);

int main() {
    int n, k;
    cin >> n >> k;

    positions.resize(n);
    for (size_t i = 0; i < n; ++i)
        cin >> positions[i];

    int left = 0, right = positions.back() - positions.front(), mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (can_be_placed(mid, k))
            left = mid + 1;
        else
            right = mid;
    }

    if (can_be_placed(left, k))
        cout << left << endl;
    else
        cout << left - 1 << endl;

    return 0;
}

bool can_be_placed(int potential_answer, int count) {
    int left = positions.front();
    count--;
    for (size_t i = 1; i < positions.size(); ++i) {
        if ((positions[i] - left) >= potential_answer) {
            left = positions[i];
            count--;
        }
        if (count == 0)
            return true;
    }
    return false;
}