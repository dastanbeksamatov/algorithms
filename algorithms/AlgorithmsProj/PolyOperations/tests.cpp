#include <iostream>
#include <map>
#include <vector>
#include "PolyOperations.h"

using namespace PolyOperations;
using namespace std;

// test for the methods of PolyOperations library

vector<double> p = { 2, 3, 3, 1 }; vector<double> q = { 0, -4, 3, 3 }; vector<double> r = { 0, 0, 0, 0 }; vector<double> s = { 1, 2, 1 };
map<int, double> m = { { 0, 1}, {1, 2}, {2, 2}, { 3, 4 } };
  // initialize Polynomials with maps and vectors
void test_constructor(){
  cout<<"Testing arithmetic operators for Polynomial library"<<endl;
  cout<<endl;
  Polynomial poly_vector(p);
  cout<<"Should print out polynomial {2, 3, 3, 1}:\n"<<poly_vector<<endl;
  Polynomial poly_map(m);
  cout<<"Should pring out polynomial from map {{ 0, 1}, {1, 2}, {2, 2}, { 3, 4 }}:\n"<<poly_map<<endl;
  cout<<endl;
}

void test_clean(){
  vector<double> test = {1, 2, 0 , 0, 2};
  Polynomial p(test);
  cout<<"Should erase zero coefficients: ({ 1,2,0,0,2 })\n";
  p.clean();
  cout<<"Result: ("<<p<<")\n";
  cout<<endl;
}

void test_addition(){
  Polynomial a(p);
  Polynomial b(q);
  cout<<"Testing addition: "<<endl;
  cout<<a<<" + "<<b<<"\n -------------------\n"<<a + b<<endl;
  cout<<endl;
}

void test_subtraction(){
  Polynomial a(p);
  Polynomial d(s);
  cout<<"Testing subtraction: "<<endl;
  cout<<a<<" - "<<d<<"\n -------------------\n"<<a-d<<endl;
  cout<<endl;
}

void test_mult(){
  Polynomial a(p);
  Polynomial b(m);
  Polynomial z(r);
  cout<<"Testing multiplication, second example is multiplication by null polynomial: "<<endl;
  cout<<a<<" * "<<b<<"\n --------------------\n"<<a*b<<endl;
  cout<<a<<" * "<<z<<"\n --------------------\n"<<a*z<<endl;
    cout<<endl;
}

void test_division(){
  Polynomial a(p); Polynomial b(q); Polynomial c(m); Polynomial d(s);
  Polynomial prod1 = a * b;
  Polynomial prod2 = c * d;
  vector<map<int, double>> res1 = prod1.divide(a);
  vector<map<int, double>> res2 = prod2.divide(d);
  vector<map<int, double>> res3 = prod1.divide(d);
  Polynomial quotientA(res1[0]);
  Polynomial quotientB(res2[0]);
  Polynomial remainderA(res1[1]);
  Polynomial remainderB(res2[1]);
  Polynomial quotientC(res3[0]);
  Polynomial remainderC(res3[1]);

  cout<<"Testing division: "<<endl;
  if(remainderA.isNull()){
    cout<<prod1<<" = ("<<quotientA<<")*("<<a<<")"<<endl;
  }
  if(remainderB.isNull()){
      cout<<prod2<<" = ("<<quotientB<<")*("<<d<<")"<<endl;
  }
  else{
    cout<<prod1<<" = ("<<quotientA<<")*("<<a<<") + ("<<remainderA<<")"<<endl;
    cout<<prod2<<" = ("<<quotientB<<")*("<<d<<") + ("<<remainderB<<")"<<endl;
  }
  cout<<prod1<<" = ("<<quotientC<<")*("<<d<<") + ("<<remainderC<<")"<<endl;
  cout<<"End of Arithmetic operations testing."<<endl;
    cout<<endl;
}

void test_bool(){
  Polynomial a(p); Polynomial b(q); 
  Polynomial c(m); Polynomial d(s);
  Polynomial f(m); Polynomial z(r);
  cout<<"Testing boolean operators for Polynomial library"<<endl<<endl;
  cout<<"should return false(0): ("<<a<<") > ("<<b<<") => "<<(a > b)<<endl;
  cout<<"should return true(1): ("<<f<<") == ("<<c<<") => "<<(f==c)<<endl;
  cout<<"shoudl return true(1): ("<<d<<") < ("<<a<<") => "<<(d<a)<<endl;
  cout<<"should return false(0): ("<<z<<") >= ("<<d<<") => "<<(z>=d)<<endl;
}