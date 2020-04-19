// Implementation of Polynomial class 
#include <iostream>
#include <algorithm>
#include <vector>
#include "PolyOperations.h"

using namespace PolyOperations;

namespace PolyOperations{
  //function used to clean polynomials 
  void Polynomial::clean(){
    auto p = this->coeffs_.cbegin();
    while(p != this->coeffs_.cend()){
      if(p->second == 0){
        this->coeffs_.erase(p++);
      }
      else{
        ++p;
      }
    }
  }
  // getter and setters 
  void Polynomial::setMember(int index, int coefficient){
    this->coeffs_[index] = coefficient;
    this->clean();
  }
  //
  int Polynomial::getMember(int index){
    return this->coeffs_[index];
  }

  // Constructors
  Polynomial::Polynomial(){
    this->coeffs_ = { };
  };

  Polynomial::Polynomial(std::vector<int> coefs){
    for (int i = 0; i<coefs.size(); i++){
      this->coeffs_[i] = coefs[i];
    }
    this->max_degree = this->coeffs_.rbegin()->first;
  }
  // overloaded operators
  std::ostream& operator<<(std::ostream& out, const Polynomial& p){
    auto i = p.coeffs_.cbegin();
    int deg = p.max_degree + 1;
    while(i!=p.coeffs_.cend()){
      if(i->second==1){
        out<<"*x^"<<deg<<"+";
      }
      else if(i->second!=0){
        out<<i->second<<"*x^"<<deg<<"+";
      }
      deg-=1;
      ++i;
    }
    return out;
  }

  // addition
  Polynomial operator+(const Polynomial& p, const Polynomial& q){
    Polynomial res = p;
    return res;
  }
}
