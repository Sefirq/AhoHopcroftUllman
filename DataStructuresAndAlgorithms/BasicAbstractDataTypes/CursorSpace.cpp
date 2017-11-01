//
// Created by sefir on 02.11.17.
//

#include "CursorSpace.h"

CursorSpace::CursorSpace(int size) {
    this->space = new Record[size];
    this->available = new ArrayList();
    this->initialize(size);
}

void CursorSpace::print_available() {
    this->available->print_list();
}

void CursorSpace::initialize(int size) {
    for (int i = 0; i < size; i++) {
        this->available->insert(i, this->available->END());
    }
}
