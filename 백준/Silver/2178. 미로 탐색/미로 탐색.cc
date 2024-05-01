#include <bits/stdc++.h>
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    queue<pair<int, int>> q;
    int map[105][105] = {0, };
    int visited[105][105] = {0, };

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++) {
            map[i][j + 1] = (int)temp[j] - 48;
        }
    }

    q.push(make_pair(1, 1));
    visited[1][1] = 1;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        if(p.first == n && p.second == m) break;
        q.pop();
        for(int i = 0; i < 4; i++) {
            if(map[p.first + dy[i]][p.second + dx[i]] == 1 && visited[p.first + dy[i]][p.second + dx[i]] == 0) {
                visited[p.first + dy[i]][p.second + dx[i]] = visited[p.first][p.second] + 1;
                q.push(make_pair(p.first + dy[i], p.second + dx[i]));
            }
        }
    }

    cout << visited[n][m] << '\n';
}