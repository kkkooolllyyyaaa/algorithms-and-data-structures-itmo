#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;

int main() {
    io_boost;
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    int A = a + c + f + h, B = b + d + e + g, i;
    if (A != B) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (i = 0; i < c; ++i) {
        cout << "AB+" << endl << "CB-" << endl;
    }
    for (i = 0; i < f; ++i) {
        cout << "AB+" << endl << "FB-" << endl;
    }
    for (i = 0; i < h; ++i) {
        cout << "AE+" << endl << "HE-" << endl;
    }

    for (i = 0; i < d; ++i) {
        cout << "BA+" << endl << "DA-" << endl;
    }
    for (i = 0; i < e; ++i) {
        cout << "BA+" << endl << "EA-" << endl;
    }
    for (i = 0; i < g; ++i) {
        cout << "BC+" << endl << "GC-" << endl;
    }
    for (i = 0; i < A; ++i) {
        cout << "AB-" << endl;
    }
    return 0;
}

