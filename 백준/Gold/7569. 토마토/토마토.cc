#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dz[3] = {1, -1};

struct Point{
    int z, y, x, d;
    Point(int a, int b, int c, int d = 0) : z(a), y(b), x(c), d(d) {}
};

int bfs(int map[101][101][101], vector<Point> v, int h, int n, int m) {
    queue<Point> q;
    int res = 0;

    for(Point i : v) q.push(i);

    while(!q.empty()) {
        Point p = q.front();
        res = p.d > res ? p.d : res;
        q.pop();
        for(int i = 0; i < 4; i++) {
            if(p.y + dy[i] > -1 && p.y + dy[i] < n && p.x + dx[i] > -1 && p.x + dx[i] < m) {
                if(map[p.z][p.y + dy[i]][p.x + dx[i]] == 0) {
                    map[p.z][p.y + dy[i]][p.x + dx[i]] = 1;
                    q.push(Point(p.z, p.y + dy[i], p.x + dx[i], p.d + 1));
                }
            }
        }
        for(int i = 0; i < 2; i++) {
            if(p.z + dz[i] > -1 && p.z + dz[i] < h) {
                if(map[p.z + dz[i]][p.y][p.x] == 0) {
                    map[p.z + dz[i]][p.y][p.x] = 1;
                    q.push(Point(p.z + dz[i], p.y, p.x, p.d + 1));
                }
            }
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(map[i][j][k] == 0) return -1;
            }
        }
    }

    return res;
}

int main() {
    int map[101][101][101];
    vector<Point> v;
    int m, n, h;
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> map[i][j][k];
                if(map[i][j][k] == 1) v.push_back(Point(i, j, k));
            }
        }
    }

    cout << bfs(map, v, h, n ,m) << '\n';
    
}