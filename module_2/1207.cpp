#include <iostream>
#include <cmath>
#include <vector>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
typedef long double dd;

typedef struct point {
    dd x, y;
    int index;
} pnt;

bool angle_comp(pnt a, pnt b) {
    // уравнение прямой
    // a.x * b.y - b.x * a.y > 0    <=>     k1 < k2
    return a.x * b.y - b.x * a.y > 0;
}

int main() {
    io_boost;
    int n;
    cin >> n;
    vector<pnt> points;

    // нахожу минимум (в 1 очередь по y, а во вторую по x)
    int mi_i = 0;
    dd mi_y = 1e9, mi_x = 1e9;
    for (int i = 0; i < n; ++i) {
        dd x, y;
        cin >> x >> y;
        if (y < mi_y) {
            mi_y = y;
            mi_x = x;
            mi_i = i;
        } else if (y == mi_y && x < mi_x) {
            mi_x = x;
            mi_i = i;
        }
        points.push_back({.x = x, .y = y, .index = i + 1});
    }
    // типо нормализую к нулю
    for (int i = 0; i < n; ++i) {
        if (i == mi_i)
            continue;
        points[i].x -= points[mi_i].x;
        points[i].y -= points[mi_i].y;
    }
    points.erase(points.begin() + mi_i, points.begin() + mi_i + 1);

    // сортирую
    sort(points.begin(), points.end(), angle_comp);
    cout << mi_i + 1 << ' ' << points[n / 2 - 1].index << endl;
    return 0;
}

