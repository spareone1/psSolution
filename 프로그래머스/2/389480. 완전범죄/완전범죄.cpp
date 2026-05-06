#include <bits/stdc++.h>
using namespace std;

struct Things {
    int a, b, c;
    Things(int a, int b, int c) : a(a), b(b), c(c) {}
};

int solution(vector<vector<int>> info, int n, int m) {
    int ans = 2147000000;
    
    queue<Things> q;
    vector<vector<int> > visited(1000, vector<int>(1000, 2147000000));
    
    q.push(Things(info[0][0], 0, 0));  // A가 0번 물건 훔침
    visited[0][0] = info[0][0];
    q.push(Things(0, info[0][1], 0));  // B가 0번 물건 훔침
    visited[0][info[0][1]] = 0;
    
    while(!q.empty()) {
        Things t = q.front(); q.pop();
        if(visited[t.c][t.b] < t.a) continue;
        if(t.a >= n || t.b >= m) continue;
        if(t.c == info.size() - 1) { if(ans > t.a) ans = t.a; continue; }
        
        q.push(Things(t.a + info[t.c + 1][0], t.b, t.c + 1));  // A가 i번 물건 훔침
        visited[t.c + 1][t.b] = min(t.a + info[t.c + 1][0], visited[t.c + 1][t.b]);
        q.push(Things(t.a, t.b + info[t.c + 1][1], t.c + 1));  // B가 i번 물건 훔침
        visited[t.c + 1][t.b + info[t.c + 1][1]] = min(t.a, visited[t.c + 1][t.b + info[t.c + 1][1]]);
    }
    
    return ans == 2147000000 ? -1 : ans;
}