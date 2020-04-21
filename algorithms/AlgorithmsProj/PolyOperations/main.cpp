#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "PolyOperations.h"
#include "tests.cpp"

//tests for the arithmetical operations is imported from tests.cpp file

using namespace PolyOperations;
using namespace std;
int main(){
  test_constructor();
  test_clean();
  test_addition();
  test_subtraction();
  test_mult();
  test_division();
  test_bool();
  return 0;
}
