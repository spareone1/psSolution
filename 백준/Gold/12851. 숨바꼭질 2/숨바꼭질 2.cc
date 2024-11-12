#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, ans1 = 2147000000, ans2 = 0;
    cin >> n >> k;

    queue<pair<int, int>> q;
    vector<int> visited(100001, -1);
    visited[n] = 0;

    q.push({n, 0});
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        if(p.first == k) {
            if(p.second < ans1) { ans1 = p.second; ans2 = 1; }
            else if(p.second == ans1) ans2++;
        } else {
            int dx[3] = { p.first + 1, p.first - 1, p.first * 2 };
            for(int i : dx) {
                if((i > -1 && i < 100001) && (visited[i] == -1 || visited[i] == p.second + 1)) {
                    visited[i] = p.second + 1;
                    q.push({i, p.second + 1});
                }
            }
        }        
    }

    cout << ans1 << '\n' << ans2 << '\n';
}