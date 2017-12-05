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
    auto * cl = new CursorList(10);
    cl->insert(15, 0);
    cl->insert(12, 0);
    cl->insert(11, 0);
    cl->insert(10, 0);
    cl->insert(19, 0);
    cl->print_indices();
    cl->print_list();
    auto *cl2 = new CursorList(10);
    cl2->insert(15, 0);
    cl2->insert(12, 0);
    cl2->insert(11, 0);
    cl2->insert(10, 0);
    cl2->insert(19, 0);
    bool ass = (cl==cl2);
    if(*cl == *cl2) {
        printf("equal");
    } else {
        printf("not equal");
    }
    return 0;
}