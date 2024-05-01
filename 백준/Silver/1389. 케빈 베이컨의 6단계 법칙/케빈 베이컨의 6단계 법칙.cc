#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, ans = 0, mini = 2147000000;
    int map[501][501];
    
    cin >> n >> m;
    
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(i == j) map[i][j] = 0;
            else map[i][j] = INF;
        }
    }
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    
    for(int k = 1; k < n + 1; k++) {
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    
    for(int i = 1; i < n + 1; i++) {
        int res = 0;
        for(int j = 1; j < n + 1; j++) {
            res += map[i][j];
        }
        if(res < mini) { mini = res; ans = i; }
    }
    
    cout << ans << '\n';
}