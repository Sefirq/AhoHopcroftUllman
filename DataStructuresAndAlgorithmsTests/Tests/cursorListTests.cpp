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
        list = new CursorList(5);
    }

    ~CursorListFixture() override {
        delete list;
    }

    CursorList* list;
};

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