#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int arr[42] = {0, };
    int count = 0;
    
    for(int i = 0; i < 10; i++) {
        int tmp; cin >> tmp;
        arr[tmp % 42]++;
    }
    
    for(int i = 0; i < 42; i++) {
        if(arr[i] != 0) count++;
    }
    
    cout << count << '\n';
}