// Implementation of Polynomial class 
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include "PolyOperations.h"

using namespace PolyOperations;

namespace PolyOperations{
  //function used to clean polynomials 
  void Polynomial::clean(){
    auto p = this->coeffs_.cbegin();
    while(p != this->coeffs_.cend()){
      if(fabs(p->second) < 1e-9){
        this->coeffs_.erase(p++);
      }
      else{
        ++p;
      }
    }
    this->max_degree = this->coeffs_.crbegin()->first;
  }
  // getter and setters 
  void Polynomial::setMember(int index, double newCoef){
    this->coeffs_[index] = newCoef;
    this->clean();
  }
  //
  int Polynomial::getMember(int index){
    return this->coeffs_.find(index)->second;
  }

  bool Polynomial::isNull(){
    return (this->max_degree==0 && this->getMember(0)==0);
  }

  bool Polynomial::isConstant(){
    return (this->max_degree==0 && this->getMember(0)>0);
  }

  // Constructors
  Polynomial::Polynomial(){
    this->coeffs_ = { };
  };

  Polynomial::Polynomial(std::vector<double> coefs){
    for (int i = 0; i<coefs.size(); i++){
      this->coeffs_[i] = coefs[i];
    }
    this->max_degree = this->coeffs_.crbegin()->first;
    this->clean();
  }

  // overloaded operators
  std::ostream& operator<<(std::ostream& out, const Polynomial& p){
    // print Polynomial object
    Polynomial t = p;
    if(t.isNull()){
      return out<<"Null Polynomial";
    }
    bool firstCoeff = true;
    auto i = p.coeffs_.crbegin();
    std::string sign = "";
    while(i!=p.coeffs_.crend()){
      int power = i->first;
      double cur = i->second;
      if(cur>0){
        out<<sign;
      }
      else{
        out<<"-";
        cur = -cur;
      }
      if(cur!=1){
        out<<cur;
        if(power>0){
          out<<"*";
        }
      }
      if(cur == 1 && power==0){
        out<<cur;
      }
      if(power>0){
        out<<"x";
        if(power>1){
          out<<"^"<<power;
        }
      }
      sign = "+";
      ++i;
    }
    return out;
  }
  // assignment operator
  void Polynomial::operator=(const Polynomial& q){
    Polynomial res = q;
    this->coeffs_ = res.coeffs_;
    this->clean();
  }
  // addition
  void Polynomial::add(Polynomial& q){
    int max_degree = std::max(this->max_degree, q.max_degree);
    for(int i=0; i<=max_degree; i++){
      this->setMember(i, this->getMember(i)+q.getMember(i));
    }
    this->clean();
  }
  Polynomial operator+(Polynomial p, Polynomial& q){
    p.add(q);
    return p;
  }

  //subtraction
  void Polynomial::subtract(const Polynomial& q){
    Polynomial other = q;
    int max_degree =  std::max(this->max_degree, other.max_degree);

    for (int i=0; i<=max_degree; i++){
      this->setMember(i, this->getMember(i) - other.getMember(i));
    }
    this->clean();
  }
  Polynomial operator-(const Polynomial& p, const Polynomial& q){
    Polynomial res = p;
    res.subtract(q);
    return res;
  }


  //multiplication
  void Polynomial::multiply(const Polynomial& q){
    Polynomial poly = q;
    Polynomial result;
    // if the Polynomial is null polynomial, the product is zero
    if(poly.isNull()){
      // assign Polynomial to Null polynomial
      std::map<int, double> zero;
      this->coeffs_ = zero;
    }
    // if polynomial is constant, the product is just multiple of polynomial
    else if(poly.isConstant()){
      int max_deg = this->max_degree;
      for(int i=0; i<=max_degree; i++){
        this->coeffs_[i] *= poly.getMember(0);
      }
    }

    else{
      for(int i = 0; i <= poly.max_degree; i++){
        for(int k = 0; k<= this->max_degree; k++){
          result.coeffs_[i+k] += this->coeffs_[k]*poly.coeffs_[i];
        }
      }
      this->coeffs_ = result.coeffs_;
    }
    this->clean();
  }

  Polynomial operator*(const Polynomial& p, const Polynomial& q){
    Polynomial res = p;
    res.multiply(q);
    return res;
  }

  // long division, returns vector with dividend and remainder

  std::vector<Polynomial> Polynomial::divide(const Polynomial& q){
    Polynomial divisor = q;
    if(divisor.isNull() || this->max_degree<divisor.max_degree){
      return {};
    }
    else{
      Polynomial quotient;
      Polynomial remainder = *this;
      int div_degree = divisor.max_degree;
      while(!remainder.isNull() && remainder.max_degree>=div_degree){
        int cur_pow = remainder.max_degree - div_degree;
        Polynomial temp;
        double last = remainder.coeffs_.crbegin()->second;
        quotient.setMember(cur_pow, last);
        temp.setMember(cur_pow, last);
        remainder = remainder - divisor*temp;
        remainder.clean();
      }
    std::vector<Polynomial> result;
    result.push_back(*this);
    result.push_back(quotient);
    result.push_back(divisor);
    result.push_back(remainder);
    return result;
    }
  }
}
