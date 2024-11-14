#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int dijkstra(vector<pair<int, int>> graph[], int n, int src, int dst) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(n, INF);
    pq.push({0, src}); visited[src] = 0;
    while(!pq.empty()) {
        auto[dist, cur] = pq.top(); pq.pop();
        if(visited[cur] < dist) continue;
        for(auto[nidx, ndist] : graph[cur]) {
            if(visited[nidx] > dist + ndist) { visited[nidx] = dist + ndist; pq.push({dist + ndist, nidx}); }
        }
    }
    return visited[dst];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x, ans = -1;
    cin >> n >> m >> x; x--;

    vector<pair<int, int>> graph[n];
    for(int i = 0; i < m; i++) { int a, b, dist; cin >> a >> b >> dist; graph[a - 1].push_back({b - 1, dist}); }

    for(int i = 0; i < n; i++) ans = max(ans, dijkstra(graph, n, i, x) + dijkstra(graph, n, x, i));
    cout << ans << '\n';
}