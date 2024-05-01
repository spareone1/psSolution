#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++) { int temp; cin >> temp; v.push_back(temp); }
    cin >> m;

    int lt = 1, rt = *max_element(v.begin(), v.end()), ans;
    while(lt <= rt) {
        int mid = (lt + rt) / 2, sum = 0;
        for(int i : v) sum += mid > i ? i : mid;
        if(m >= sum) { ans = mid; lt = mid + 1; }
        else rt = mid - 1;
    }
    cout << ans << '\n';
}