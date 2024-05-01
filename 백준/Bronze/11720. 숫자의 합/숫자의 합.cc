#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, ans = 0;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++) {
        ans += s[i] - '0';
    }
    cout << ans << '\n';
}