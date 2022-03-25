#include "bt_node.h"
#include "Instrumentor.h"
#include <gtest/gtest.h>

using namespace util;

TEST(BTNode, TakeUserInputTest){
  BTNode<int> *root = MakeTreeLevelwise();
  PrintTreeLevelwise(root);
  EXPECT_TRUE(root != nullptr);
}

