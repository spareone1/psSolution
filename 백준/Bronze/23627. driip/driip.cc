#include <iostream>
#include <string>
using namespace std;

int solution(string s) {
	if (s.size() < 5) return 0;
	
	string last = s.substr(s.size() - 5, 5);
	if (!last.compare("driip")) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string str;
	cin >> str;
	
	if (solution(str)) cout << "cute" << '\n';
	else cout << "not cute" << '\n';
}
