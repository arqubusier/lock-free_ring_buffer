#include <optional>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ring.hpp"


TEST(Push, Single) {
  Ring<int, 1> r{};
  r.push(1);
  EXPECT_THAT(r.buffer_, testing::ElementsAre(1));
}

TEST(Push, Multiple) {
  Ring<int, 3> r{};
  r.push(1);
  r.push(2);
  r.push(3);
  EXPECT_THAT(r.buffer_, testing::ElementsAre(1, 2, 3));
}

TEST(Push, Wrap) {
  Ring<int, 3> r{};
  r.push(1);
  r.push(2);
  r.push(3);
  r.push(4);
  r.push(5);
  EXPECT_THAT(r.buffer_, testing::ElementsAre(4, 5, 3));
}

using RetT = std::optional<int>;

TEST(Pop, Empty) {
  Ring<int, 1> r{};
  RetT val = r.pop();
  EXPECT_FALSE(val);
}

TEST(Pop, Single) {
  Ring<int, 1> r{};
  r.push(1);
  RetT val = r.pop();
  EXPECT_EQ(val, 1);
}

TEST(PushPop, FullEmpty) {
  Ring<int, 3> r{};
  r.push(1);
  r.push(2);
  r.push(3);
  EXPECT_EQ(1, r.pop());
  EXPECT_EQ(2, r.pop());
  EXPECT_EQ(3, r.pop());
  EXPECT_FALSE(r.pop());
}

TEST(PushPop, FullWrapEmpty) {
  Ring<int, 3> r{};
  r.push(1);
  r.push(2);
  r.push(3);
  r.push(4);
  r.push(5);
  EXPECT_EQ(3, r.pop());
  EXPECT_EQ(4, r.pop());
  EXPECT_EQ(5, r.pop());
  EXPECT_FALSE(r.pop());
}
