//
// Created by sefir on 10.09.17.
//

#include <gtest/gtest.h>
#include "BasicAbstractDataTypes/Lists/ArrayList.h"

class ArrayListFixture : public ::testing::Test {
protected:
    void TearDown() override {
    }

    void SetUp() override {
    }
public:
    ArrayListFixture() : Test() {
        list = new ArrayList();
    }

    ~ArrayListFixture() override {
        delete list;
    }

    ArrayList * list;
};

TEST_F(ArrayListFixture, insert_into_empty_list) {
    list->insert(25, 0);
    ASSERT_EQ(list->retrieve(0), 25);
}

TEST_F(ArrayListFixture, insert_into_empty_list_negative_index) {
    try {
        list->insert(25, -2);
    }
    catch (int e) {
        ASSERT_EQ(e, NEGATIVE_INDEX);
    }
}

TEST_F(ArrayListFixture, insert_into_empty_list_too_big_index) {
    try {
        list->insert(25, 1);
    }
    catch (int e) {
        ASSERT_EQ(e, WRONG_INDEX);
    }
}

TEST_F(ArrayListFixture, insert_into_nonempty_lists_end) {
    list->insert(25, 0);
    list->insert(20, 1);
    ASSERT_EQ(list->retrieve(1), 20);
}

TEST_F(ArrayListFixture, insert_into_nonempty_list_front) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 0);
    ASSERT_EQ(list->retrieve(0), 2);
    ASSERT_EQ(list->retrieve(1), 25);
    ASSERT_EQ(list->retrieve(2), 20);
}

TEST_F(ArrayListFixture, insert_into_list_until_max_elements_on_list) {
    for (int i = 0; i < 10000; i++) {
        list->insert(i, i);
    }
    try {
        list->insert(10, 10000);
    }
    catch (int e) {
        ASSERT_EQ(e, TOO_MANY_ITEMS);
    }
}

TEST_F(ArrayListFixture, locate_element_in_nonempty_list) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 0);
    ASSERT_EQ(list->locate(25), 1);
}

TEST_F(ArrayListFixture, locate_element_not_present_in_list) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 0);
    ASSERT_EQ(list->locate(259), list->END());
}

TEST_F(ArrayListFixture, locate_element_present_twice_in_a_list) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 0);
    list->insert(25, 3);
    ASSERT_EQ(list->locate(25), 1);
}

TEST_F(ArrayListFixture, next_of_last_item) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 0);
    list->insert(25, 3);
    ASSERT_EQ(list->next(3), list->END());
}

TEST_F(ArrayListFixture, previous_of_existing_item) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 0);
    list->insert(25, 3);
    ASSERT_EQ(list->previous(3), 2);
}

TEST_F(ArrayListFixture, next_of_nonexisting_index) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 0);
    list->insert(25, 3);
    try {
        list->next(20);
    } catch (int e) {
        ASSERT_EQ(e, WRONG_INDEX);
    }
}

TEST_F(ArrayListFixture, next_of_negative_index) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 0);
    list->insert(25, 3);
    try {
        list->next(-1);
    } catch (int e) {
        ASSERT_EQ(e, NEGATIVE_INDEX);
    }
}

TEST_F(ArrayListFixture, previous_of_nonexisting_index) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 0);
    list->insert(25, 3);
    try {
        list->previous(20);
    } catch (int e) {
        ASSERT_EQ(e, WRONG_INDEX);
    }
}

TEST_F(ArrayListFixture, previous_of_first_index) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 0);
    list->insert(25, 3);
    try {
        list->previous(list->first());
    } catch (int e) {
        ASSERT_EQ(e, NEGATIVE_INDEX);
    }
}

TEST_F(ArrayListFixture, delete_first_item) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 2);
    list->insert(25, 3);
    list->delete_(0);
    ASSERT_EQ(list->retrieve(0), 20);
    ASSERT_EQ(list->retrieve(1), 2);
    ASSERT_EQ(list->retrieve(2), 25);
}

TEST_F(ArrayListFixture, delete_last_item) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 2);
    list->insert(25, 3);
    list->delete_(3);
    ASSERT_EQ(list->retrieve(0), 25);
    ASSERT_EQ(list->retrieve(1), 20);
    ASSERT_EQ(list->retrieve(2), 2);
    ASSERT_EQ(list->END(), 3);
}

TEST_F(ArrayListFixture, delete_nonexisting_item) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 2);
    list->insert(25, 3);
    try {
        list->delete_(40);
    }
    catch (int e) {
        ASSERT_EQ(e, WRONG_INDEX);
    }
}

TEST_F(ArrayListFixture, delete_negative_index) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 2);
    list->insert(25, 3);
    try {
        list->delete_(-20);
    }
    catch (int e) {
        ASSERT_EQ(e, NEGATIVE_INDEX);
    }
}

TEST_F(ArrayListFixture, purge_last_index_duplicate) {
    list->insert(25, 0);
    list->insert(20, 1);
    list->insert(2, 2);
    list->insert(25, 3);
    list->purge();
    ASSERT_EQ(list->retrieve(0), 25);
    ASSERT_EQ(list->retrieve(1), 20);
    ASSERT_EQ(list->retrieve(2), 2);
    ASSERT_EQ(list->END(), 3);
}

TEST_F(ArrayListFixture, purge_index_with_four_same_elements) {
    list->insert(25, 0);
    list->insert(25, 1);
    list->insert(25, 2);
    list->insert(25, 3);
    list->purge();
    ASSERT_EQ(list->retrieve(0), 25);
    ASSERT_EQ(list->END(), 1);
}
