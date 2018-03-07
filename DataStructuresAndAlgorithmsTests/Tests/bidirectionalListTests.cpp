#include <gtest/gtest.h>
#include "BasicAbstractDataTypes/Lists/BidirectionalList.h"

class BidirectionalListFixture : public ::testing::Test {
protected:
    void TearDown() override {
    }

    void SetUp() override {
    }
public:
    BidirectionalListFixture() : Test() {
        list = new BidirectionalList(10);
    }

    ~BidirectionalListFixture() override {
        delete list;
    }
    BidirectionalList* list;

};

TEST_F(BidirectionalListFixture, test_printing_one_element_list) {
    printf("\n");
    printf("\n");
    printf("\n");
    ASSERT_TRUE(list->createStringRepresentationOfList() == "[10]");
}

TEST_F(BidirectionalListFixture, test_printing_more_elements_list) {
    list->insert(0, 11);
    printf("\n");
    printf("\n");
    printf("\n");
    ASSERT_TRUE(list->createStringRepresentationOfList() == "[10, 11]");
}

TEST_F(BidirectionalListFixture, test_inserting_elements) {
    list->insert(0, 11);
    list->insert(0, 13);
    printf("\n");
    printf("\n");
    printf("\n");
    ASSERT_TRUE(list->createStringRepresentationOfList() == "[10, 13, 11]");
}

TEST_F(BidirectionalListFixture, test_accessing_first_element) {
    BidirectionalList test = (*list)[0];
    printf("\n");
    printf("\n");
    printf("\n");
    ASSERT_TRUE(test.getValue() == 10);
}

TEST_F(BidirectionalListFixture, test_accessing_second_element) {
    list->insert(0, 12);
    BidirectionalList test = (*list)[1];
    printf("\n");
    printf("\n");
    printf("\n");
    ASSERT_TRUE(test.getValue() == 12);
}

TEST_F(BidirectionalListFixture, test_inserting_behind_the_second_position) {
    list->insert(0, 12);
    list->insert(1, 13);
    BidirectionalList test = (*list)[2];
    printf("\n");
    printf("\n");
    printf("\n");
    ASSERT_TRUE(test.getValue() == 13);
}

TEST_F(BidirectionalListFixture, test_removing_first_element) {
    list->insert(0, 12);
    list->insert(1, 13);
    list->printPositionAndValue();
    std::cout << list->createStringRepresentationOfList() << std::endl;
    list->delete_(0);
    std::cout << list->createStringRepresentationOfList() << std::endl;
    printf("\n");
    printf("\n");
    printf("\n");
    ASSERT_TRUE(list->createStringRepresentationOfList() == "[12, 13]");
}

TEST_F(BidirectionalListFixture, test_removing_second_element) {
    list->insert(0, 12);
    list->insert(1, 13);
    list->printPositionAndValue();
    std::cout << list->createStringRepresentationOfList() << std::endl;
    list->delete_(1);
    std::cout << list->createStringRepresentationOfList() << std::endl;
    printf("\n");
    printf("\n");
    printf("\n");
    ASSERT_TRUE(list->createStringRepresentationOfList() == "[10, 13]");
}

TEST_F(BidirectionalListFixture, test_removing_two_last_elements) {
    list->insert(0, 12);
    list->insert(1, 13);
    list->delete_(1);
    list->delete_(1);
    printf("\n");
    printf("\n");
    printf("\n");
    ASSERT_TRUE(list->createStringRepresentationOfList() == "[10]");
}

TEST_F(BidirectionalListFixture, test_removing_wo_last_elements) {
    list->insert(0, 12);
    list->insert(1, 13);
    list->delete_(1);
    list->delete_(1);
    list->delete_(0);
    printf("\n");
    printf("\n");
    printf("\n");
    std::cout<<list->createStringRepresentationOfList()<<std::endl;
    ASSERT_TRUE(list->createStringRepresentationOfList() == "[10]");
}