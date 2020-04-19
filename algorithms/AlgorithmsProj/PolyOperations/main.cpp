#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "PolyOperations.h"

using namespace PolyOperations;
using namespace std;

int main(){
  vector<double> p = { 1, 0, 0, 2, 3 }; vector<double> q = { 0, -4, 3, 3 }; vector<double> r = { 2, 2, 3, 0 };

  Polynomial poly_p(p);
  Polynomial poly_q(q);
  cout<<"Test for the class: "<<endl;
  cout<<"Class initialization works "<< poly_q <<endl;
  cout<<"degree: "<<poly_p.max_degree<<endl;
  cout<<"getMember() works"<<endl;
  cout<<poly_p.getMember(3)<<poly_q.getMember(3)<<endl;
  cout<<"---------------"<<endl;
  cout<<"test addition: \n ("<<poly_p<<") \n + ("<<poly_q<<")\n ========== \n";
  poly_p.add(poly_q);
  cout<<poly_p<<endl;
  cout<<"-----------"<<"\n"<<"test subtraction\n";


  return 0;
}
