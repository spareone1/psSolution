#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v;
    int n, ans = 0, tmp = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++) { int temp; cin >> temp; v.push_back(temp); }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++) {
        tmp += v[i];
        ans += tmp;
    }
    
    cout << ans << '\n';
}