#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void dfs(vector<vector<int>> &map, vector<vector<int>> &visited, int y, int x, int* res) {
    if(map[y][x] == 1) *res += 1;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        if(y + dy[i] < 0 || y + dy[i] > map.size() - 1 || x + dx[i] < 0 || x + dx[i] > map[0].size() - 1) continue;
        if(map[y + dy[i]][x + dx[i]] == 1 && visited[y + dy[i]][x + dx[i]] == 0)
            dfs(map, visited, y + dy[i], x + dx[i], res);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n, 0));
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < n; j++){
            map[i][j] = temp[j] - 48;
        }
    }

    for(int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map[0].size(); j++) {
            if(map[i][j] == 1 && visited[i][j] == 0) {
                int res = 0;
                dfs(map, visited, i, j, &res);
                ans.push_back(res);
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i : ans) {
        cout << i << '\n';
    }
}