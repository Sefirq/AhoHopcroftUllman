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
    void setNext(int position, int next);
    int getNext(int position);
    void setAvailable(int position);
    int getAvailable();
    void setValue(int position, int value);
    int getValue(int position);


private:
    Record* space;
    int available;
    void initialize(int size);
};


#endif //AHOHOPCROFTULLMAN_CURSORSPACE_H
