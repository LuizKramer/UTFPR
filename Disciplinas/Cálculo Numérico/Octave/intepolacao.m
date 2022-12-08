clear

%Para quatro valores
 x=[2.8 3.0 3.2 3.4];
 y=e.^x;
 t=[2.4:0.1:3.8];
 f=e.^t;
 n=length(x)-1;
 p=0;

for k=1:n+1
   L=1;
   for i=1:n+1
     if i!=k
       L=L.*(t-x(i))/(x(k)-x(i));
     end
end
   p=p+y(k)*L;
end

figure
  plot(t,f,'g', x,y,'*',t,p,'r')
  axis ([ 2.4 3.8 5 40]);
  p(8)
clearvars
  %Para Tres valores
 x=[2.8 3.0 3.2];
 y=e.^x;
 t=[2.4:0.1:3.8];
 f=e.^t;
 n=length(x)-1;
 p=0;
 for k=1:n+1
   L=1;
   for i=1:n+1
     if i!=k
       L=L.*(t-x(i))/(x(k)-x(i));
     end
end
   p=p+y(k)*L;
 end

figure
  plot(t,f,'g', x,y,'*',t,p,'r')
  axis ([ 2.4 3.9 5 40]);
  p(8)
clear

 %Para Dois valores
 x=[2.8 3.2] ;
 y=e.^x;
 t=[2.4:0.1:3.8];
 f=e.^t;
 n=length(x)-1;
 p=0;
 for k=1:n+1
   L=1;
   for i=1:n+1
     if i!=k
       L=L.*(t-x(i))/(x(k)-x(i));
     end
end
   p=p+y(k)*L;
 end

figure
 plot(t,f,'g', x,y,'*',t,p,'r')
 axis ([ 2.4 3.9 5 40]);
 p(8)

