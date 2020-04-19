#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "PolyOperations.h"

using namespace PolyOperations;
using namespace std;

int main(){
  vector<int> p = { 1, 3, 0, 2 }; vector<int> q = { 0, 1, 3, 4 }; vector<int> r = { 2, 2, 3, 0 };

  Polynomial test(p);

  cout<<"Test for the class: "<<endl;
  cout<<"Class initialization works "<< test <<endl;
  cout<<"getMember() works"<<endl;
  cout<<test.getMember(3)<<endl;

  return 0;
}
