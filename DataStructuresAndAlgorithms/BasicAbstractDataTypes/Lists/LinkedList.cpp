//
// Created by sefir on 13.09.17.
//

#include <cstdio>
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

void LinkedList::delete_(int position) {
    if (position <= 0) {
        throw WRONG_INDEX;
    }
    int index = 0;
    LinkedList* temp = this;
    while (index != position - 1) {
        temp = temp->next;
        index++;
    }
    temp->delete_();
}

void LinkedList::delete_() {
    this->next = this->next->next;
}

void LinkedList::print_list() {
    LinkedList* temp = this;
    do {
        printf("%d, ", temp->element);
        temp = temp->next;
    } while(temp->next != nullptr);
    printf("%d\n", temp->element);
}

LinkedList *LinkedList::locate(int element) {
    LinkedList* temp = this;
    while(temp != this->end()) {
        if (temp->element == element)
            return temp;
        temp = temp->next;
    }
    return temp->next;
}

void LinkedList::make_null() {
    this->next = nullptr;
}

void LinkedList::purge() {
    LinkedList* temp = this;
    LinkedList* temp2;
    while (temp->next != nullptr) {
        temp2 = temp;
        while (temp2->next->next != nullptr) {
            if (temp->element == temp2->next->element) {
                temp2->delete_();
            }
            else {
                temp2 = temp2->next;
            }
        }
        if(temp->next != nullptr) {
            if(temp->element == temp->next->element) {
                temp->delete_();
            }
            else {
                temp = temp->next;
            }
        }
    }
}
