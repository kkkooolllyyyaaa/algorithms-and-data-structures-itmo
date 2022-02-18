#include <iostream>
#include <vector>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;
vector<vector<int>> graph;
vector<bool> used;
int USED_CNT = 0;

void dfs(int current, int limit) {
    used[current] = true;
    USED_CNT++;
    for (int i = 0; i < graph.size(); ++i) {
        if (i != current && !used[i] && graph[current][i] <= limit) {
            dfs(i, limit);
        }
    }
}

void dfs_backwards(int current, int limit) {
    used[current] = true;
    USED_CNT++;
    for (int i = 0; i < graph.size(); ++i) {
        if (i != current && !used[i] && graph[i][current] <= limit) {
            dfs_backwards(i, limit);
        }
    }
}

void restore_all() {
    used.clear();
    used.resize(graph.size());
    USED_CNT = 0;
}

bool check_limit(int limit) {
    bool straight = false, backwards = false;
    restore_all();
    dfs(0, limit);
    if (USED_CNT == graph.size())
        straight = true;

    restore_all();
    dfs_backwards(0, limit);
    if (USED_CNT == graph.size())
        backwards = true;

    if (backwards && straight)
        return true;
    return false;
}

int main() {
    io_boost;
    int n;
    cin >> n;
    graph.resize(n);
    restore_all();

    int weight, ma = 0;
    for (int i = 0; i < n; ++i) {
        graph[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> weight;
            graph[i][j] = weight;
            if (weight > ma)
                ma = weight;
        }
    }

    int left = 0, right = 2 * ma, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (check_limit(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
    return 0;
}
