#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, ans = 0;
    int map[501][501];
    
    cin >> n >> m;
    
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            map[i][j] = INF;
        }
    }
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(map[a][b] == INF) map[a][b] = 1;
        else map[a][b]++;
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
            if(map[i][j] != INF) res++;
            if(map[j][i] != INF) res++;
        }
        if(res == n - 1) ans++;
    }
    
    cout << ans << '\n';
}