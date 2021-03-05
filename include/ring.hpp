#include <atomic>
#include <array>
#include <optional>
#include <cstdint>

template <typename T, int capacity>
class Ring {
  FRIEND_TEST(Push, Single);
  FRIEND_TEST(Push, Multiple);
  FRIEND_TEST(Push, Wrap);
  FRIEND_TEST(Pop, Single);
  FRIEND_TEST(Pop, Empty);
  FRIEND_TEST(Pop, Multiple);
  FRIEND_TEST(PushPop, FullEmpty);
  FRIEND_TEST(PushPop, FullWrapEmpty);
  std::array<T, capacity> buffer_{};
  std::atomic_uint64_t pushed{0};
  std::atomic_uint64_t popped{0};

  void push(T const& val) {
  }

  std::optional<T> pop() {
    std::optional<T> ret{};
    return ret;
  }

  
};
