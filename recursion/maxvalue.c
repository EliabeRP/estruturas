#include <stdio.h>

int maxvalue(int lista[], int n) {
  if (n == 1) {
    return lista[0];
  }

  int max = maxvalue(lista+1, n-1);
  return (lista[0] > max) ? lista[0] : max;
}

int main(void) {
  int list[] = {1,2,3,4,78,109};

  printf("%d", maxvalue(list, 6));
  return 0;
}