#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> colors;

int get_other_color(int clr) {
    if (clr == 1)
        return 2;
    return 1;
}

void dfs(int start, int color) {
    colors[start] = color;
    for (int v: graph[start]) {
        if (colors[v] == 0) {
            dfs(v, get_other_color(color));
        } else if (colors[v] == color) {
            cout << "NO" << endl;
            exit(0);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);

    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        colors.clear();
        colors.resize(n, 0);
        dfs(i, 1);
    }

    cout << "YES" << endl;
    return 0;
}
