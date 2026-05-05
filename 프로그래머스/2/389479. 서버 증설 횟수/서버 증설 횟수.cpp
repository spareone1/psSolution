#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int ans = 0;
    int res = 0;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < players.size(); i++) {        
        if(!q.empty() && q.front().second + k <= i) {
            res -= q.front().first;
            q.pop();
        }
        
        if(res < (players[i] / m)) {
            q.push({(players[i] / m) - res, i});
            ans += players[i] / m - res;
            res += (players[i] / m) - res;
        }
    }
    
    return ans;
}