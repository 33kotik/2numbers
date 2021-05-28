
file = fopen('cmake-build-debug/output.txt',"r+");
% for i=1:n
inp=fscanf(file,'%f');
n=inp(1:2);
y1=inp(2  : n+1);
y2=inp(n+2  : 2*n+1);
x=inp(2*n+2 :3 *n+1); 
% start=3*n+1;cd
% n2=inp(start+1:start+ 2);
% x2=inp(start+ 2  :start+ n2+1);
% y2=inp(start+n2+2  :start+ 2*n2+1);
% y3=inp(start+2*n2+2 :start+ 3 *n2+1); 
% erorrs=inp(3*n+2 :4 *n+1);
% plot(x1,y1,x2,y2,x2,y3)

semilogx(x,y1,x,y2)
% loglog(x,y_ac,x,hp);
%  plot(x1,y12,x2,y3);


% plot(x1,y1)
% title("n=100")

%  x_bis = [1e-10,1e-0];
% y_bis = [1e-10,1e-0];
% title("n=100")
% % % loglog(x,y1,x,y2);
legend('конечных разностей','рунге-кутты');
%  loglog(x1,y2,x_bis,y_bis)
 ylabel("координата")
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