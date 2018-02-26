//
// Created by sefir on 10.09.17.
//

#include <iostream>
#include <BasicAbstractDataTypes/Lists/CursorSpace.h>
#include "BasicAbstractDataTypes/Lists/CursorList.h"
#include "BasicAbstractDataTypes/Lists/BidirectionalList.h"
#include "BasicAbstractDataTypes/Lists/LinkedList.h"

int main() {
    auto * xd = new BidirectionalList(11);
    std::cout<< xd->createStringRepresentationOfList()<<std::endl;
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
    bool ass = true;
    if(*cl == *cl2) {
        printf("equal\n");
    } else {
        printf("not equal\n");
    }
    int input;
    int vlu;
    while(ass) {
        std::cin.clear();
        std::cin >> input;
        printf("got it %d\n", input);
        switch(input) {
            case -2:
                ass = !ass;
                break;
            case -3:
                cl->print_indices();
                break;
            case -4:
                cl->print_list();
                break;
            default:
                printf("Podaj wartosc do wpisania\n");
                std::cin.clear();
                std::cin >> vlu;
                printf("%d\n", vlu);
                cl->insert(vlu, input);
                break;
        }
    }
    return 0;
}