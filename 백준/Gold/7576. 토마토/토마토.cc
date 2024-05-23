#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Point{
    int y, x, d;
    Point(int y, int x, int d) : y(y), x(x), d(d) {}
};

int bfs(int arr[1001][1001], vector<Point> &v, int n, int m) {
    queue<Point> q;
    int res = 0;
    for(auto i : v) q.push(i);

    while(!q.empty()) {
        Point p = q.front();
        res = p.d > res ? p.d : res;
        q.pop();
        for(int i = 0; i < 4; i++) {
            if(p.y + dy[i] > -1 && p.y + dy[i] < n && p.x + dx[i] > -1 && p.x + dx[i] < m) {
                if(arr[p.y + dy[i]][p.x + dx[i]] == 0) {
                    arr[p.y + dy[i]][p.x + dx[i]] = 1;
                    q.push(Point(p.y + dy[i], p.x + dx[i], p.d + 1));
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) return -1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    int map[1001][1001];
    vector<Point> v;

    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                v.push_back(Point(i, j, 0));
            }
        }
    }

    cout << bfs(map, v, n, m) << '\n';
}