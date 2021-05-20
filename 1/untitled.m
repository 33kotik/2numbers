
file = fopen('cmake-build-debug/output.txt',"r+");
% for i=1:n
    inp=fscanf(file,'%f ');
    n=1001;      
    r1=inp(1:16);
    r1=r1/1000
    r2=inp(100:115)
%     x1=inp(n+1 : n*2);
%     e1=inp(n+n+1 : n*3);
%     x2=inp(n*3+1 : n*4);
%     e2=inp(n*4+1 : n*5);
%     x3=inp(n*5+1 : n*6);
%     e3=inp(n*6+1 : n*7);
%     y=inp(n*7+1 : n*8);
%     f=inp(1 : n);
% end
% for i=1:n
%         fprintf(file,'%.20f ',x(i));
% 
% end
% z=[1,10,100,1000,10000,100000,1000000,10000000];
%
semilogy(r2,r1);
  xlabel("число узлов")
  ylabel("ошибка")
%  plot(y,f,y,x1,y,x2,y,x3);
%  legend('f(x)','полином 2-й степени','полином 4-й степени','полином 8-й степени');
%  xlabel("x")
%  ylabel("y")
% grid on;
%   plot(y,e1,y,e2,y,e3);
%  legend('полином 2-й степени','полином 4-й степени','полином 8-й степени');
%  xlabel("x")
%  ylabel("error")
 grid on;
% plot(x3,y)
% y=[2.1e-14,1.5e-14,7.1e-14,6.1e-13,2e-8,1.7e-7,1e-5,2e-4];

% loglog(z,y)