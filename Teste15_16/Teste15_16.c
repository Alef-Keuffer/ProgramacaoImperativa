#include "Teste15_16.h"
#include <malloc.h>
#include <stdlib.h>

char *my_strcat(char s1[], char s2[]) {
	int i;
	for (i = 0; s1[i] != 0; ++i);
	int c;
	for (c = 0; s2[c] != 0; ++c, ++i) { s1[i] = s2[c]; }
	s1[i] = s2[c];
	return s1;
}

char *my_strcat2(char *s1, char *s2) {
	int j = 0, i = 0, c = 0;
	char *r = malloc(0);
	for (; s2[j] != 0; ++c) {
		r = realloc(r, c + 1);
		if (s1[i] != 0) {
			r[c] = s1[i];
			++i;
		} else {
			r[c] = s2[j];
			++j;
		}
	}
	return r;
}

int remRep(char x[]) {
	int c = 0;
	for (int i = 1;; ++i) {
		if (x[i] != x[i - 1]) { x[++c] = x[i]; }
		if (x[i] == 0) {
			x[c] = x[i];
			break;
		}
	}
	return c;
}

void nivelRec(ABin a, int n, int v[], int current, int *i) {
	if (a != NULL) {
		if (n == current) {
			v[*i] = a->valor;
			(*i)++;
		} else {
			nivelRec(a->esq, n, v, current + 1, i);
			nivelRec(a->dir, n, v, current + 1, i);
		}
	}
}

int nivelV(ABin a, int n, int v[]) {
	int i = 0;
	nivelRec(a, n, v, 1, &i);
	return i;
}

ABin newNode(int data) {
	ABin node = malloc(sizeof(ABin));
	node->valor = data;
	node->esq = NULL;
	node->dir = NULL;
	return node;
}

int addOrd(ABin *a, int x) {
	int exists = -1;
	ABin *c = a;
	
	while (exists == -1) {
		if (*c == NULL) {
			*c = newNode(x);
			exists = 0;
		} else {
			int valor = (*c)->valor;
			if (x == valor) { exists = 1; }
			else if (x < valor) { c = &(*c)->esq; }
			else { c = &(*c)->dir; }
		}
	}
	return exists;
}

Mat find_line(Mat m, int linha) {
	Mat *current_line;
	for (current_line = &m;
		 *current_line == NULL
		 || (*current_line)->prox == NULL
		 || (*current_line)->prox->linha > linha;
		 current_line = &(*current_line)->prox);
	return *current_line;
}

Colunas find_col(Colunas c, int coluna) {
	Colunas *current_col;
	for (current_col = &c;
		 *current_col == NULL
		 || (*current_col)->prox == NULL
		 || (*current_col)->prox->coluna > coluna;
		 current_col = &(*current_col)->prox);
	return *current_col;
}

float getEntry(Mat m, int linha, int coluna) {
	Mat *current_line;
	for (current_line = &m;; current_line = &(*current_line)->prox) {
		if (*current_line == NULL || (*current_line)->linha > linha) { return 0; }
		else if ((*current_line)->linha == linha) { break; }
	}
	Colunas *current_column;
	for (current_column = &(*current_line)->lcol;; current_column = &(*current_column)->prox) {
		if (*current_column == NULL || (*current_column)->coluna > coluna) { return 0; }
		else if ((*current_column)->coluna == coluna) { return (*current_column)->valor; }
	}
}

Mat newLine(int line_number) {
	Mat newLine = malloc(sizeof(Mat));
	newLine->linha = line_number;
	newLine->prox = NULL;
	return newLine;
}

Colunas newCol(int col_number, float valor) {
	Colunas new_col = malloc(sizeof(Colunas));
	new_col->valor = valor;
	new_col->coluna = col_number;
	new_col->prox = NULL;
	return new_col;
}

void setEntry(Mat *m, int linha, int coluna, float valor) {
	if (valor == 0) { return; }
	Mat *current_line;
	for (current_line = m;; current_line = &(*current_line)->prox) {
		if (*current_line == NULL) {
			*current_line = newLine(linha);
			break;
		} else if ((*current_line)->linha == linha) { break; }
		else if ((*current_line)->prox == NULL) {}
		else if ((*current_line)->prox->linha > (*current_line)->linha) {
			Mat new_line = newLine(linha);
			new_line->prox = (*current_line)->prox;
			(*current_line)->prox = new_line;
			current_line = &new_line;
			break;
		}
	}
	Colunas *cc; /*current column*/
	for (cc = &((*current_line)->lcol);; cc = &((*cc)->prox)) {
		if (*cc == NULL) { *cc = newCol(coluna, valor); }
		if ((*cc)->coluna == coluna) {
			(*cc)->valor = valor;
			break;
		} else if ((*cc)->prox == NULL) { continue; }
		else if ((*cc)->prox->coluna > (*cc)->coluna) {
			Colunas new_col = newCol(coluna, valor);
			new_col->prox = (*cc)->prox;
			(*cc)->prox = new_col;
			break;
		}
	}
}

void printMatrix(Mat m) {
	Mat *line;
	Colunas *col;
	for (line = &m; *line != NULL; line = &(*line)->prox) {
		printf("Linha %d:", (*line)->linha);
		for (col = &(*line)->lcol; *col != NULL; col = &(*col)->prox) {
			printf(" (%d,%.2f)", (*col)->coluna, (*col)->valor);
		}
		puts("\n");
	}
}

void addTo(Mat *m1, Mat m2) {}

void transpose(Mat *m) {
	Mat *cl;     /*current line*/
	Colunas *cc; /*current column*/
	for (cl = m; *cl != NULL; cl = &(*cl)->prox) {
		for (cc = &(*cl)->lcol; *cc != NULL; cc = &(*cc)->prox) {
			int i = (*cl)->linha, j = (*cc)->coluna;
			float t = getEntry(*m, i, j);
			setEntry(m, i, j, getEntry(*m, j, i));
			setEntry(m, j, i, t);
		}
	}
}

