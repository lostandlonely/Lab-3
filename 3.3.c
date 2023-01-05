#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lim 100
int main() {
	int arr[100], n, random,cnt=0,cntmax=0,num;
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] == arr[j])
				cnt++;
		}
		if (cnt > cntmax) {
			num = arr[i];
			cntmax = cnt;
		}
		cnt = 0;
	}
	printf("The most frequent number is %d", num);
	return 0;
}