clear;
clc;

function res = f(x)
  res = x^3 + 3*(x^2) -1;
endfunction

a = -2;
b = 0;

n = 1000;
tol = 5*(10^(-5000000));
% exemplo: f=@(x) x^3-9*x+3; a=0; b=1; tol=0.005; maxit=1000;

for k=1:n
  a
  b
  x(k)=(a+b)/2;
  x(k)
  if f(a)*f(x(k))<0
    b=x(k);
  else
    a=x(k);
  endif
  if ( (abs(b-a)<tol) || (f(x(k))==0) )
    break
  endif
endfor
k
x_aprox=x(k)
A = f(x_aprox);
