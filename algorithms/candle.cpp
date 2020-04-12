//https://www.e-olymp.com/en/problems/7934


#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int d, r, t;
  cin>>d>>r>>t;

  // to adjust for n(n+1)/2 formula
  r+=6; t+=3;

  // max possible age of Rita
  long n = floor(sqrt(2*r)) - 1;
  //remainder 
  int m = r - n*(n+1)/2;
  //run the loop until remainder plus Alex's age is ideal sum
  while ((n-d)*(n-d+1)/2 != (t+m)){
    m += n;
    n -= 1;
  }
  cout<<m<<endl;
}