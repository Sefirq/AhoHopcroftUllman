//
// Created by sefir on 08.12.17.
//

#include <cstddef>
#include <cstdio>
#include <iostream>
#include "BidirectionalList.h"

BidirectionalList::BidirectionalList(int value) {
    this->previous = nullptr;
    this->next = nullptr;
    this->value = value;
    this->position = 0;
}

BidirectionalList& BidirectionalList::operator[](int idx) {
    if (idx < this->position) {
        BidirectionalList* previousRecord = this->previous;
        while (previousRecord != nullptr) {
            if (previousRecord->position == idx) {
                return *previousRecord;
            }
            previousRecord = previousRecord->previous;
        }
        delete previousRecord;
    } else if (idx > this->position) {
        BidirectionalList *nextRecord = this->next;
        while (nextRecord != nullptr) {
            if (nextRecord->position == idx) {
                return *nextRecord;
            }
            nextRecord = nextRecord->next;
        }
        delete nextRecord;
    } else {
        return *this;
    }
}
// This method inserts element after given position. If position = -1 then it's on the end of list
// If position is on in the list, throws exception
void BidirectionalList::insert(int position, int value) {
    BidirectionalList& recordToHaveNewNext = (*this)[position];
    auto *newRecord = new BidirectionalList(value);
    newRecord->previous = &recordToHaveNewNext;
    newRecord->position = recordToHaveNewNext.position + 1;
    if (recordToHaveNewNext.next != nullptr) {
        newRecord->next = recordToHaveNewNext.next;
        recordToHaveNewNext.next->previous = newRecord;
    }
    recordToHaveNewNext.next = newRecord;
    newRecord = newRecord->next;
    int i = 1;
    while (newRecord != nullptr) {
        newRecord->position = position + i++;
        newRecord = newRecord->next;
    }
}

std::string BidirectionalList::createStringRepresentationOfList() {
    BidirectionalList *iterator = this;
    std::string toBeReturned;
    toBeReturned += "[";
    while (iterator != nullptr) {
        if (iterator->next != nullptr) {
            toBeReturned += std::to_string(iterator->value) + ", ";
        }
        else {
            toBeReturned += std::to_string(iterator->value) + "]";
        }
        iterator = iterator->next;
    }
    return toBeReturned;
}

void BidirectionalList::delete_(int position) {
    BidirectionalList& recordToBeDeleted = (*this)[position];
    if (recordToBeDeleted.previous == nullptr) {
        if (recordToBeDeleted.next == nullptr) {
            printf("Cannot delete only element from list\n");
            return;
        } else {
            recordToBeDeleted.value = recordToBeDeleted.next->getValue();
            recordToBeDeleted.next = recordToBeDeleted.next->next;
        }
        return;
    } else {
        recordToBeDeleted.previous->next = recordToBeDeleted.next;
        if (recordToBeDeleted.next != nullptr) {
            recordToBeDeleted.next->previous = recordToBeDeleted.previous;
            delete &recordToBeDeleted;
        }
    }
    this->updatePositions();
}

void BidirectionalList::updatePositions() {
    BidirectionalList* currentRecord = this;
    while (currentRecord->next != nullptr) {
        if (currentRecord->next->position != currentRecord->position + 1) {
            currentRecord->next->position = currentRecord->position + 1;
        }
        currentRecord = currentRecord->next;
    }
}
