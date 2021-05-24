#include <stdio.h>
#include <malloc.h>
#include "Teste15_16.h"


int main(int argc, char *argv[]) {
	Mat *m = malloc(sizeof(Mat));
	int i = 0, j = 0;
	for (; i < 5; ++i, ++j) { setEntry(m, i, j, 1); }
	printMatrix(*m);
	printf("%f\n", getEntry(*m, 1, 1));
}