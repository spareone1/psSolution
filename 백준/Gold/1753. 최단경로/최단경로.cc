#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

struct edge{
    int node, dist;
    edge(int node, int dist) : node(node), dist(dist) {}
    bool operator<(const edge &e) const { return this->dist > e.dist; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, k;
    cin >> v >> e >> k;
    vector<vector<pair<int, int>>> graph(v);
    vector<int> ans(v, INF);
    priority_queue<edge> pq;

    for(int i = 0; i < e; i++) { int a, b, dist; cin >> a >> b >> dist; graph[a - 1].push_back({b - 1, dist}); }

    pq.push(edge(k - 1, 0));
    ans[k - 1] = 0;
    while(!pq.empty()) {
        edge p = pq.top(); pq.pop();
        if(ans[p.node] < p.dist) continue;
        for(int i = 0; i < graph[p.node].size(); i++){
            int next = graph[p.node][i].first, nextdist = graph[p.node][i].second + ans[p.node];
            if(nextdist < ans[next]) { ans[next] = nextdist; pq.push({next, nextdist}); }
        }
    }

    for(int i : ans) {
        if(i == INF) cout << "INF" << '\n';
        else cout << i << '\n';
    }
}