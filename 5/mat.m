
file = fopen('cmake-build-debug/output.txt',"r+");
% for i=1:n
inp=fscanf(file,'%f ');
n=inp(1:2);
x=inp(2  : n+1);
y=inp(n+2  : 2*n+1);
% hp=inp(2*n+2 :3 *n+1); 
%erorrs=inp(3*n+2 :4 *n+1);
%  plot (y,x)
loglog(x,y)
% loglog(x,y_ac,x,hp);
% loglog(y1,x1,y2,x1);
% loglog(x1,y1,x1,y2);

% plot(x1,y1)
%  title("зависимость чила итераций и фактической точности от заданной")
% legend('фактическая точность','h^p');
% x_bis = [1e-10,1e-2];
% y_bis = [1e-10,1e-2];

%  loglog(x1,y2,x_bis,y_bis)
ylabel("координата ошибки")
 xlabel("размер шага")
%   semilogx(x1,y1)
%   xlabel("заданная точность")
%   ylabel("log2 число итераций ")
 grid on;

% cdc
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