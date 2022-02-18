#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define INF 1e9
using namespace std;

int n, k;

int minimum(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int get_left(int iteration_number) {
    return iteration_number;
}

int get_right(int iteration_number) {
    return iteration_number + k - 1;
}

int main() {
    io_boost;
    cin >> n >> k;
    vector<int> arr(n);

    int block_sz = (int) sqrt(double(n)) + 1, block_cnt = n / block_sz;
    if (n % block_sz != 0)
        block_cnt++;
    vector<int> sq(block_cnt, INF);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sq[i / block_sz] = minimum(arr[i], sq[i / block_sz]);
    }

    for (int i = 0; i < n - k + 1; ++i) {
        int l = get_left(i), r = get_right(i);
        int mi = INF;
        while (l % block_sz != 0 && l <= r) {
            mi = minimum(arr[l], mi);
            ++l;
        }
        while ((l + block_sz - 1) <= r) {
            mi = minimum(sq[l / block_sz], mi);
            l += block_sz;
        }
        while (l <= r) {
            mi = minimum(arr[l], mi);
            ++l;
        }
        cout << mi << ' ';
    }
    cout << endl;
    return 0;
}

