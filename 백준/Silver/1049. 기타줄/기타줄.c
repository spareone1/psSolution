#include <stdio.h>

int main() {
	int n, m;
	int string[100] = { 0 };
	int min;

	scanf("%d %d", &n, &m);

	int p = n / 6;
	int s = n % 6;
	int min_p = 1000;
	int min_s = 1000;

	for (int i = 0; i < m * 2; i += 2) {
		scanf("%d %d", &string[i], &string[i + 1]);
	}


	for (int i = 0; i < m * 2; i += 2) {
		if (string[i] < min_p) {
			min_p = string[i];
		}
		if (string[i + 1] < min_s) {
			min_s = string[i + 1];
		}
	}

	if (min_p * (p + 1) < min_s * n) {
		if (min_p * (p + 1) < min_p * p + min_s * s) {
			min = min_p * (p + 1);
		}
		else {
			min = min_p * p + min_s * s;
		}
	}
	else {
		if(min_s * n < min_p * p + min_s * s) {
			min = min_s * n;
		}
		else {
			min = min_p * p + min_s * s;
		}
	}


	printf("%d", min);

	return 0;
}