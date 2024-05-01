#include <iostream>
using namespace std;

int n;
int arr[1001][10];
int res[1001];
bool visited[1001][10];
int count = 0;

void print() {
	for(int i = 1; i <= n; i++) {
		if(res[i]) cout << res[i] << '\n';
	}
}

void dfs(int today, int pre) {
	//cout << today << ' ' << pre << '\n';
	if(visited[today][pre]) return;
	visited[today++][pre] = true;
	if(today == n) {
		for(int i = 1; i <= 9; i++) {
			if(i == pre) continue;
			if(arr[today][i] && !visited[today][i]) {
				res[today] = i;
				print();
				exit(0);
			}
		}
	}
	for(int i = 1; i <= 9; i++) {
		if(i == pre) continue;
		if(arr[today][i] && !visited[today][i]) {
			res[today] = i;
			dfs(today, i);
		}
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i][0];
		for(int j = 1; j <= arr[i][0]; j++) {
			int a;
			cin >> a;
			arr[i][a] = 1;
		}
	}
	dfs(0, 0);
	cout << -1;
}