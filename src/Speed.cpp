#include "Speed.h"
#include <iostream>

uint64_t CalculatingSpeed::CalculateSpeed(uint64_t typedCharacters) {
  std::chrono::duration<double> elapsed_seconds = end_time - start_time;
  double minutes = elapsed_seconds.count() / 60.0;
  uint64_t speed = static_cast<uint64_t>(typedCharacters / minutes);
  return speed;
}