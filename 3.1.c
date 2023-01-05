#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define lim 50
float mod(float a) {
	if (a < 0)
		return -a;
	else
		return a;
}
int main() {
	srand(time(NULL));
	float arr[100],C,prod=1,max;
	int k,random,grtC=0,indmax=0;
	printf("Input 1 for random or 2 for manual\n");
	while (scanf_s("%d", &random) != 1 || (random != 1 && random != 2) || getchar() != '\n') {
		printf("wrong input\n");
		rewind(stdin);
	}
	printf("Input size of array\n");
	while (scanf_s("%d", &k) != 1 || k < 1 || k > 100 || getchar() != '\n') {
		printf("wrong input\n");
		rewind(stdin);
	}
	printf("Input C(num to compare)\n");
	while (scanf_s("%f", &C) != 1 || getchar() != '\n') {
		printf("wrong input\n");
		rewind(stdin);
	}
	if (random == 1)
		for (int i = 0; i < k; i++) {
			arr[i] = rand() % (200 * lim + 1);
			arr[i] = arr[i] / (float)100 - lim;
			printf("%f\n", arr[i]);
			if (arr[i] > C)
				grtC++;
		}
	else
		for (int i = 0; i < k; i++) {
			while (scanf_s("%f", &arr[i]) != 1 || getchar() != '\n') {
				printf("wrong input\n");
				rewind(stdin);
			}
			if (arr[i] > C)
				grtC++;
		}
	printf("\n");
	max = mod(arr[0]);
	for (int i = 0; i < k; i++) {
		if (mod(arr[i]) > max){
			max = mod(arr[i]);
			indmax = i;
		}
	}
	for (int i = indmax+1; i < k; i++) {
		prod *= arr[i];
	}
	printf("%d elements greater than C(%f)\nproduct of elements after max by module is %f", grtC, C, prod);
	return 0;
}