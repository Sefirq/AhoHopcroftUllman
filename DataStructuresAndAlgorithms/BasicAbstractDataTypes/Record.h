//
// Created by sefir on 01.11.17.
//

#ifndef AHOHOPCROFTULLMAN_RECORD_H
#define AHOHOPCROFTULLMAN_RECORD_H


class Record {
public:
    explicit Record(int value);
    Record();
private:
    int value;
    int next;
};


#endif //AHOHOPCROFTULLMAN_RECORD_H
