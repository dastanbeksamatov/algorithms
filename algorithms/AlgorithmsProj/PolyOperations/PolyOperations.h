#include <vector>
namespace PolyOperations{
  // Class of polynomial operations for polynomials with integer coefficients
  class Polynomial{
    public: 
    int degree;
    std::vector<int> coeffs;
    // default constructor
    Polynomial();
    // constructor with given coefficients and degrees
    Polynomial(std::vector<int> coefs);

    // initialize polynomial operations that will override basic arithmetical operators
    friend Polynomial operator + (const Polynomial& p, const Polynomial& q);
    friend Polynomial operator - (const Polynomial& p, const Polynomial& q);
    friend Polynomial operator / (const Polynomial& p, const Polynomial& q);
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
    
    // arithmetical methods
    void add(const Polynomial& q);
    void subtract(const Polynomial& q);
    void divide(const Polynomial& q);
    void multiply(const Polynomial& q);

    // utility functions
    int getMember(int index);
    void setMember(int index, int newCoef);
    int degree();
    bool isConstant(std::vector<int> coeffs);
    bool isNegative(std::vector<int> degs);
  };
}
