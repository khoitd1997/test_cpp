#include <gtest/gtest.h>

int targetFunc(int num) { return num + 5; }

class ModuleTest : public ::testing::Test {
protected:
  void SetUp() override { someInt = 5; }

  int someInt;

  // void TearDown() override {}
};

TEST_F(ModuleTest, TargetFuncTest) { EXPECT_EQ(10, targetFunc(someInt)); }
TEST_F(ModuleTest, TargetWrongFuncTest) { EXPECT_EQ(11, targetFunc(someInt)); }