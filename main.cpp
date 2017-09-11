//
// Created by sefir on 10.09.17.
//

#include <iostream>
#include "ArrayList.h"
int main() {
    auto * a = new ArrayList();
    a->insert(10, 0);
    a->insert(11, 1);
    a->insert(12, 2);
    a->print_list();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}