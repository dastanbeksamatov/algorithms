from math import floor, sqrt

d = int(input(''))
r = int(input(''))
t = int(input(''))

# find the maximum age of Rita based on sum

r += 6
t += 3

n = floor(sqrt(2*r)) - 1

# m - remainder from Ritas sum and her max age summand

m = r - n*(n+1)/2


def check(n, m, d, t):
  if ((n-d)*(n-d+1)/2 == (t+m)):
    return m
  else:
    n = n-1
    m = n+m
    return check(n, m, d, t)
  
m = check(n,m,d,t)
print(int(m))