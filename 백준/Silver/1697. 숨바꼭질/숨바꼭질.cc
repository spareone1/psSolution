#include <iostream>
#include <queue>
using namespace std;

int bfs(int n, int k) {
    int res;
    int visited[100001] = {0, };
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));

    visited[n] = 1;

    while(!q.empty()) {
        int point = q.front().first;
        int time = q.front().second;
        q.pop();
        if(point == k) { res = time; break; }
        if((point + 1 <= 100000) && !visited[point + 1]) { visited[point + 1] = 1; q.push(make_pair(point + 1, time + 1)); }
        if((point - 1 >= 0) && !visited[point - 1]) { visited[point - 1] = 1; q.push(make_pair(point - 1, time + 1)); }
        if((point * 2 <= 100000) && !visited[point * 2]) { visited[point * 2] = 1; q.push(make_pair(point * 2, time + 1)); }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    cout << bfs(n, k) << '\n';
}