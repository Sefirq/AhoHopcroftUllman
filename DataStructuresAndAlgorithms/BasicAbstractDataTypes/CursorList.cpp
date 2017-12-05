//
// Created by sefir on 01.11.17.
//

#include <cstdio>
#include "CursorList.h"

CursorSpace *CursorList::SPACE = new CursorSpace(100000);


bool CursorList::move(int from, int to) {
    // Takes element next to "from" and places it after "to" cell.
    if (!from)
        return false;
    int next = this->SPACE->getNext(from);
    this->SPACE->setNext(from, this->SPACE->getNext(SPACE->getNext(from)));
    this->SPACE->setNext(next, this->SPACE->getNext(to));
    this->SPACE->setNext(to, next);
    return true;
}

void CursorList::insert(int value, int position) {
    if (!position) {
        int availableIndex = this->SPACE->getAvailable();
        this->move_to_front(availableIndex);
        this->SPACE->setValue(availableIndex, value);
    } else {
        printf("one");
    }
}

void CursorList::move_to_front(int from) {
    int temp = this->LHead;
    this->LHead = from;
    this->SPACE->setAvailable(SPACE->getNext(from));
    this->SPACE->setNext(this->LHead, temp);
}

void CursorList::_delete(int position) {

}

CursorList::CursorList(int value) {
    int available = this->SPACE->getAvailable();
    this->LHead = available;
    this->SPACE->setValue(available, value);
    this->SPACE->setAvailable(SPACE->getNext(available));
    this->SPACE->setNext(available, 0);
}


void CursorList::print_list() {
    int index = this->LHead;
    printf("[");
    do {
        printf("%d", this->SPACE->getValue(index));
        index = this->SPACE->getNext(index);
        if (index)
            printf(", ");
    } while(index != 0);
    printf("]\n");
}

void CursorList::print_indices() {
    int index = this->LHead;
    printf("[");
    do {
        printf("%d", index);
        index = this->SPACE->getNext(index);
        if (index)
            printf(", ");
    } while(index != 0);
    printf("]\n");
}

bool CursorList::operator==(const CursorList& other_list) {
    int this_idx = this->LHead;
    int other_idx = other_list.LHead;
    while(this_idx != 0 and other_idx != 0) {
        if (this->SPACE->getValue(this_idx) != this->SPACE->getValue(other_idx)) {
            return false;
        }
        this_idx = this->SPACE->getNext(this_idx);
        other_idx = this->SPACE->getNext(other_idx);
    }
    return true;
}

