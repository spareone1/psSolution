#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {1, 0, -1, 0};
    
    queue<pair<int, int>> q;
    vector<vector<int> > visited (maps.size(), vector<int> (maps[0].size(), 0));
    
    q.push({0, 0});
    visited[0][0] = 1;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        if(y == maps.size() - 1 && x == maps[0].size() - 1) {
            answer = visited[y][x];
            break;
        }
        q.pop();
        for(int i = 0; i < 4; i++) {
            if(y + dy[i] < 0 || y + dy[i] > maps.size() - 1 || x + dx[i] < 0 || x + dx[i] > maps[0].size() - 1) continue;
            if(maps[y + dy[i]][x + dx[i]] == 1 && visited[y + dy[i]][x + dx[i]] == 0) {
                visited[y + dy[i]][x + dx[i]] = visited[y][x] + 1;
                q.push({y + dy[i], x + dx[i]});
            }
        }
    }
    
    return answer;
}