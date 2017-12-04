//
// Created by sefir on 10.09.17.
//

#include <iostream>
#include <BasicAbstractDataTypes/CursorSpace.h>
#include "BasicAbstractDataTypes/CursorList.h"
#include "BasicAbstractDataTypes/ArrayList.h"
#include "BasicAbstractDataTypes/LinkedList.h"

int main() {
    auto * a = new ArrayList();
    a->insert(10, 0);
    a->insert(11, 1);
    a->insert(12, 2);
    a->print_list();
    std::cout << "Hello, World!" << std::endl;
    auto * b = new LinkedList();
    b->insert(10);
    b->insert(9);
    b->insert(8);
    std::cout << "XD" << std::endl;
    b->print_list();
    auto * c = new CursorSpace(10000);
    printf("###%d###\n", c->getAvailable());
    printf("###%d###\n", c->getNext(c->getAvailable()));
    auto * cl = new CursorList(c, 10);
    printf("###%d###\n", c->getAvailable());
    printf("###%d###\n", c->getNext(c->getAvailable()));
    cl->insert(15, 0, c);
    cl->insert(12, 0, c);
    cl->insert(11, 0, c);
    cl->insert(10, 0, c);
    cl->insert(19, 0, c);
    cl->print_indices(c);
    cl->print_list(c);
    return 0;
}