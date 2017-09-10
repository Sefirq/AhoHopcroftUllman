//
// Created by sefir on 03.09.17.
//

#include <cstdio>
#include "ArrayList.h"

int ArrayList::END() {
    return this->last + 1;
}

ArrayList::ArrayList() {
    this->last = -1;
}

void ArrayList::insert(int element, int position) {
    if (END() >= max_elements) {
        throw TOO_MANY_ITEMS;
    }
    if (position > END()) {
        throw WRONG_INDEX;
    }
    else if (position < 0) {
        throw NEGATIVE_INDEX;
    }
    else if (position == END()) {
        this->elements[END()] = element;
        this->last++;
    }
    else {
        this->shift(position);
        this->elements[position] = element;
        this->last++;
    }
}

void ArrayList::shift(int position) {
    int iter = last;
     do {
        elements[next(iter)] = elements[iter];
         try{
             iter = previous(iter);
         }
         catch (int e) {
             return;
         }
    } while (iter != position -1);
}

int ArrayList::retrieve(int position) {
    return this->elements[position];
}

int ArrayList::first() {
    return 0;
}

int ArrayList::next(int position) {
    if (position == last){
        return END();
    }
    else if (position >= END()) {
        throw WRONG_INDEX;
    }
    else if (position < 0) {
        throw NEGATIVE_INDEX;
    }
    return position + 1;
}

int ArrayList::previous(int position) {
    if (position <= first()) {
        throw NEGATIVE_INDEX;
    }
    else if (position > END()) {
        throw WRONG_INDEX;
    }
    return position - 1;
}

int ArrayList::locate(int element) {
    int iter = first();
    while (iter != END()) {
        if (elements[iter] == element) {
            return iter;
        }
        iter = next(iter);
    }
    return iter;
}
