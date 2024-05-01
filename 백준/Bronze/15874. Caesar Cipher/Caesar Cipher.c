#include <stdio.h>

int main() {
	
	int k, s;
	unsigned char words[100000];
	unsigned char temp;

	scanf("%d %d ", &k, &s);
	scanf("%[^\n]", &words);

	k %= 26;
	
	for (int i = 0; i < s; i++) {
		if (words[i] == ' ' || words[i] == '.' || words[i] == ',') {
			continue;
		}
		temp = words[i];
		words[i] += k;
		if ('z' < words[i] && words[i]) {
			words[i] -= 'a';
			words[i] %= 26;
			words[i] += 'a';
		}
		else if ('Z' < words[i] && words[i] < 'a' || temp <= 'Z') {
			words[i] -= 'A';
			words[i] %= 26;
			words[i] += 'A';
		}
	}
	printf("%s", words);

	return 0;
}