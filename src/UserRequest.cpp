
#include <limits>
#include "UserRequest.h"

void Request::StartRequest() {
  std::string start = "Press 'Enter' to start the typing test";
  std::cout << start;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << std::endl;
}

void Request::TypingRequest(std::string& userInput) {
  std::string typing = "Start typing: ";
  std::cout << typing;
  std::getline(std::cin, userInput);
}

void Request::RestartRequest() {
  std::string restart = "Press 'Enter' to retest or 'q' to end: ";
  std::string programme_completed = "Program completed";
  std::string q_little = "q";
  std::string q_big = "Q";
  std::cout << restart;

  std::string key;
  std::getline(std::cin, key);
  //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << std::endl;
  // Проверка нажатой клавиши для определения продолжения или завершения цикла
  if (key == q_little || key == q_big) {
    std::cout << programme_completed << std::endl;
    exit(0);
  }
}
