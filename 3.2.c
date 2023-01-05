#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lim 100
int main() {
	int arr[100], n, k, random;
	printf("Input 1 for random or 2 for manual\n");
	while (scanf_s("%d", &random) != 1 || (random != 1 && random != 2) || getchar() != '\n') {
		printf("wrong input\n");
		rewind(stdin);
	}
	printf("Input size of array\n");
	while (scanf_s("%d", &n) != 1 || n < 1 || n > 100 || getchar() != '\n') {
		printf("wrong input\n");
		rewind(stdin);
	}
	printf("Input k(interval)\n");
	while (scanf_s("%d", &k) != 1 || k < 1 || k > n || getchar() != '\n') {
		printf("wrong input\n");
		rewind(stdin);
	}
	if (random == 1) {
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (2 * lim + 1) - lim;
			printf("%4d ", arr[i]);
		}
		printf("\n");
	}
	else
		for (int i = 0; i < n; i++) {
			while (scanf_s("%d", &arr[i]) != 1 || getchar() != '\n') {
				printf("wrong input\n");
				rewind(stdin);
			}
		}
	for (int i = n - 1; i >= 0; i--) {
		if ((i + 1) % k == 0) {
			n++;
			for (int j = n - 1; j > i + 1; j--) {
				arr[j] = arr[j - 1];
			}
			arr[i + 1] = 0;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%4d ", arr[i]);
}