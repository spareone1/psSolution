#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int field[101][101] = {0, };
    int ans = 0;

    for(int i = 0; i < 4; i++) {
        int coordinate[4] = {0, };
        for(int j = 0; j < 4; j++) cin >> coordinate[j];
        for(int j = coordinate[0]; j < coordinate[2]; j++) {
            for(int k = coordinate[1]; k < coordinate[3]; k++) {
                if(field[j][k] == 0) {field[j][k]++; ans++;}
            }
        }
    }
    cout << ans << '\n';
}