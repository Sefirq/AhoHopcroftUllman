//
// Created by sefir on 13.09.17.
//

#ifndef AHOHOPCROFTULLMAN_LINKEDLIST_H
#define AHOHOPCROFTULLMAN_LINKEDLIST_H
#define _NULL (-2147000000)

class LinkedList {
public:
    LinkedList();
    explicit LinkedList(int element);
    LinkedList* end();
    void insert(int element);
    int element;
    LinkedList* next;
private:

};


#endif //AHOHOPCROFTULLMAN_LINKEDLIST_H
