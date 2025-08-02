#include <iostream>
#include <queue_s.h>

using namespace std;

Queue_s::Queue_s(int max_size) {
  this->begin = 0;
  this->end = -1;
  this->max_size = max_size;
  this->current_size = 0;
  this->vector = new int[max_size];
}

Queue_s::~Queue_s() {}

bool Queue_s::is_empty() {
  return this->current_size == 0;
}

bool Queue_s::is_full() {
  return this->current_size == this->max_size;
}

int Queue_s::get_begin() {
  return this->vector[this->begin];
}

int Queue_s::get_end() {
  return this->vector[this->end];
}

int Queue_s::push(int new_element) {
  if (this->is_full()) return -1;

  this->end = (this->end + 1) % this->max_size;
  this->vector[this->end] = new_element;
  this->current_size++;
  return 0;
}

int Queue_s::remove() {
  if (this->is_empty()) return -1;

  this->begin = (this->begin + 1) % this->max_size;
  this->current_size--;
  return 0;
}