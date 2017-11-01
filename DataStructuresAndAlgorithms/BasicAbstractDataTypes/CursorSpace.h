//
// Created by sefir on 02.11.17.
//

#ifndef AHOHOPCROFTULLMAN_CURSORSPACE_H
#define AHOHOPCROFTULLMAN_CURSORSPACE_H


#include "Record.h"
#include "ArrayList.h"

class CursorSpace {
public:
    explicit CursorSpace(int size);
    void print_available();

private:
    Record* space;
    ArrayList *available;
    void initialize(int size);
};


#endif //AHOHOPCROFTULLMAN_CURSORSPACE_H
