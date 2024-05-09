#include <iostream>
#include <string>
class Request {
 public:
  static void StartRequest();
  static void TypingRequest(std::string& userInput);
  static void RestartRequest();
};