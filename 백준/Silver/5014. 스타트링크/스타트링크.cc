#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    vector<int> visited(f + 1, INF);
    queue<pair<int, int>> q;

    q.push({s, 0}); visited[s] = 0;
    while(!q.empty()) {
        auto[current, count] = q.front(); q.pop();
        int dx[2] = {current + u, current - d};
        for(int i : dx) {
            if(i > 0 && i < f + 1 && visited[i] > count + 1) {
                visited[i] = count + 1;
                q.push({i, count + 1});
            }
        }
    }
    if(visited[g] == INF) cout << "use the stairs" << '\n';
    else cout << visited[g] << '\n';
}