#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, ans = INF;
    cin >> v >> e;

    vector<vector<int>> graph(v, vector<int>(v, INF));
    for(int i = 0; i < graph.size(); i++) graph[i][i] = 0;
    for(int i = 0; i < e; i++) { int a, b, dist; cin >> a >> b >> dist; graph[a - 1][b - 1] = dist; }

    for(int k = 0; k < v; k++)
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            if(i != j) ans = min(ans, graph[i][j] + graph[j][i]);
    
    if(ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}