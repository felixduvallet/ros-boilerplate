#include <gtest/gtest.h>
#include <memory>
#include <ros_boilerplate/BasicWorker.h>

namespace {

class BasicTest: public ::testing::Test {
  void SetUp() {
    worker.reset(new BasicWorker(NULL));
  }

 public:
  std::unique_ptr<BasicWorker> worker;
};

TEST_F(BasicTest, TestSomething) {
  ASSERT_EQ(true, true);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
