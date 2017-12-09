//
// Created by sefir on 01.11.17.
//

#include "Record.h"

Record::Record(int value) {
    this->value = value;
    this->next = 0;
}

Record::Record() {
    this->value = 0;
    this->next = 0;
}

void Record::setNext(int next) {
    this->next = next;
}

void Record::setValue(int value) {
    this->value = value;
}

int Record::getNext() {
    return this->next;
}

int Record::getValue() {
    return this->value;
}
