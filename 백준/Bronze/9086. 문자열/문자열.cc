#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s = "";
        cin >> s;
        cout << s[0] << s[s.size() - 1] << '\n';
    }
}