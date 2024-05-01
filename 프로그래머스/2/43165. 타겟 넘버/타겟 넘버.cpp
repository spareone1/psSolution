#include <vector>
using namespace std;

void dfs(vector<int> &v, int l, int target, int res, int* ans) {
    if(l == v.size()) { if(res == target) *ans += 1; return; }
    dfs(v, l + 1, target, res + v[l], ans);
    dfs(v, l + 1, target, res - v[l], ans);
}

int solution(vector<int> numbers, int target) {
    int ans = 0;
    dfs(numbers, 0, target, 0, &ans);
    return ans;
}