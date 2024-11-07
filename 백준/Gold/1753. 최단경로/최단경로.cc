#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, k;
    cin >> v >> e >> k;
    vector<vector<pair<int, int>>> graph(v);
    vector<int> ans(v, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 0; i < e; i++) { int a, b, dist; cin >> a >> b >> dist; graph[a - 1].push_back({b - 1, dist}); }

    pq.push({0, k - 1}); ans[k - 1] = 0;
    while(!pq.empty()) {
        pair<int, int> p = pq.top(); pq.pop();
        if(ans[p.second] < p.first) continue;
        for(int i = 0; i < graph[p.second].size(); i++){
            int next = graph[p.second][i].first, nextdist = graph[p.second][i].second + ans[p.second];
            if(nextdist < ans[next]) { ans[next] = nextdist; pq.push({nextdist, next}); }
        }
    }

    for(int i : ans) {
        if(i == INF) cout << "INF" << '\n';
        else cout << i << '\n';
    }
}