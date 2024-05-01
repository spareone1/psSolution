#include <stdio.h>

int main() {
	int t;

	scanf("%d", &t);

	for (t; t > 0; t--) {
		int input;
		scanf("%d", &input);
		int max = input;
		while (input > 1) {
			if (input % 2 == 0) {
				input = input / 2;
			}
			else {
				input = input * 3 + 1;
			}
			if (max < input) {
				max = input;
			}
		}
		printf("%d\n", max);
	}
}