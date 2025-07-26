#include <iostream>
#include <cassert>
#include <sequential.h>

using namespace std;

void test_insert() {
    List_s lista(5);

    assert(lista.insert(1, 10) == 1);
    assert(lista.insert(2, 20) == 1);
    assert(lista.insert(2, 15) == 1);
    
    assert(lista.get_element(1) == 10);
    assert(lista.get_element(2) == 15);
    assert(lista.get_element(3) == 20);
}

void test_set_get() {
    List_s lista(3);
    lista.insert(1, 5);
    lista.insert(2, 6);

    assert(lista.set_element(2, 9) == 1);
    assert(lista.get_element(2) == 9);

    assert(lista.set_element(4, 7) == -1);
}

void test_remove() {
    List_s lista(3);
    lista.insert(1, 1);
    lista.insert(2, 2);
    lista.insert(3, 3);

    assert(lista.remove(2) == 1);
    assert(lista.get_element(1) == 1);
    assert(lista.get_element(2) == 3);
    assert(lista.get_current_size() == 2);

    assert(lista.remove(10) == -1);
}

void test_full_empty() {
    List_s lista(2);
    assert(lista.is_empty());
    lista.insert(1, 11);
    assert(!lista.is_empty());
    lista.insert(2, 22);
    assert(lista.is_full());
}

int main() {
    cout << "Testando insert..." << endl;
    test_insert();
    cout << "OK\n";

    cout << "Testando set/get..." << endl;
    test_set_get();
    cout << "OK\n";

    cout << "Testando remove..." << endl;
    test_remove();
    cout << "OK\n";

    cout << "Testando full/empty..." << endl;
    test_full_empty();
    cout << "OK\n";

    cout << "✅ Todos os testes passaram!" << endl;
    return 0;
}
