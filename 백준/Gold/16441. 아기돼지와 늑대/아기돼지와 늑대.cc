#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

struct wolf{
    int y, x;
    wolf(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

void dfs(int(* map)[101], int(* visited)[101], int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        if(visited[y + dy[i]][x + dx[i]] != 0) continue;
        if(map[y + dy[i]][x + dx[i]] == 0) continue;
        if(map[y + dy[i]][x + dx[i]] == 2) {
            int ty = y, tx = x, flag = 0;
            while(map[ty + dy[i]][tx + dx[i]] == 2) {
                ty += dy[i]; tx += dx[i];
                if(visited[ty][tx] == 1) flag = 1;
            }
            if(map[ty + dy[i]][tx + dx[i]] != 0) {
                ty += dy[i]; tx += dx[i];
                if(visited[ty][tx] == 1) flag = 1;
            }
            if(flag == 1) continue;
            dfs(map, visited, ty, tx);
        }
        if(map[y + dy[i]][x + dx[i]] == 1) dfs(map, visited, y + dy[i], x + dx[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    vector<wolf> v;
    int map[101][101] = {0, };
    int visited[101][101] = {0, };

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++) {
            if(temp[j] == '#') map[i][j] = 0;
            else if(temp[j] == '.') map[i][j] = 1;
            else if(temp[j] == '+') map[i][j] = 2;
            else if(temp[j] == 'W') { map[i][j] = 1; v.push_back(wolf(i, j)); }
        }
    }

    for(auto i : v) {
        dfs(map, visited, i.y, i.x);
    }

    for(auto i : v) {
        map[i.y][i.x] = 3;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == 0 && map[i][j] == 1) map[i][j] = 4;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) cout << "#";
            else if(map[i][j] == 1) cout << ".";
            else if(map[i][j] == 2) cout << "+";
            else if(map[i][j] == 3) cout << "W";
            else if(map[i][j] == 4) cout << "P";
        }
        cout << '\n';
    }
}