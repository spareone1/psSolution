#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	vector<pair<int, string>> v;
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		int age; string name;
		cin >> age >> name;
		v.push_back(make_pair(age, name));
	}
	
	stable_sort(v.begin(), v.end(), compare);
	
	for(auto i : v) cout << i.first << ' ' << i.second << '\n';
}