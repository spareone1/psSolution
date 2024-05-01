#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void dfs(vector<vector<int>> &map, vector<vector<int>> &visited, int y, int x, int* res) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        if(y + dy[i] > map.size() - 1 || x + dx[i] > map[0].size() - 1 || y + dy[i] < 0 || x + dx[i] < 0) continue;
        if(map[y + dy[i]][x + dx[i]] == 1 && visited[y + dy[i]][x + dx[i]] == 0) {
            *res += 1; dfs(map, visited, y + dy[i], x + dx[i], res);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ans = 0, max = 0;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 1 && visited[i][j] == 0) {
                ans++;
                int res = 1;
                dfs(map, visited, i, j, &res);
                if(max < res) max = res;
            }
        }
    }

    cout << ans << '\n' << max << '\n';
}