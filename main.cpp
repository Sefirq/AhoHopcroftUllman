//
// Created by sefir on 10.09.17.
//

#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"

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
    return 0;
}