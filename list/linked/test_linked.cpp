#include <iostream>
#include "linked.h"

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

void test_result(bool passed, const string& message) {
    if (passed)
        cout << GREEN << "[PASSOU] " << RESET << message << endl;
    else
        cout << RED << "[FALHOU] " << RESET << message << endl;
}

int main() {
    cout << CYAN << "===== TESTES DA LISTA LIGADA =====" << RESET << endl << endl;

    List_l lista(5);

    cout << BLUE << "[TESTE 1] Inserções" << RESET << endl;
    test_result(lista.insert(0, 10) == 0, "Inseriu 10 na posição 0");
    test_result(lista.insert(1, 20) == 0, "Inseriu 20 na posição 1");
    test_result(lista.insert(2, 30) == 0, "Inseriu 30 na posição 2");
    lista.print_list();

    cout << BLUE << "\n[TESTE 2] get_element()" << RESET << endl;
    test_result(lista.get_element(0) == 10, "Elemento na posição 0 é 10");
    test_result(lista.get_element(1) == 20, "Elemento na posição 1 é 20");
    test_result(lista.get_element(2) == 30, "Elemento na posição 2 é 30");
    test_result(lista.get_element(3) == -1, "Posição inválida retorna -1");

    cout << BLUE << "\n[TESTE 3] set_element()" << RESET << endl;
    test_result(lista.set_element(1, 25) == 0, "Atualizou posição 1 para 25");
    test_result(lista.get_element(1) == 25, "Verificou atualização da posição 1");

    cout << BLUE << "\n[TESTE 4] remove()" << RESET << endl;
    test_result(lista.remove(1) == 0, "Removeu elemento da posição 1");
    test_result(lista.get_element(1) == 30, "Elemento na posição 1 agora é 30");
    test_result(lista.remove(5) == -1, "Remoção em posição inválida falha");

    cout << BLUE << "\n[TESTE 5] Limites da lista" << RESET << endl;
    test_result(lista.insert(1, 40) == 0, "Inseriu 40 na posição 1");
    test_result(lista.insert(3, 50) == 0, "Inseriu 50 na posição 3");
    test_result(lista.insert(4, 60) == 0, "Inseriu 60 na posição 4");
    test_result(lista.is_full() == true, "Lista está cheia");
    test_result(lista.insert(5, 70) == -1, "Inserção falha quando cheia");

    cout << BLUE << "\n[TESTE 6] is_empty() e get_current_size()" << RESET << endl;
    test_result(lista.is_empty() == false, "Lista não está vazia");
    test_result(lista.get_current_size() == 5, "Tamanho atual é 5");

    cout << BLUE << "\n[ESTADO FINAL DA LISTA]" << RESET << endl;
    lista.print_list();

    cout << CYAN << "\n===== FIM DOS TESTES =====" << RESET << endl;
    return 0;
}
