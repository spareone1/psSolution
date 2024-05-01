#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ans[31] = {0, };
    
    for(int i = 0; i < 28; i++) {
        int tmp; cin >> tmp;
        ans[tmp]++;
    }
    
    for(int i = 1; i < 31; i++) {
        if(ans[i] == 0) cout << i << '\n';
    }
}