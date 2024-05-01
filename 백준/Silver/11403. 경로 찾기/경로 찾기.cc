#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int map[101][101];
    
    cin >> n;
    for(int i = 1; i < n + 1; i++)
        for(int j = 1; j < n + 1; j++)
            cin >> map[i][j];
    
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(map[i][j] == 0) map[i][j] = INF;
        }
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
            else cout << 1 << ' ';
        }
        cout << '\n';
    }
}