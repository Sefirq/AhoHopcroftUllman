//
// Created by sefir on 03.09.17.
//
#define WRONG_INDEX 29
#define NEGATIVE_INDEX 28
#define TOO_MANY_ITEMS 27
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
    void delete_(int element);
    void make_null();
    void print_list();
    void purge();

private:
    int last;
    int elements[10000];
};
#endif //AHOHOPCROFTULLMAN_LIST_H
