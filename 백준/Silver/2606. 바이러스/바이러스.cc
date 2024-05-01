#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int> > &v, vector<int> &visited, int l) {
    visited[l] = 1;
    for(auto i : v[l]) if(visited[i] == 0) dfs(v, visited, i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ans = 0;
    cin >> n >> m;

    vector<vector<int> > v (n, vector<int> (n));
    vector<int> visited (n, 0);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    dfs(v, visited, 0);
    visited[0]--;
    for(int i : visited) ans += i;
    cout << ans << '\n';
}