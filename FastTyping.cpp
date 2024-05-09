#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include "ErrorStatistics.h"
#include "Speed.h"
#include "UserRequest.h"


class FastTyping : public Error, public Speed {
 public:
  std::string GetRandomText(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
      std::string line;
      while (std::getline(file, line)) {
        text_to_type.push_back(line);
      }
      file.close();

      uint64_t random_index = Randomizer();
      std::cout <<fence;
      std::cout << generated_text << text_to_type[random_index] << std::endl;
      start_time = std::chrono::steady_clock::now();
      return text_to_type[random_index];
    } else {
      std::cerr << error_opening_file << filename << std::endl;
    }
    return "";
  }

  uint64_t Randomizer() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, (int)text_to_type.size() - 1);
    uint64_t random_index = dis(gen);
    return random_index;
  }

  void GetCurrentTime() {
    end_time = std::chrono::steady_clock::now();
  }
 private:
  std::vector<std::string> text_to_type;
};

void RunProgram(FastTyping& testEngine, const std::string& filename,  std::string& userInput) {
  // Ваш код для запуска программы
  std::string fence = "------------------------------------------------------------\n";
  std::string excess_characters = "Error: You typed more characters than the original line.\n";
  std::string speed_comment = "Your typing speed is: ";
  std::string per_minute = " characters per minute.\n";
  std::string accuracy_comment = "Your typing accuracy is: ";
  std::string percentage = "%.\n";
  std::cout <<fence;
  Request::StartRequest();
  std::string original = testEngine.GetRandomText(filename);
  std::cout <<fence;
  Request::TypingRequest(userInput);

  testEngine.GetCurrentTime();
  uint64_t speed = testEngine.CalculateSpeed(original.size());
  uint64_t accuracy = testEngine.CalculateAccuracy(userInput, original);


  if (original.size() < userInput.size()) {
    std::cout <<fence;
    std::cout << excess_characters;
  } else {
    testEngine.DisplayErrors(userInput, original);

    std::cout << speed_comment << speed << per_minute;
    std::cout << accuracy_comment << accuracy << percentage;
    std::cout << fence;
  }
  // Запрос на нажатие клавиши Enter для продолжения или 'q' для завершения цикла
  Request::RestartRequest();
}
int main() {
  FastTyping testEngine;
  std::string filename = "Dictionary.txt";
  std::string userInput;
  while (true) {
    RunProgram(testEngine, filename, userInput);
  }
}
