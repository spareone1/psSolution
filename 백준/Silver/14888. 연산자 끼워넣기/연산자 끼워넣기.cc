#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &v, int *sign, int l, int res, int* max, int* min) {
    if(l == v.size() - 1) {
        if(res >= *max) *max = res;
        if(res <= *min) *min = res;
        return;
    }
    if(sign[0] > 0) { sign[0]--; dfs(v, sign, l + 1, res + v[l + 1], max, min); sign[0]++; }
    if(sign[1] > 0) { sign[1]--; dfs(v, sign, l + 1, res - v[l + 1], max, min); sign[1]++; }
    if(sign[2] > 0) { sign[2]--; dfs(v, sign, l + 1, res * v[l + 1], max, min); sign[2]++; }
    if(sign[3] > 0) { sign[3]--; dfs(v, sign, l + 1, res / v[l + 1], max, min); sign[3]++; }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, max = -2147000000, min = 2147000000;
    int sign[4];

    cin >> n;
    vector<int> v (n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < 4; i++) cin >> sign[i];

    dfs(v, sign, 0, v[0], &max, &min);

    cout << max << '\n' << min << '\n';
}