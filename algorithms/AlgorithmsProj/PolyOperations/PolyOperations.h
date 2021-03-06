#ifndef POLYOPERATIONS_H
#define POLYOPERATIONS_H
#include <vector>
#include <map>
#include <utility>
namespace PolyOperations{
  // Class of polynomial operations for polynomials with integer coefficients
  class Polynomial{
    private:
    // map's key, value is power and coefficient of Polynomial, respectively
    std::map<int, double> coeffs_;
    public:
    int max_degree;
    // default constructor
    Polynomial();
    // constructor with given coefficients and degrees
    Polynomial(std::vector<double> coefs);

    Polynomial(const Polynomial& q);

    Polynomial(std::map<int, double> coef);

    // initialize polynomial operations that will override basic arithmetical operators
    friend Polynomial operator + (const Polynomial& p, const Polynomial& q);
    friend Polynomial operator - (const Polynomial& p, const Polynomial& q);
    friend std::vector<std::map<int, double>> operator / (const Polynomial& p, const Polynomial& q);
    friend Polynomial operator * (const Polynomial& p, const Polynomial& q);
    friend Polynomial operator += (const Polynomial& p, const Polynomial& q);
    friend Polynomial operator -= (const Polynomial& p, const Polynomial& q);
    friend Polynomial operator /= (const Polynomial& p, const Polynomial& q);
    friend Polynomial operator *= (const Polynomial& p, const Polynomial& q);

    // initialize comparison operators
    friend bool operator == (const Polynomial& p, const Polynomial& q);
    friend bool operator != (const Polynomial& p, const Polynomial& q);
    friend bool operator < (const Polynomial& p, const Polynomial& q);
    friend bool operator <= (const Polynomial& p, const Polynomial& q);
    friend bool operator > (const Polynomial& p, const Polynomial& q);
    friend bool operator >= (const Polynomial& p, const Polynomial& q);
    
    void operator = (const Polynomial& p);
    // printing polynomial
    friend std::ostream& operator <<(std::ostream &out, const Polynomial& p);

    // arithmetical methods
    void add(const Polynomial& q);
    void subtract(const Polynomial& q);
    // returns quotient and remainder in a vector of maps
    std::vector<std::map<int, double>> divide(const Polynomial& q);
    void multiply(const Polynomial& q);

    // utility functions
    int getMember(int index);
    void setMember(int index, double newCoef);
    void clean();
    bool isNull();
    bool isConstant();
  };
}

#endif