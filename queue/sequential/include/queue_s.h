class Queue_s {
  private:
    int begin;
    int end;
    int max_size;
    int current_size;
    int *vector;

  public:
    Queue_s(int max_size);
    ~Queue_s();

    bool is_empty();
    bool is_full();

    int get_begin();
    int get_end();

    int push(int new_element);
    int remove();
};