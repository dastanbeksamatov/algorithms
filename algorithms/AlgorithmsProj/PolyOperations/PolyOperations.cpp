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
    if (this->isNull()){
      this->setMember(0,0);
      this->max_degree = -1;
     }
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
    this->coeffs_ = {};
    this->max_degree = 0;
  };

  Polynomial::Polynomial(std::vector<double> coefs){
    for (int i = 0; i<coefs.size(); i++){
      this->coeffs_[i] = coefs[i];
    }
    this->max_degree = this->coeffs_.crbegin()->first;
    this->clean();
  }
  Polynomial::Polynomial(const Polynomial& q){
    this->coeffs_ = q.coeffs_;
    this->clean();
    max_degree = this->coeffs_.crbegin()->first;
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
    this->coeffs_ = q.coeffs_;
    this->clean();
  }
  // addition
  void Polynomial::add(const Polynomial& q){
    Polynomial poly = q;
    int max_degree = std::max(this->max_degree, poly.max_degree);
    for(int i=0; i<=max_degree; i++){
      this->setMember(i, this->getMember(i)+poly.getMember(i));
    }
    this->clean();
  }
  Polynomial operator+(const Polynomial& p, const Polynomial& q){
    Polynomial res = p;
    res.add(q);
    return res;
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
      for(int i = 0; i <= this->max_degree; i++){
        for(int k = 0; k<= poly.max_degree; k++){
          result.coeffs_[i+k] += this->coeffs_[i]*poly.coeffs_[k];
        }
      }
      this->coeffs_ = result.coeffs_;
    }
    this->clean();
    for (int i = 0; i<result.coeffs_.size(); ++i){
      this->setMember(i, result.coeffs_.at(i));
    }
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
      std::cout<<"this true"<<std::endl;
      return {};
    }
    else{
      std::cout<<"passes till here 0"<<std::endl;
      Polynomial quotient;
      Polynomial remainder = *this;
      int div_degree = divisor.max_degree;
      std::cout<<"passes till here"<<quotient<<std::endl;
      while(!remainder.isNull() && remainder.max_degree>=div_degree){
        int cur_pow = remainder.max_degree - div_degree;
        if (quotient.max_degree > cur_pow){
          break;
        }
        std::cout<<"passes till here 2"<<std::endl;
        double last = remainder.coeffs_.crbegin()->second;
        double lead_div = divisor.coeffs_.crbegin()->first;
        std::cout<<"remainder's last coef: "<<last<<std::endl;
        Polynomial temp;
        temp.setMember(cur_pow, last);
        quotient.add(temp);
        remainder = remainder - divisor*temp;
        remainder.clean();
        std::cout<<remainder.max_degree<<std::endl;
        temp.setMember(cur_pow, 0);
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
