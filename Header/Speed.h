#include <string>
#include <chrono>

class CalculatingSpeed {
 public:
  uint64_t CalculateSpeed(uint64_t typedCharacters);
 protected:
  std::chrono::time_point<std::chrono::steady_clock> start_time;
  std::chrono::time_point<std::chrono::steady_clock> end_time;
};
