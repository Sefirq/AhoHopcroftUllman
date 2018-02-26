#import <string>
#ifndef AHOHOPCROFTULLMAN_DOUBLERECORD_H
#define AHOHOPCROFTULLMAN_DOUBLERECORD_H


class BidirectionalList {
public:
    BidirectionalList& operator[](int idx);
    explicit BidirectionalList(int value);
    void insert(int position, int value);
    std::string createStringRepresentationOfList();
    int getValue() {
        return this->value;
    }
    void printPositionAndValue() {
        printf("Value: %d, position: %d\n", this->value, this->position);
    }

private:
    int value;
    BidirectionalList *previous;
    BidirectionalList *next;
    int position;
};


#endif //AHOHOPCROFTULLMAN_DOUBLERECORD_H
