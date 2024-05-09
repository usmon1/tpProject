#include <string>
class Error {
 public:
  std::string fence = "------------------------------------------------------------\n";
  std::string error_comment = "Errors made during typing:\n";
  std::string error_position = "Error at position ";
  std::string expected_symbol = ": Expected '";
  std::string got_symbol = "', got '";
  std::string next_line = "'\n";
  std::string number_of_errors = "Total errors: ";
  std::string generated_text = "Type the following line: ";
  std::string error_opening_file = "Error opening file: ";
  void DisplayErrors(const std::string& userInput, const std::string& original);
  uint64_t CalculateAccuracy(const std::string& userInput, const std::string& original);
};

