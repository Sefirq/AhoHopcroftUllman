#include <gtest/gtest.h>
#include "BasicAbstractDataTypes/Lists/LinkedList.h"

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

TEST_F(LinkedListFixture, delete_specific_index) {
    list->insert(20);
    list->insert(25);
    list->insert(26);
    list->delete_(1);
    ASSERT_EQ(list->next->element, 25);
    ASSERT_EQ(list->next->next->element, 20);
}

TEST_F(LinkedListFixture, delete_last_index) {
    list->insert(20);
    list->insert(25);
    list->insert(26);
    list->delete_(3);
    ASSERT_EQ(list->next->element, 26);
    ASSERT_EQ(list->next->next->element, 25);
}


TEST_F(LinkedListFixture, locate_first_element) {
    list->insert(20);
    list->insert(25);
    list->insert(26);
    LinkedList* a = list->locate(26);
    ASSERT_EQ(list->next, a);
}


TEST_F(LinkedListFixture, locate_nonexisting_element) {
    list->insert(20);
    list->insert(25);
    list->insert(26);
    LinkedList* a = list->locate(26999);
    ASSERT_EQ(nullptr, a);
}

TEST_F(LinkedListFixture, purge_list_with_four_duplicates) {
    list->insert(20);
    list->insert(20);
    list->insert(20);
    list->insert(20);
    list->purge();
    list->print_list();
}