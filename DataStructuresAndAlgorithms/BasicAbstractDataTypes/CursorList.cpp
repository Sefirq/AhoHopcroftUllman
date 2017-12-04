//
// Created by sefir on 01.11.17.
//

#include <cstdio>
#include "CursorList.h"

bool CursorList::move(int from, int to, CursorSpace* SPACE) {
    // Takes element next to "from" and places it after "to" cell.
    if (!from)
        return false;
    int next = SPACE->getNext(from);
    SPACE->setNext(from, SPACE->getNext(SPACE->getNext(from)));
    SPACE->setNext(next, SPACE->getNext(to));
    SPACE->setNext(to, next);
    return true;
}

void CursorList::insert(int value, int position, CursorSpace* SPACE) {
    if (!position) {
        int availableIndex = SPACE->getAvailable();
        printf("Available: %d\n", availableIndex);
        this->move_to_front(availableIndex, SPACE);
        SPACE->setValue(availableIndex, value);
        printf("My next is: %d\n", SPACE->getNext(availableIndex));
    } else {
        printf("one");
    }
}

void CursorList::move_to_front(int from, CursorSpace *SPACE) {
    printf("!%d!\n", this->LHead);
    int temp = this->LHead;
    this->LHead = from;
    SPACE->setAvailable(SPACE->getNext(from));
    SPACE->setNext(this->LHead, temp);
}

void CursorList::_delete(int position) {

}

CursorList::CursorList(CursorSpace *SPACE, int value) {
    int available = SPACE->getAvailable();
    this->LHead = available;
    SPACE->setValue(available, value);
    SPACE->setAvailable(SPACE->getNext(available));
    SPACE->setNext(available, 0);
    printf("@%d@\n", SPACE->getAvailable());
}


void CursorList::print_list(CursorSpace *SPACE) {
    int index = this->LHead;
    printf("[");
    do {
        printf("%d", SPACE->getValue(index));
        index = SPACE->getNext(index);
        if (index)
            printf(", ");
    } while(index != 0);
    printf("]\n");
}

void CursorList::print_indices(CursorSpace *SPACE) {
    int index = this->LHead;
    printf("[");
    do {
        printf("%d", index);
        index = SPACE->getNext(index);
        if (index)
            printf(", ");
    } while(index != 0);
    printf("]\n");
}
