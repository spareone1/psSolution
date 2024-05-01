#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> coin;
    int n, k, ans = 0;
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) { int temp; cin >> temp; coin.push_back(temp); }
    
    for(int i = n - 1; i > -1; i--) {
        if(!(k / coin[i])) continue;
        ans += k / coin[i];
        k %= coin[i];
    }
    
    cout << ans << '\n';
}