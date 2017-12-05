//
// Created by sefir on 01.11.17.
//
#ifndef AHOHOPCROFTULLMAN_CURSORLIST_H
#define AHOHOPCROFTULLMAN_CURSORLIST_H


#include "CursorSpace.h"

class CursorList {
public:
    explicit CursorList(int value);
    void insert(int value, int position);
    void _delete(int position);
    bool move(int from, int to);
    void move_to_front(int from);
    void print_list();
    void print_indices();
    bool operator==(const CursorList& other_list);
private:
    static CursorSpace *SPACE;
    int LHead;
};


#endif //AHOHOPCROFTULLMAN_CURSORLIST_H
