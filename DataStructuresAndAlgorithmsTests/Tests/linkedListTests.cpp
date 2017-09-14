#include <gtest/gtest.h>
#include "LinkedList.h"

class LinkedListFixture : public ::testing::Test {
protected:
    void TearDown() override {
    }

    void SetUp() override {
    }
public:
    LinkedListFixture() : Test() {
        list = new LinkedList();
    }

    ~LinkedListFixture() override {
        delete list;
    }

    LinkedList* list;
};

TEST_F(LinkedListFixture, insert_into_empty_list) {
    list->insert(25);
    ASSERT_EQ(list->element, _NULL);
    ASSERT_EQ(list->next->element, 25);
}

TEST_F(LinkedListFixture, insert_three_values) {
    list->insert(25);
    list->insert(20);
    list->insert(11);
    ASSERT_EQ(list->element, _NULL);
    ASSERT_EQ(list->next->element, 11);
    ASSERT_EQ(list->next->next->element, 20);
    ASSERT_EQ(list->next->next->next->element, 25);
}

TEST_F(LinkedListFixture, end_of_one_element_list) {
    list->insert(25);
    ASSERT_EQ(list->end()->element, 25);
}

TEST_F(LinkedListFixture, end_of_more_elements_list) {
    list->insert(20);
    list->insert(25);
    list->insert(26);
    ASSERT_EQ(list->end()->element, 20);
}