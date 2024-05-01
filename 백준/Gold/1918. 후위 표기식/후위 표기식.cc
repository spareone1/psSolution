#include <iostream>
#include <stack>
#include <string>
using namespace std;

int isp(char c) {
	if(c == '*' || c == '/') return 2;
	if(c == '+' || c == '-') return 1;
	else return 0;
}

int icp(char c) {
	if(c == '*' || c == '/') return 2;
	if(c == '+' || c == '-') return 1;
	else return 4;
}

int main() {
	string str;
	stack<char> s;
	cin >> str;
	
	string::iterator it;
	for(it = str.begin(); it < str.end(); it++) {
		if(65 <= *it && *it <= 90) { cout << *it; continue; }
		if(*it == ')') {
			while(s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
			continue;
		}
		while(1) {
			if(s.empty()) { s.push(*it); break; }
			if(icp(*it) > isp(s.top())) {
				s.push(*it);
				break;
			}
			else {
				cout << s.top();
				s.pop();
				continue;
			}
		}
	}
	
	while(!s.empty()) {
		cout << s.top();
		s.pop();
	}
}