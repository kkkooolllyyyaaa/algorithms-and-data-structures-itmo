#include <iostream>
#include <algorithm>
#include <vector>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    io_boost;
    int n, k;
    cin >> n >> k;
    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }
    sort(costs.begin(), costs.end(), comp);
    int ans = 0;
    for (size_t i = 0; i < n; ++i) {
        if ((i + 1) % k != 0)
            ans += costs[i];
    }
    cout << ans << endl;
    return 0;
}
