#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "PolyOperations.h"

using namespace PolyOperations;
using namespace std;

int main(){
  vector<double> p = { 2, 3, 3, 1 }; vector<double> q = { 0, -4, 3, 3 }; vector<double> r = { 1, 0, 0, 0 }; vector<double> d = { 1, 1 };

  Polynomial poly_p(p);
  Polynomial poly_q(q);
  Polynomial div(d);
  cout<<"Test for the class: "<<endl;
  cout<<"Class initialization works "<< poly_q <<endl;
  poly_p.clean();
  cout<<"degree: "<<poly_p.max_degree<<endl;
  cout<<"getMember() works"<<endl;
  cout<<"---------------"<<endl;
  cout<<"test addition: \n ("<<poly_p<<") \n + ("<<poly_q<<")\n ========== \n";
  cout<<poly_p+poly_q<<endl;
  cout<<"-----------"<<"\n"<<"test subtraction\n";
  cout<<poly_p<<" - "<<poly_q<<endl;
  cout<<poly_p-poly_q<<endl;

  cout<<"Test multiplication: "<<endl;
  cout<<poly_p<<endl;
  cout<<"Test multiplication: "<<endl;
  vector<Polynomial> result = poly_p.divide(div);
  cout<<result[0]<<" = ("<<result[1]<<")*("<<result[2]<<") + "<<result[3]<<endl;
  return 0;
}
