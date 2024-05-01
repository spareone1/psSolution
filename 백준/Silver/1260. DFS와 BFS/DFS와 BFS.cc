#include <iostream>
#include <queue>
using namespace std;

void dfs(int (*arr)[1001], int *visited, int n, int y) {
    if(visited[y] == 1) return;
    visited[y] = 1;
    cout << y << ' ';
    for(int i = 1; i <= n; i++) {
        if(arr[y][i] == 1) dfs(arr, visited, n, i);
    }
}

void bfs(int (*arr)[1001], int *visited, int n, int y) {
    queue<int> q;
    q.push(y);
    while(!q.empty()) {
        int i = q.front(); q.pop();
        visited[i] = 1;
        cout << i << ' ';
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] && !visited[j]) { q.push(j); visited[j] = 1; }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, v;
    int arr[1001][1001] = {{0, }, };
    int dfs_visited[1001] = {0, };
    int bfs_visited[1001] = {0, };

    cin >> n >> m >> v;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    dfs(arr, dfs_visited, n, v);
    cout << '\n';
    bfs(arr, bfs_visited, n, v);
    cout << '\n';
}