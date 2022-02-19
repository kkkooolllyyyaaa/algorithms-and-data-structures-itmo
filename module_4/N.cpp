#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> opened;
vector<bool> used;

int dfs(int start) {
    int ans = 1;
    used[start] = true;
    for (int v: graph[start]) {
        if (!used[v] && !opened[v])
            ans += dfs(v);
        else if (!used[v])
            ans = ans + dfs(v) - 1;
    }
    return ans;
}

void clear_used(int n) {
    used.clear();
    used.resize(n, false);
}

int main() {
    int n, x;
    cin >> n;
    graph.resize(n);
    opened.resize(n, false);

    for (int i = 0; i < n; ++i) {
        cin >> x;
        graph[--x].push_back(i);
    }

    int ans = 0, opened_cnt = 0, best_v;
    while (opened_cnt < n) {
        int ma = 0;
        for (int i = 0; i < n; ++i) {
            if (opened[i])
                continue;

            clear_used(n);
            int res = dfs(i);
            if (res > ma) {
                ma = res;
                best_v = i;
            }
        }
        clear_used(n);
        opened_cnt += dfs(best_v);
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                opened[i] = true;
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}
