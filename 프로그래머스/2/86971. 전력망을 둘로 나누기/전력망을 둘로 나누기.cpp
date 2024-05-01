#include <vector>
#include <algorithm>
using namespace std;

void count(vector<vector<int>> map, vector<int> &visited, int l, int n, int* cnt) {
    *cnt += 1;
    visited[l] = 1;
    for(int i = 0; i < n; i++)
        if(map[l][i] == 1 && visited[i] == 0)
            count(map, visited, i, n, cnt);
}

int solution(int n, vector<vector<int>> wires) {
    int ans = 2147000000;
    
    for(int i = 0; i < n; i++) {
        vector<vector<int>> map(n, vector<int>(n));
        vector<int> visited(n, 0);
        int cnt = 0;
        
        for(int j = 0; j < wires.size(); j++) {
            if(j == i) continue;
            map[wires[j][0] - 1][wires[j][1] - 1] = 1;
            map[wires[j][1] - 1][wires[j][0] - 1] = 1;
        }
        
        count(map, visited, 0, n, &cnt);
        
        if(ans * ans > (2 * cnt - n) * (2 * cnt - n)) ans = max(2 * cnt - n, n - 2 * cnt);
        
    }
    return ans;
}