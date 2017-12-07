#include <gtest/gtest.h>
#include "BasicAbstractDataTypes/CursorList.h"

class CursorListFixture : public ::testing::Test {
protected:
    void TearDown() override {
    }

    void SetUp() override {
    }
public:
    CursorListFixture() : Test() {
        list->initialize_SPACE();
        list = new CursorList(5);
    }

    ~CursorListFixture() override {
        delete list;
    }

    CursorList* list;
};

TEST_F(CursorListFixture, test_deleting_middle) {
    printf("\n");
    printf("\n");
    printf("\n");
    list->insert(55, 0);
    list->insert(60, 0);
    list->_delete(3);
    auto list2 = new CursorList(5);
    list2->insert(60, 0);
    ASSERT_TRUE(*list == *list2);
}

TEST_F(CursorListFixture, test_equality_operator_true) {
    auto *list2 = new CursorList(5);
    list->insert(55, 0);
    list2->insert(55, 0);
    ASSERT_TRUE(*list == *list2);
}

TEST_F(CursorListFixture, test_equality_operator_false) {
    auto *list2 = new CursorList(5);
    list->insert(55, 0);
    list2->insert(559, 0);
    ASSERT_FALSE(*list == *list2);
}

TEST_F(CursorListFixture, test_equality_operator_false_first_longer) {
    auto *list2 = new CursorList(5);
    list->insert(55, 0);
    list->insert(55, 0);
    list->insert(55, 0);
    list->insert(55, 0);
    list2->insert(559, 0);
    ASSERT_FALSE(*list == *list2);
}

TEST_F(CursorListFixture, test_equality_operator_false_second_longer) {
    auto *list2 = new CursorList(5);
    list->insert(55, 0);
    list2->insert(559, 0);
    list2->insert(550, 0);
    list2->insert(59, 0);
    list2->insert(590, 0);
    list2->insert(102, 0);
    ASSERT_FALSE(*list == *list2);
}

TEST_F(CursorListFixture, test_deleting_first) {
    list->insert(55, 0);
    list->_delete(0);
    auto list2 = new CursorList(5);
    ASSERT_TRUE(*list == *list2);
}

TEST_F(CursorListFixture, test_deleting_not_first) {
    list->insert(55, 0);
    list->_delete(30);
    auto list2 = new CursorList(55);
    ASSERT_TRUE(*list == *list2);
}

TEST_F(CursorListFixture, test_deleting_from_two_lists) {
    list->insert(55, 0);
//    list->_delete(30);
    auto list2 = new CursorList(5);
    list2->insert(55, 31);
    list2->_delete(31);
    list->_delete(0);
    ASSERT_TRUE(*list == *list2);
}

