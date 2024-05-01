#include <iostream>
using namespace std;

int main() {
	int board[1001] = {0};
	int bring[3] = {4, 3, 1};
	int n;
	cin >> n;
	
	board[1] = board[3] = board[4] = 1;
	board[2] = 0;
	
	for(int i = 5; i <= n; i++) {
		for(int j = 0; j < 3; j++) {
			if(board[i-bring[j]] == 0) {
				board[i] = 1;
				break;
			}
		}
	}
	
	if(board[n] == 1) cout << "SK";
	else cout << "CY";
	
}