#include <iostream>
#include <vector>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;

int main() {
    io_boost;
    long long A, B, C, D, k;
    cin >> A >> B >> C >> D >> k;

    long long n = A, cnt = 0;
    vector<long long> cycle = {A};

    while (cnt < k) {

        n = n * B;

        if (n <= C) {
            cout << 0 << endl;
            return 0;
        }

        n = n - C;

        if (n > D) {
            cout << D << endl;
            return 0;
        }

        if (n == A) {
            cout << cycle[k % (cnt + 1)] << endl;
            return 0;
        }

        ++cnt;
        cycle.push_back(n);
    }
    cout << n << endl;
    return 0;
}
