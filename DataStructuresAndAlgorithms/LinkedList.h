//
// Created by sefir on 13.09.17.
//

#ifndef AHOHOPCROFTULLMAN_LINKEDLIST_H
#define AHOHOPCROFTULLMAN_LINKEDLIST_H
#define _NULL (-2147000000)
#define WRONG_INDEX 29

class LinkedList {
public:
    LinkedList();
    explicit LinkedList(int element);
    LinkedList* end();
    void insert(int element);
    void delete_(int position);
    void delete_();
    void print_list();
    LinkedList* locate(int element);
    void make_null();
    void purge();
    int element;
    LinkedList* next;
private:

};


#endif //AHOHOPCROFTULLMAN_LINKEDLIST_H
