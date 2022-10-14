clear;
clc;
n = 30;
h = 0.1;

for i=1:n
 if i == 1 || i==n
   b(i) = 1;
 else
   b(i) = 0;
 endif
end

A = [-2*(1 + (h*h)), 1];
A(n,n-1) = 1;
A(n,n) = -2*(1 + (h*h));

for i = 2:n-1
  for j=i:i
    A(i, j-1) = 1;
    A(i,j) = -2 * (1 + (h * h));
    A(i, j+1) = 1;
   end
end



