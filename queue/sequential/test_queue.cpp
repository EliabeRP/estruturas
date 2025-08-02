// test_queue.cpp
#include <iostream>
#include "queue_s.h"

using namespace std;

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

void test_result(bool passed, const string& message) {
    cout << (passed ? GREEN "[PASS] " : RED "[FAIL] ") << message << RESET << endl;
}

int main() {
    Queue_s q(3);

    test_result(q.is_empty(), "Fila deve estar vazia inicialmente");

    q.push(10);
    test_result(!q.is_empty(), "Fila não deve estar vazia após push");
    test_result(q.get_begin() == 10, "get_begin deve retornar 10");
    test_result(q.get_end() == 10, "get_end deve retornar 10");

    q.push(20);
    q.push(30);
    test_result(q.is_full(), "Fila deve estar cheia após 3 inserções");

    int res = q.push(40);
    test_result(res == -1, "push em fila cheia deve retornar -1");

    q.remove();
    test_result(q.get_begin() == 20, "Após remover, get_begin deve retornar 20");

    q.remove();
    q.remove();
    test_result(q.is_empty(), "Fila deve estar vazia após remover todos");

    res = q.remove();
    test_result(res == -1, "remove em fila vazia deve retornar -1");

    return 0;
}
