#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "PolyOperations.h"

using namespace PolyOperations;
using namespace std;

int main(){
  vector<double> p = { 2, 3, 3, 1 }; vector<double> q = { 0, -4, 3, 3 }; vector<double> r = { 1, 0, 0, 0 }; vector<double> d = { 1, 2, 1 };

  Polynomial poly_p(p);
  Polynomial poly_q(q);
  Polynomial poly_r(r);
  Polynomial div(d);
  cout<<"good till here"<<endl;
  cout<<"Test for the class: "<<endl;
  cout<<"Class initialization works "<< poly_q <<endl;
  poly_p.clean();
  cout<<"degree: "<<poly_p.max_degree<<endl;
  cout<<"getMember() works"<<endl;
  cout<<"---------------"<<endl;
  cout<<"test addition: \n ("<<poly_p<<") \n + ("<<poly_q<<")\n ========== \n";
  poly_r.add(poly_q);
  cout<<poly_r<<endl;
  cout<<"-----------"<<"\n"<<"test subtraction\n";
  cout<<poly_p<<" - "<<poly_q<<endl;
  cout<<poly_p-poly_q<<endl;
  Polynomial product(poly_p*poly_q);
  cout<<"Test multiplication: "<<endl;
  cout<<product<<endl;
  cout<<"Test multiplication: "<<endl;
  vector<Polynomial> result = product.divide(poly_q);
  //cout<<result[0]<<" = ("<<")*("<<") + "<<endl;
  return 0;
}
