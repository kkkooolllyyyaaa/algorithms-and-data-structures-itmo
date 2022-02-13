#include <iostream>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;

int main() {
    io_boost;
    int t;
    cin >> t;
    while (t--) {
        long long ans = 0;
        int n, k;
        cin >> n >> k;
        int fighters_in_team = n / k;
        int remainder = n % k;
        int cur = n;
        for (int i = 1; i < k; ++i) {
            if (i < remainder) {
                cur -= (fighters_in_team + 1);
                ans += (fighters_in_team + 1) * cur;
            } else {
                cur -= fighters_in_team;
                ans += fighters_in_team * cur;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
