#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int map[102][102];
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(i == j) map[i][j] = 0;
            else map[i][j] = INF;
        }
    }
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(map[a][b] > c) map[a][b] = c;
    }
    
    for(int k = 1; k < n + 1; k++) {
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(map[i][j] == INF) cout << 0 << ' ';
            else cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}