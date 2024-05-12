#include "ErrorStatistics.h"
#include <iostream>

void Error::DisplayErrors(const std::string& userInput, const std::string& original) {
  uint64_t errors = 0;
  std::cout <<fence;
  std::cout << error_comment;
  std::cout <<fence;
  for (size_t i = 0; i < original.size() && i < userInput.size(); ++i) {
    if (original[i] != userInput[i]) {
      ++errors;
      std::cout << error_position << i << expected_symbol << original[i] << got_symbol << userInput[i] << next_line;
    }
  }
  if (errors != 0) {
    std::cout <<fence;
    std::cout << number_of_errors << errors << std::endl;
  }
}
uint64_t Error::CalculateAccuracy(const std::string& userInput, const std::string& original) {
  uint64_t matching_characters = 0;
  for (size_t i = 0; i < original.size() && i < userInput.size(); ++i) {
    if (original[i] == userInput[i]) {
      ++matching_characters;
    }
  }

  double accuracy = static_cast<double>(matching_characters) / original.size() * 100.0;
  return static_cast<uint64_t>(accuracy);
}