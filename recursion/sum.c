#include <stdio.h>

int sum(int lista[], int n) {
  if (n==0) return 0;

  return lista[0] + sum(lista+1, n-1);
}

int main(void) {
  int lista[] = {2, 2, 2, 2, 2};

  printf("%d", sum(lista, 5));
  return 0;
}