#include <iostream>
#include <cmath>
#include <vector>

#define INF 1e9
using namespace std;

int min_int(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    int block_sz, block_cnt;
    block_sz = (int) sqrt(double(n)) + 1;
    block_cnt = n / block_sz;
    if (n % block_sz != 0)
        block_cnt++;

    vector<int> sq(block_cnt, INF);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sq[i / block_sz] = min_int(arr[i], sq[i / block_sz]);
    }

    for (int i = 0; i < n - k + 1; ++i) {
        int l = i, r = i + k - 1;
        int mi = INF;
        while (l % block_sz != 0 && l <= r) {
            mi = min_int(arr[l], mi);
            ++l;
        }
        while ((l + block_sz - 1) <= r) {
            mi = min_int(sq[l / block_sz], mi);
            l += block_sz;
        }
        while (l <= r) {
            mi = min_int(arr[l], mi);
            ++l;
        }
        cout << mi << ' ';
    }
    return 0;
}
