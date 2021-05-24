#ifndef PROGRAMACAOIMPERATIVA_TESTE15_16_TESTE15_16_H_
#define PROGRAMACAOIMPERATIVA_TESTE15_16_TESTE15_16_H_
char* my_strcat(char s1[], char s2[]);
int remRep(char x[]);
typedef struct nodo
{
	int valor;
	struct nodo* esq, * dir;
} * ABin;
ABin newNode(int data);
int nivelV(ABin a, int n, int v[]);
int addOrd(ABin* root, int x);

typedef struct listaC
{
	int coluna;
	float valor;
	struct listaC* prox;
} * Colunas;

typedef struct listaL
{
	int linha;
	Colunas lcol;
	struct listaL* prox;
} * Mat;

void transpose(Mat *m);
void printMatrix(Mat m);
void setEntry(Mat *m, int linha, int coluna, float valor);
float getEntry(Mat m, int linha, int coluna);

#endif //PROGRAMACAOIMPERATIVA_TESTE15_16_TESTE15_16_H_
