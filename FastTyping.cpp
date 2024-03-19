#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <vector>
#include <random>

class SpeedTypingTime {
 private:
  std::vector<std::string> linesToType;
  std::chrono::time_point<std::chrono::steady_clock> startTime;
  std::chrono::time_point<std::chrono::steady_clock> endTime;

 public:
  std::string startTest(const std::string& fileName) {
    std::ifstream file(fileName);
    if (file.is_open()) {
      std::string line;
      while (std::getline(file, line)) {
        linesToType.push_back(line);
      }
      file.close();

      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> dis(0, (int)linesToType.size() - 1);
      int randomIndex = dis(gen);

      std::cout << "Type the following line: " << linesToType[randomIndex] << std::endl;
      startTime = std::chrono::steady_clock::now();
      return linesToType[randomIndex];
    } else {
      std::cerr << "Error opening file: " << fileName << std::endl;
    }
    return "";
  }

  void endTest() {
    endTime = std::chrono::steady_clock::now();
  }

  int calculateSpeed(const int& typedCharacters) {
    std::chrono::duration<double> elapsed_seconds = endTime - startTime;
    double minutes = elapsed_seconds.count() / 60.0;
    int speed = static_cast<int>(typedCharacters / minutes);
    return speed;
  }

  void displayErrors(const std::string& userInput, const std::string& original) {
    int errors = 0;
    std::cout << "Errors made during typing:\n";
    for (size_t i = 0; i < original.size() && i < userInput.size(); ++i) {
      if (original[i] != userInput[i]) {
        errors++;
        std::cout << "Error at position " << i << ": Expected '" << original[i] << "', got '" << userInput[i] << "'\n";
      }
    }
    if (errors != 0) {
      std::cout << "Total errors: " << errors << std::endl;
    }
  }
};

int main() {
  SpeedTypingTime testEngine;
  std::string fileName = "text.txt"; // Assuming the file name is known

  std::cout << "Press 'Enter' to start the typing test...";

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string original = testEngine.startTest(fileName);


  std::string userInput;

  std::cout << "Start typing: ";
  std::getline(std::cin, userInput);

  testEngine.endTest();
  int speed = testEngine.calculateSpeed(original.size());

  std::cout << "Your typing speed is: " << speed << " characters per minute.\n";
  if (original.size() < userInput.size()) {
    return 0;
  }
  testEngine.displayErrors(userInput, original);

  return 0;
}
