#include <bits/stdc++.h>
using namespace std;

int isValid(int map[9][9], int y, int x) {
    // 가로세로 검사
    for(int i = 0; i < 9; i++) {
        if(i != x) { if(map[y][x] == map[y][i]) return 0; }
        if(i != y) { if(map[y][x] == map[i][x]) return 0; }
    }

    // 3x3 검사
    int offsetY;
    int offsetX;

    if(y < 3) offsetY = 0;
    else if(y < 6) offsetY = 3;
    else offsetY = 6;

    if(x < 3) offsetX = 0;
    else if(x < 6) offsetX = 3;
    else offsetX = 6;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i + offsetY != y && j + offsetX != x) { if(map[y][x] == map[i + offsetY][j + offsetX]) return 0; }
        }
    }

    return 1;
}

void dfs(int map[9][9], vector<pair<int, int>> &v, int index) {
    if(index == v.size()) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) cout << map[i][j] << ' ';
            cout << '\n';
        }
        exit(0);
    }

    for(int i = 1; i < 10; i++) {
        map[v[index].first][v[index].second] = i;
        if(isValid(map, v[index].first, v[index].second)) dfs(map, v, index + 1);
        map[v[index].first][v[index].second] = 0;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int map[9][9];
    vector<pair<int, int> > v;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> map[i][j];
            if(map[i][j] == 0) v.push_back({i, j});
        }
    }
    dfs(map, v, 0);
}