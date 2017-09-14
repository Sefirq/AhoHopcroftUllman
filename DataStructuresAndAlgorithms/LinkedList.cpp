//
// Created by sefir on 13.09.17.
//

#include "LinkedList.h"
LinkedList *LinkedList::end() {
    LinkedList* p = this;
    while (p->next != nullptr) {
        p = p->next;
    }
    return(p);
}

void LinkedList::insert(int element) {
    LinkedList* temp = this->next;
    this->next = new LinkedList(element);
    this->next->next = temp;
}

LinkedList::LinkedList(int element) {
    this->element = element;
    this->next = nullptr;
}

LinkedList::LinkedList() {
    this->element = _NULL;
    this->next = nullptr;
}
