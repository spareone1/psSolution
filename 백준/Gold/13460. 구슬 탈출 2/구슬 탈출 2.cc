#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {1, 0, -1, 0};

    int n, m, ry, rx, bx, by, ty, tx;
    queue<pair<pair<pair<int, int>, pair<int, int>>, int>> q;

    int map[12][12] = {0, };

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++) {
            if(temp[j] == '#') map[i][j] = 0;
            else if(temp[j] == '.') map[i][j] = 1;
            else if(temp[j] == 'O') { map[i][j] = 1; ty = i, tx = j; }
            else if(temp[j] == 'R') { map[i][j] = 1; ry = i; rx = j; }
            else if(temp[j] == 'B') { map[i][j] = 1; by = i; bx = j; }
        }
    }

    q.push({{{ry, rx}, {by, bx}}, 0});

    while(!q.empty()) {
        int dry = q.front().first.first.first;
        int drx = q.front().first.first.second;
        int dby = q.front().first.second.first;
        int dbx = q.front().first.second.second;
        int sum = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int tdry = dry, tdrx = drx, tdby = dby, tdbx = dbx, flag = 0;
            while(map[tdry + dy[i]][tdrx + dx[i]] != 0 && map[tdby + dy[i]][tdbx + dx[i]] != 0) {
                tdry += dy[i]; tdrx += dx[i];
                tdby += dy[i]; tdbx += dx[i];
                if(tdby == ty && tdbx == tx) { flag = 1; break; }
                if(tdry == ty && tdrx == tx) { flag = 2; tdry = 0; tdrx = 0; break; }
            }
            while(map[tdry + dy[i]][tdrx + dx[i]] != 0 && (tdry + dy[i] != tdby || tdrx + dx[i] != tdbx) && flag != 2) {
                tdry += dy[i]; tdrx += dx[i];
                if(tdry == ty && tdrx == tx) { cout << ++sum << '\n'; return 0; }
            }
            while(map[tdby + dy[i]][tdbx + dx[i]] != 0 && (tdby + dy[i] != tdry || tdbx + dx[i] != tdrx)) {
                tdby += dy[i]; tdbx += dx[i];
                if(tdby == ty && tdbx == tx) { flag = 1; break; }
            }
            if(tdry == dry && tdrx == drx && tdby == dby && tdbx == dbx) flag = 1;
            if(flag == 1) continue;
            if(flag == 2 && sum + 1 < 11) { cout << sum + 1 << '\n'; return 0; }
            if(sum + 1 > 10) { cout << -1 << '\n'; return 0; }
            q.push({{{tdry, tdrx}, {tdby, tdbx}}, sum + 1});
        }
    }

    cout << -1 << '\n';
}