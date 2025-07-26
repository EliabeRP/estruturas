#include <iostream>
#include <sequential.h>

using namespace std;

void List_s::insert_end(int value) {
    this->arr[this->current_size] = value;
    this->current_size++;
}

void List_s::insert_mid(int pos, int value) {
    int index = pos - 1;
    for (int i = this->current_size; i > index; i--) {
        this->arr[i] = this->arr[i - 1];
    }
    this->arr[index] = value;
    this->current_size++;
}

List_s::List_s(int max_size) {
    this->max_size = max_size;
    this->arr = new int[max_size];
    this->current_size = 0;
}

List_s::~List_s() {
    delete[] arr;
}

bool List_s::is_empty() {
    return this->current_size == 0;
}

bool List_s::is_full() {
    return this->current_size == this->max_size;
}

int List_s::get_current_size() {
    return this->current_size;
}

int List_s::get_max_size() {
    return this->max_size;
}

int List_s::get_element(int pos) {
    int index = pos - 1;
    if (index >= 0 && index < this->current_size) {
        return this->arr[index];
    }
    return -1;
}

int List_s::set_element(int pos, int value) {
    int index = pos - 1;
    if (index >= 0 && index < this->current_size) {
        this->arr[index] = value;
        return 1;
    }
    return -1;
}

int List_s::insert(int pos, int value) {
    if (is_full()) return -1;

    int index = pos - 1;

    if (pos == this->current_size + 1) {
        insert_end(value);
        return 1;
    }

    if (index >= 0 && index < this->current_size) {
        insert_mid(pos, value);
        return 1;
    }

    return -1;
}

int List_s::remove(int pos) {
    int index = pos - 1;
    if (index < this->current_size && index >= 0) {
        for (int i = index; i < this->current_size - 1; i++) {
            this->arr[i] = this->arr[i + 1];
        }
        this->current_size--;
        return 1;
    }
    return -1;
}
