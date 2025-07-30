#ifndef LINKED_H
#define LINKED_H

struct No {
  int data;
  No* next;
};

class List_l {
private:
  No* head;
  int max_size;
  int current_size;

  int set_begin(int value);
  int set_mid(int pos, int value);
  int insert_begin(int value);
  int insert_mid(int pos, int value);

public:
  List_l(int max_size);
  ~List_l();

  int is_empty();
  int is_full();
  int get_current_size();
  int get_element(int pos);
  int set_element(int pos, int value);
  int insert(int pos, int value);
  int remove(int pos);
  void print_list();
};

#endif
