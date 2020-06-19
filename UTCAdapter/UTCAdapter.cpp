#include "UTCAdapter.h"

#include <ctime>
#include <iostream>

UTCAdapter::UTCAdapter(){
}
UTCAdapter::~UTCAdapter(){
}
std::time_t UTCAdapter::get_time(){
  std::time_t result = std::time(nullptr);
  return result;
}

void UTCAdapter::print(){
  auto tmp= this->get_time();
std::cout << std::asctime(std::localtime(&tmp));
}
