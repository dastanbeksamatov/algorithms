// Implementation of Polynomial class 
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include "PolyOperations.h"

using namespace PolyOperations;

namespace PolyOperations{
  //function used to clean polynomials 
  void Polynomial::clean(){
    auto p = this->coeffs_.cbegin();
    while(p != this->coeffs_.cend()){
      if(p->second == 0.0){
        this->coeffs_.erase(p++);
      }
      else{
        ++p;
      }
    }
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
    return (this->max_degree==0 && this->getMember(0)==1);
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

  // addition
  void Polynomial::add(Polynomial& q){
    int min_degree = std::min(this->max_degree, q.max_degree);
    for(int i=0; i<=min_degree; i++){
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
    int min_degree =  std::min(this->max_degree, other.max_degree);

    for (int i=0; i<=min_degree; i++){
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
    Polynomial res = *this;
    
  }
}
