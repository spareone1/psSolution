#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int recruit[3];
	int now[3];
	
	for(int i = 0; i < 3; i++) cin >> recruit[i];
	for(int i = 0; i < 3; i++) cin >> now[i];
	
	int total = ((now[0] - recruit[0]) * 360) + ((now[1] - recruit[1]) * 30) + (now[2] - recruit[2]);
	
	int year = total / 360;
	int annual = 0;
	for(int i = 1; i <= year; i++) {
		int temp = i;
		if(temp % 2 == 0) temp--;
		int a = temp - (temp / 2 + 1);
		annual += a + 15;
	}
	
	int monthly = total / 30;
	if(monthly > 36) monthly = 36;
	
	cout << annual << ' ' << monthly << '\n';
	cout << total << "days" <<'\n';
}