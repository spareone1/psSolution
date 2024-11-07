#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ans = 2147000000, res = 0;
    char map[51][51];

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];

    for(int i = 0; i < n - 7; i++) {
        for(int j = 0; j < m - 7; j++) {
            for(int k = i; k < i + 8; k++) {
                for(int l = j; l < j + 8; l++) {
                    if(k % 2) {
                        if(l % 2) {
                            if(map[k][l] != 'B') res++;
                        } else {
                            if(map[k][l] != 'W') res++;
                        }
                    } else {
                        if(l % 2) {
                            if(map[k][l] != 'W') res++;
                        } else {
                            if(map[k][l] != 'B') res++;
                        }
                    }
                }
            }
            if(ans > res) ans = res;
            res = 0;
            for(int k = i; k < i + 8; k++) {
                for(int l = j; l < j + 8; l++) {
                    if(k % 2) {
                        if(l % 2) {
                            if(map[k][l] != 'W') res++;
                        } else {
                            if(map[k][l] != 'B') res++;
                        }
                    } else {
                        if(l % 2) {
                            if(map[k][l] != 'B') res++;
                        } else {
                            if(map[k][l] != 'W') res++;
                        }
                    }
                }
            }
            if(ans > res) ans = res;
            res = 0;
        }
    }
    cout << ans << '\n';
}