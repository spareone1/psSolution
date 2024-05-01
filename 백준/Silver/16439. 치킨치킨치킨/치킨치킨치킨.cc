#include <iostream>
using namespace std;

int n;
int m;
int arr[31][31]; 
int ans = 0;

int big(int i, int j, int k, int l) {
	int temp = arr[l][i] > arr[l][j] ? arr[l][i] : arr[l][j];
	return (temp > arr[l][k] ? temp : arr[l][k]);
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	
	for(int i = 1; i <= m-2; i++) {
		for(int j = (i+1); j <= m-1; j++) {
			for(int k = (j+1); k <= m; k++) {
				int temp = 0;
				for(int l = 1; l <= n; l++) {
					temp += big(i, j, k, l);
				}
				if(ans < temp) ans = temp;
			}
		}
	}
	
	cout << ans;
}