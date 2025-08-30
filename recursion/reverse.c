#include <stdio.h>

void inverter(char string[], int inicio, int fim) {
  if (inicio >= fim) {
    return;
  }

  char aux = string[inicio];
  string[inicio] = string[fim];
  string[fim] = aux;

  inverter(string, inicio+1, fim-1);
}

int main(void) {
  char teste[] = "eliabe";

  inverter(teste, 0, 5);
  printf("%s", teste);
  return 0;
}