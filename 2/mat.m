
file = fopen('cmake-build-debug/output.txt',"r+");
% for i=1:n
inp=fscanf(file,'%f ');

%     n=200;      
%     nodes=5;
% 
%         y1=inp(1  : n)
%         y2=inp(n+1  : 2*n)
        
%         x1=inp(2*n+1 : n*3);
%         point_x=inp(3*n+1 : 3*n + nodes); 
%          point_y=inp(3*n+1+nodes : 3*n + 2*nodes); 
% plot(x1,y1,x1,y2 ,point_x,point_y,'o');
% для второй лабы 

n=9;
y1=inp(1  : n);
y2=inp(n+1  : 2*n);
x1=inp(2*n+1 :3 *n); 
% plot(y2,y1,y2,x1);
% loglog(y1,x1,y2,x1);
% loglog(x1,y1,x1,y2);

% plot(x1,y1)
%  title("зависимость чила итераций и фактической точности от заданной")
%  legend('фактическая точность','число итераций');
x_bis = [1e-10,1e-2];
y_bis = [1e-10,1e-2];

%  loglog(x1,y2,x_bis,y_bis)
%  xlabel("заданная точность")
%  ylabel("фактическая точность")
%   semilogx(x1,y1)
  xlabel("заданная точность")
  ylabel("log2 число итераций ")
 grid on;

% for i=1:n
%         fprintf(file,'%.20f ',x(i));
% 
% end
% z=[1,10,100,1000,10000,100000,1000000,10000000];
%
% semilogy(r2,r1);
%   xlabel("число узлов")
%   ylabel("ошибка")
%  
%   plot(y,e1,y,e2,y,e3);
%  legend('полином 2-й степени','полином 4-й степени','полином 8-й степени');
%  xlabel("x")
%  ylabel("error")
 grid on;
% plot(x3,y)
% y=[2.1e-14,1.5e-14,7.1e-14,6.1e-13,2e-8,1.7e-7,1e-5,2e-4];

% loglog(z,y)