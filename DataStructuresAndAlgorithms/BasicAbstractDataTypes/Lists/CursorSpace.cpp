//
// Created by sefir on 02.11.17.
//

#include "CursorSpace.h"

CursorSpace::CursorSpace(int size) {
    this->space = new Record[size];
    this->available = 1;
    this->initialize(size);
}

void CursorSpace::initialize(int size) {
    for (int i = 1; i < size - 1; i++) {
        this->space[i].setNext(i+1);
    }
}

void CursorSpace::setNext(int position, int next) {
    this->space[position].setNext(next);
}

int CursorSpace::getNext(int position) {
    return this->space[position].getNext();
}

int CursorSpace::getAvailable() {
    return this->available;
}

void CursorSpace::setValue(int position, int value) {
    this->space[position].setValue(value);
}

int CursorSpace::getValue(int position) {
    return this->space[position].getValue();
}

void CursorSpace::setAvailable(int position) {
    this->available = position;
}
