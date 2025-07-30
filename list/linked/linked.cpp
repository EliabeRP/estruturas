#include <iostream>
#include "linked.h"

using namespace std;

List_l::List_l(int max_size) {
  this->max_size = max_size;
  this->current_size = 0;
  this->head = nullptr;
}

List_l::~List_l() {
  No* current_element = head;
  while (current_element != nullptr) {
    No* temp = current_element;
    current_element = current_element->next;
    delete temp;
  }
}

int List_l::is_empty() {
  return this->current_size == 0;
}

int List_l::is_full() {
  return this->current_size == this->max_size;
}

int List_l::get_current_size() {
  return this->current_size;
}

int List_l::get_element(int pos) {
  if (this->is_empty() || pos < 0 || pos >= current_size) return -1;

  No* current_element = this->head;
  while (pos--) {
    current_element = current_element->next;
  }
  return current_element->data;
}

int List_l::set_begin(int value) {
  if (this->head == nullptr) return -1;
  this->head->data = value;
  return 0;
}


int List_l::set_mid(int pos, int value) {
  if (this->is_empty() || pos < 0 || pos >= current_size) return -1;

  No* current_element = this->head;
  while (pos--) {
    current_element = current_element->next;
  }
  current_element->data = value;
  return 0;
}

int List_l::set_element(int pos, int value) {
  if (this->is_empty() || pos < 0 || pos >= current_size) return -1;

  if (pos == 0) return set_begin(value);
  return set_mid(pos, value);
}


int List_l::insert(int pos, int value) {
  if (is_full()) return -1;

  if (pos == 0) return insert_begin(value);
  return insert_mid(pos, value);
}

int List_l::insert_begin(int value) {
  No* new_element = new No();
  new_element->data = value;
  new_element->next = head;
  head = new_element;
  this->current_size++;
  return 0;
}

int List_l::insert_mid(int pos, int value) {
  if (pos < 1 || pos > current_size) return -1;

  No* current_element = this->head;
  for (int i = 0; i < pos - 1; i++) {
    current_element = current_element->next;
  }

  No* new_element = new No();
  new_element->data = value;
  new_element->next = current_element->next;
  current_element->next = new_element;
  this->current_size++;
  return 0;
}

int List_l::remove(int pos) {
  if (is_empty() || pos < 0 || pos >= current_size)
    return -1;

  No* temp;

  if (pos == 0) {
    temp = head;
    head = head->next;
    delete temp;
  } else {
    No* current_element = head;
    for (int i = 0; i < pos - 1; i++) {
      current_element = current_element->next;
    }
    temp = current_element->next;
    current_element->next = temp->next;
    delete temp;
  }

  current_size--;
  return 0;
}


void List_l::print_list() {
  if (is_empty()) {
    cout << "The list is empty." << endl;
    return;
  }

  No* current_element = this->head;
  while (current_element != nullptr) {
    cout << current_element->data << " ";
    current_element = current_element->next;
  }
  cout << endl;
}
