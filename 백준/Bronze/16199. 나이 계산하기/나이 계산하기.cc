#include <iostream>
using namespace std;

int sol(int (*date)[3]) {
    if(date[1][1] < date[0][1] || date[1][1] == date[0][1] && date[1][2] < date[0][2]) return date[1][0] - date[0][0] - 1;
    return date[1][0] - date[0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int date[2][3] = {0, };

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++)
            cin >> date[i][j];

    cout << sol(date) << '\n' << date[1][0] - date[0][0] + 1 << '\n' << date[1][0] - date[0][0] << '\n';
}