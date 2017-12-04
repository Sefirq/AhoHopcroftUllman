//
// Created by sefir on 01.11.17.
//
#ifndef AHOHOPCROFTULLMAN_CURSORLIST_H
#define AHOHOPCROFTULLMAN_CURSORLIST_H


#include "CursorSpace.h"

class CursorList {
public:
    CursorList(CursorSpace *SPACE, int value);
    void insert(int value, int position, CursorSpace *SPACE);
    void _delete(int position);
    bool move(int from, int to, CursorSpace* SPACE);
    void move_to_front(int from, CursorSpace *SPACE);
    void print_list(CursorSpace *SPACE);
    void print_indices(CursorSpace *SPACE);
private:
    int LHead;
};


#endif //AHOHOPCROFTULLMAN_CURSORLIST_H
