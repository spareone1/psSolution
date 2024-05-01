#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, ans = 0;
    vector<int> v;
    
    cin >> n;
    for(int i = 0; i < n; i++) { int temp; cin >> temp; v.push_back(temp); }
    
    int h = v[0];
    for(int i = 1; i < n; i++) {
        if(h > v[i]) { h = v[i]; continue; }
        h = v[i]; ans++;
    }
    
    cout << ans + 1<< '\n';
}