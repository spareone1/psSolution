#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> (&v)[102], vector<int> &visited, int x, int y, int count, int *res) {
    visited[x] = 1;
    for(int i = 0; i < v[x].size(); i++) {
        if(v[x][i] == y) { *res += count + 1; break; }
        if(visited[v[x][i]] == 0) dfs(v, visited, v[x][i], y, count + 1, res);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, m, res = 0;
    vector<int> v[102];
    vector<int> visited(102, 0);
    cin >> n >> a >> b >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }

    dfs(v, visited, a - 1, b - 1, 0, &res);

    if(res == 0) cout << -1 << '\n';
    else cout << res << '\n';
}