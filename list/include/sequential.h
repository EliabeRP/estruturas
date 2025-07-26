class List_s {
private:
    int max_size;
    int current_size;
    int *arr;

    void insert_end(int value);

    void insert_mid(int pos, int value);

public:
    List_s(int max_size);

    ~List_s();

    bool is_empty();

    bool is_full();

    int get_current_size();

    int get_max_size();

    int get_element(int pos);

    int set_element(int pos, int value);

    int insert(int pos, int value);

    int remove(int pos);
};

