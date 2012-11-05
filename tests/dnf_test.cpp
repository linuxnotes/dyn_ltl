#include <stdio.h>
#include <dnf.h>
#include <iostream>


int main(int argc, char * argv[]) {
  Dnf * t_dnf;
  t_dnf = new Dnf(10);
  t_dnf->setState(5);
  t_dnf->setState(6);
  std::string result = t_dnf->toString();
  std::cout << result;
  return 0;
}
