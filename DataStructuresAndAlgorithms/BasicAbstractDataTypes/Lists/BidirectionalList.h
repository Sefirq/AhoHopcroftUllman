#import <string>
#ifndef AHOHOPCROFTULLMAN_DOUBLERECORD_H
#define AHOHOPCROFTULLMAN_DOUBLERECORD_H


class BidirectionalList {
public:
    BidirectionalList& operator[](int idx);
    explicit BidirectionalList(int value);
    void insert(int position, int value);
    std::string createStringRepresentationOfList();
    void delete_(int position);
    int getValue() {
        return this->value;
    }
    void printPositionAndValue() {
        printf("jksdjhfldj\n");
        printf("Value: %d, position: %d\n", this->value, this->position);
    }
    int value;

private:
    BidirectionalList *previous;
    BidirectionalList *next;
    int position;
    void updatePositions();
};


#endif //AHOHOPCROFTULLMAN_DOUBLERECORD_H
