// Implementation of Polynomial class 
#include <iostream>
#include <algorithm>
#include <vector>
#include "PolyOperations.h"

using namespace PolyOperations;

namespace PolyOperations{
  Polynomial::Polynomial(){
    this->coeffs = { };
    this->degree = this->coeffs.size();
  };

  Polynomial::Polynomial(std::vector<int> coefs){
    this->coeffs = coefs;
    this->degree = coefs.size() - 1;
  }
  // overloading addition operator
  Polynomial operator+(const Polynomial& p, const Polynomial& q){
    Polynomial res = p;
    res.add(q);
    return res;
  }
}
