#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;

    vector<pair<int, int>> graph[n];
    vector<int> ans(n, INF);
    for(int i = 0; i < m; i++) { int v1, v2, dist; cin >> v1 >> v2 >> dist; graph[v1 - 1].push_back({dist, v2 - 1}); }
    cin >> a >> b; a--; b--;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, a}); ans[a] = 0;
    while(!pq.empty()) {
        pair<int, int> p = pq.top(); pq.pop();
        if(ans[p.second] < p.first) continue;
        for(int i = 0; i < graph[p.second].size(); i++) {
            int next = graph[p.second][i].second, nextdist = graph[p.second][i].first + ans[p.second];
            if(nextdist < ans[next]) { ans[next] = nextdist; pq.push({nextdist, next}); }
        }
    }
    cout << ans[b] << '\n';
}