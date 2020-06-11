#include "GTKApplication.hpp"
#include <iostream>


int main (int argc, char **argv)
{
  std::cout << "C++ project\n";
  GTKApplication *app =new GTKApplication(0,argc,argv);
  int status;
  status= app->init();
  app->version();
  delete app;

  return status;
}

