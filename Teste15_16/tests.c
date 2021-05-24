#include <stddef.h>
#include <malloc.h>
#include "tests.h"
#include "Teste15_16.h"


void test_nivelV(int argc, char* argv[])
{
	ABin a = newNode(1);
	a->esq = newNode(2);
	a->dir = newNode(3);
	a->esq->esq = newNode(4);
	a->esq->dir = newNode(5);
	int v[100];
	int c = nivelV(a, 3, v);
	for (int i = 0; i < c; ++i)
	{ printf("%d ", v[i]); }
}
