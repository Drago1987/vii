#include"OpenSSLAdapter.h"
#include <memory>

int main (int argc, char **argv)
{
  std::unique_ptr<OpenSSLAdapter> tmp;
  tmp->print();
  return 0;
}

