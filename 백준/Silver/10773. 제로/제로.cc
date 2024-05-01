#include <iostream>
#include <stack>
using namespace std;

int main() {
    int k, ans = 0;
    stack<int> s;

    cin >> k;

    for(int i = 0; i < k; i++) {
        int temp; cin >> temp;
        if(temp == 0) {
            s.pop();
        } else {
            s.push(temp);
        }
    }

    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }
    cout << ans << '\n';
}