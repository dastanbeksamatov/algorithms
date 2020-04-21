// Implementation of Polynomial class 
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include "PolyOperations.h"

using namespace PolyOperations;

namespace PolyOperations{

  // Constructors
  Polynomial::Polynomial(){
    this->coeffs_ = {};
    this->max_degree = 0;
  };
  // construct from vector
  Polynomial::Polynomial(std::vector<double> coefs){
    for (size_t i = 0; i<coefs.size(); i++){
      this->coeffs_[i] = coefs[i];
    }
    this->max_degree = this->coeffs_.crbegin()->first;
    this->clean();
  }
  // construct from another polynomial
  Polynomial::Polynomial(const Polynomial& q){
    this->coeffs_ = q.coeffs_;
    this->clean();
    max_degree = this->coeffs_.crbegin()->first;
  }
  // construct from map with degrees and coefficients as keys and values, respectively
  Polynomial::Polynomial(std::map<int, double> coef){
    this->coeffs_ = coef;
    this->clean();
  }

  //function used to remove zero coefficients from the map
  void Polynomial::clean(){
    std::map<int, double> temp = this->coeffs_;
    // if the map has all values zero, then it's a null polynomial
    bool empty = true; 
    auto i = this->coeffs_.cbegin();
    while(i!=this->coeffs_.cend()){ // this loop checks whether the map is null map
      if (i->second != 0){
        empty = false;
      }
      ++i;
    }
    // if the map is empty, it assigns 0 to 0 index of map, and its degree is also zero
    if(empty){
      std::map<int, double> def;
      def[0] = 0;
      this->coeffs_ = def;
      this->max_degree = 0;
    }
    // in any other case, it proceeds to remove elements with zero coefficient
    else{
      auto p = temp.cbegin();
      while(p != temp.cend()){
        if(p->second == 0 ){
            p = temp.erase(p);
        }
        else{
          ++p;
        }
      }
      this->coeffs_ = temp;
      this->max_degree = this->coeffs_.crbegin()->first;
    }
  }
  // getter and setters 
  void Polynomial::setMember(int index, double newCoef){
    this->coeffs_[index] = newCoef;
  }
  //
  int Polynomial::getMember(int index){
    return this->coeffs_.find(index)->second;
  }
  // checks whether map is null
  bool Polynomial::isNull(){
    return (this->max_degree==0 && this->getMember(0)==0);
  }

  bool Polynomial::isConstant(){
    return (this->max_degree==0 && this->getMember(0)>0);
  }

  
  // overloaded operators
  // overloaded std::cout operator used to display polynomials in pretty form
  std::ostream& operator<<(std::ostream& out, const Polynomial& p){
    // print Polynomial object
    Polynomial t(p);
    if(t.isNull()){
      return out<<"Null Polynomial";
    }
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
  // assignment operator for polynomial
  void Polynomial::operator=(const Polynomial& q){
    this->coeffs_ = q.coeffs_;
    this->clean();
  }

  void Polynomial::add(const Polynomial& q){
    Polynomial poly(q);
    int max_degree = std::max(this->max_degree, poly.max_degree);
    for(int i=0; i<=max_degree; i++){
      this->setMember(i, this->getMember(i)+poly.getMember(i));
    }
    this->clean();
  }
    // addition overloaded
  Polynomial operator+(const Polynomial& p, const Polynomial& q){
    Polynomial res(p);
    res.add(q);
    return res;
  }

  Polynomial operator +=(const Polynomial& p, const Polynomial& q){
    Polynomial res(p);
    res.add(p);
    res.add(q);
    return res;
  }

  //subtraction
  void Polynomial::subtract(const Polynomial& q){
    Polynomial other(q);
    int max_degree =  std::max(this->max_degree, other.max_degree);
    for (int i=0; i<=max_degree; i++){
      this->setMember(i, this->getMember(i) - other.getMember(i));
    }
    this->clean();
  }
  Polynomial operator-(const Polynomial& p, const Polynomial& q){
    Polynomial res(p);
    res.subtract(q);
    return res;
  }
    // decrementation overladed
  Polynomial operator -= (const Polynomial& p, const Polynomial& q){
    Polynomial res(p);
    res.subtract(p);
    res.subtract(q);
    return res;
  }


  //multiplication
  void Polynomial::multiply(const Polynomial& q){
    Polynomial poly(q);
    std::map<int, double> result;
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
          result[i+k] += this->coeffs_[i]*poly.coeffs_[k];
        }
      }
      this->coeffs_ = result;
    }
    this->clean();
    for (size_t i = 0; i<result.size(); ++i){
      this->setMember(i, result.at(i));
    }
  }

  Polynomial operator*(const Polynomial& p, const Polynomial& q){
    Polynomial res(p);
    res.multiply(q);
    return res;
  }

  Polynomial operator *=(const Polynomial& p, const Polynomial& q){
    Polynomial res(p);
    res.add(p*q);
    return res;
  }

  // long division, returns vector with quotient and remainder

  std::vector<std::map<int, double>> Polynomial::divide(const Polynomial& q){
    Polynomial divisor(q);
    if(divisor.isNull() || this->max_degree<divisor.max_degree){
      return {};
    }
    else{
      std::map<int, double> quotient;
      // remainder is a dividend in the beggining
      Polynomial remainder(*this);
      // degree and leading coefficient of divisor is constant
      int div_degree = divisor.max_degree;
      int lead_div = divisor.coeffs_.crbegin()->second;
      // run until remainder is null and remainder has degree less than divisor
      while(remainder.max_degree>=div_degree){
        // current power
        int cur_pow = remainder.max_degree - div_degree;
        // leading coefficient of remainder
        double last = remainder.coeffs_.crbegin()->second;
        std::map<int, double> temp;
        // make a temporary quotient
        temp[cur_pow] = last/lead_div;
        quotient[cur_pow] = last/lead_div;
        Polynomial tempP(temp);
        remainder = remainder- divisor*tempP;
        if(remainder.max_degree < div_degree){
          break;
        }
      }
    std::map<int, double> rem = remainder.coeffs_;
    std::vector<std::map<int, double>> result = {quotient, rem};
    return result;
    }
  }
  // overloaded / operator
  std::vector<std::map<int, double>> operator / (const Polynomial& p, const Polynomial& q){
    Polynomial res(q);
    std::vector<std::map<int, double>> result = res.divide(q);
    return result;
  }

  // Boolean operators overloaded
  bool operator == (const Polynomial& p, const Polynomial& q){
    return p.coeffs_ == q.coeffs_;
  }
  bool operator > (const Polynomial& p, const Polynomial& q){
    return p.coeffs_ > q.coeffs_;
  }
  bool operator >= (const Polynomial& p, const Polynomial& q){
    return p.coeffs_ >= q.coeffs_;
  }
  bool operator < (const Polynomial& p, const Polynomial& q){
    return p.coeffs_ < q.coeffs_;
  }
  bool operator <= (const Polynomial& p, const Polynomial& q){
    return p.coeffs_ <= q.coeffs_;
  }
  bool operator != (const Polynomial& p, const Polynomial& q){
    return p.coeffs_ != q.coeffs_;
  }


}
