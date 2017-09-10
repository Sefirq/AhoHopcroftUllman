//
// Created by sefir on 03.09.17.
//
const int max_elements = 10000;
const int WRONG_INDEX = 29;
const int NEGATIVE_INDEX = 28;
const int TOO_MANY_ITEMS = 27;
#ifndef AHOHOPCROFTULLMAN_LIST_H
#define AHOHOPCROFTULLMAN_LIST_H
class ArrayList
{
public:
    int END();
    ArrayList();
    void insert(int element, int position);
    void shift(int position);
    int retrieve(int position);
    int first();
    int next(int position);
    int previous(int position);
    int locate(int element);

private:
    int last;
    int elements[max_elements];
};
#endif //AHOHOPCROFTULLMAN_LIST_H
