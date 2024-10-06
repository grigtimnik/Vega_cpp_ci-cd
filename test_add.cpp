#include <gtest/gtest.h>

#include "include/my_add.h"

TEST(Add, Simple) {
    EXPECT_EQ(my_add(2, 2), 4);
    EXPECT_EQ(my_add(2, 3), my_add(3, 2));
    EXPECT_EQ(my_add(-42, 3), -39);
}
