filename = 'plot_data_nl-e-ox.txt';
delimiterIn = ' ';
headerlinesIn = 0;
fxdataeuler=importdata(filename,delimiterIn,headerlinesIn);

filename = 'plot_data_nl-i-ox.txt';
delimiterIn = ' ';
headerlinesIn = 0;
fxdataieuler=importdata(filename,delimiterIn,headerlinesIn);

filename = 'plot_data_nl-e-oy.txt';
delimiterIn = ' ';
headerlinesIn = 0;
fydataeuler=importdata(filename,delimiterIn,headerlinesIn);

filename = 'plot_data_nl-i-oy.txt';
delimiterIn = ' ';
headerlinesIn = 0;
fydataieuler=importdata(filename,delimiterIn,headerlinesIn);

filename = 'plot_data_nl-e-oz.txt';
delimiterIn = ' ';
headerlinesIn = 0;
nzdataeuler=importdata(filename,delimiterIn,headerlinesIn);

filename = 'plot_data_nl-i-oz.txt';
delimiterIn = ' ';
headerlinesIn = 0;
nzdataieuler=importdata(filename,delimiterIn,headerlinesIn);

filename = 'plot_data_nl-e-cl.txt';
delimiterIn = ' ';
headerlinesIn = 0;
cldataeuler=importdata(filename,delimiterIn,headerlinesIn);

filename = 'plot_data_nl-i-cl.txt';
delimiterIn = ' ';
headerlinesIn = 0;
cldataieuler=importdata(filename,delimiterIn,headerlinesIn);

filename = 'plot_data_l-e-cl.txt';
delimiterIn = ' ';
headerlinesIn = 0;
lcldataeuler=importdata(filename,delimiterIn,headerlinesIn);

filename = 'plot_data_l-i-cl.txt';
delimiterIn = ' ';
headerlinesIn = 0;
lcldataieuler=importdata(filename,delimiterIn,headerlinesIn);

filename = 'plot_data_l-analytic-cl.txt';
delimiterIn = ' ';
headerlinesIn = 0;
lcldataanalytic=importdata(filename,delimiterIn,headerlinesIn);

% data(:,1) is time
% data(:,2) is x
% data(:,3) is dx/dt
% data(:,4) is y
% data(:,5) is dydt
% data(:,6) is ø
% data(:,7) is dø/dt

figure(1);

subplot(2,1,1);
plot(fxdataeuler(:,1),fxdataeuler(:,2),'Color',[33/255 79/255 255/255],'LineWidth',2);
grid;
title('Euler method for $$[f_x, f_y, n_z] = [3496, 0, 0]$$', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$x(t)$$', 'Interpreter', 'Latex');

subplot(2,1,2);
plot(fxdataieuler(:,1),fxdataieuler(:,2),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Improved Euler method for $$[f_x, f_y, n_z] = [3496, 0, 0]$$', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$x(t)$$', 'Interpreter', 'Latex');

figure(2);

subplot(2,1,1);
plot(fydataeuler(:,1),fydataeuler(:,4),'Color',[33/255 79/255 255/255],'LineWidth',2);
grid;
title('Euler method for $$[f_x, f_y, n_z] = [0, -3496, 0]$$', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$y(t)$$', 'Interpreter', 'Latex');

subplot(2,1,2);
plot(fydataieuler(:,1),fydataeuler(:,4),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Improved Euler method for $$[f_x, f_y, n_z] = [0, -3496, 0]$$', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$y(t)$$', 'Interpreter', 'Latex');

figure(3);

subplot(2,1,1);
plot(nzdataeuler(:,1),nzdataeuler(:,6),'Color',[33/255 79/255 255/255],'LineWidth',2);
grid;
title('Euler method for $$[f_x, f_y, n_z] = [0, 0, -3496]$$', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\psi(t)$$', 'Interpreter', 'Latex');

subplot(2,1,2);
plot(nzdataeuler(:,1),nzdataeuler(:,6),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Improved Euler method for $$[f_x, f_y, n_z] = [0, 0, -3496]$$', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\psi(t)$$', 'Interpreter', 'Latex');

figure(4);

subplot(2,1,1);
plot(cldataeuler(:,1),cldataeuler(:,2),'Color',[33/255 79/255 255/255],'LineWidth',2);
grid;
title('Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$x(t)$$', 'Interpreter', 'Latex');

subplot(2,1,2);
plot(cldataeuler(:,1),cldataeuler(:,3),'Color',[33/255 79/255 255/255],'LineWidth',2);
grid;
title('Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\dot{x}(t)$$', 'Interpreter', 'Latex');

figure(5);

subplot(2,1,1);
plot(cldataeuler(:,1),cldataeuler(:,4),'Color',[33/255 79/255 255/255],'LineWidth',2);
grid;
title('Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$y(t)$$', 'Interpreter', 'Latex');

subplot(2,1,2);
plot(cldataeuler(:,1),cldataeuler(:,5),'Color',[33/255 79/255 255/255],'LineWidth',2);
grid;
title('Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\dot{y}(t)$$', 'Interpreter', 'Latex');

figure(6);

subplot(2,1,1);
plot(cldataeuler(:,1),cldataeuler(:,6),'Color',[33/255 79/255 255/255],'LineWidth',2);
grid;
title('Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\psi(t)$$', 'Interpreter', 'Latex');

subplot(2,1,2);
plot(cldataeuler(:,1),cldataeuler(:,7),'Color',[33/255 79/255 255/255],'LineWidth',2);
grid;
title('Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\dot{\psi}(t)$$', 'Interpreter', 'Latex');

figure(7);

subplot(2,1,1);
plot(cldataieuler(:,1),cldataieuler(:,2),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Improved Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$x(t)$$', 'Interpreter', 'Latex');

subplot(2,1,2);
plot(cldataieuler(:,1),cldataieuler(:,3),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Improved Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\dot{x}(t)$$', 'Interpreter', 'Latex');

figure(8);

subplot(2,1,1);
plot(cldataieuler(:,1),cldataieuler(:,4),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Improved Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$y(t)$$', 'Interpreter', 'Latex');

subplot(2,1,2);
plot(cldataieuler(:,1),cldataieuler(:,5),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Improved Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\dot{y}(t)$$', 'Interpreter', 'Latex');

figure(9);

subplot(2,1,1);
plot(cldataieuler(:,1),cldataieuler(:,4),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Improved Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\psi(t)$$', 'Interpreter', 'Latex');

subplot(2,1,2);
plot(cldataieuler(:,1),cldataieuler(:,5),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Improved Euler method for the closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\dot{\psi}(t)$$', 'Interpreter', 'Latex');

figure(10);

%subplot(2,1,1);
plot(lcldataeuler(:,1),lcldataeuler(:,2),'Color',[33/255 79/255 255/255],'LineWidth',2);
grid;
title('Euler method for the linear closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\psi(t)$$', 'Interpreter', 'Latex');
hold  on;
plot(lcldataieuler(:,1),lcldataieuler(:,2),'Color',[255/255 79/255 33/255],'LineWidth',2);
title('Improved Euler method for the linear closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\psi(t)$$', 'Interpreter', 'Latex');
hold on;
plot(lcldataanalytic(:,1),lcldataanalytic(:,2),'Color',[33/255 255/255 33/255],'LineWidth',2);
title('Analytic solution for the linear closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\psi(t)$$', 'Interpreter', 'Latex');

figure(11);

%subplot(2,1,1);
plot(lcldataieuler(:,1),lcldataieuler(:,3),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Improved Euler method for the linear closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\dot{\psi}(t)$$', 'Interpreter', 'Latex');
%subplot(2,1,2);
hold on;
plot(lcldataeuler(:,1),lcldataeuler(:,3),'Color',[33/255 79/255 255/255],'LineWidth',2);
title('Euler method for the linear closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\dot{\psi}(t)$$', 'Interpreter', 'Latex');
hold on;
plot(lcldataanalytic(:,1),lcldataanalytic(:,3),'Color',[33/255 255/255 33/255],'LineWidth',2);
title('Analytic solution for the linear closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\dot{\psi}(t)$$', 'Interpreter', 'Latex');

figure(12);

plot(lcldataanalytic(:,1),lcldataanalytic(:,2),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Analytic solution for the linear closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\psi(t)$$', 'Interpreter', 'Latex');

figure(13);
plot(lcldataanalytic(:,1),lcldataanalytic(:,3),'Color',[255/255 79/255 33/255],'LineWidth',2);
grid;
title('Analytic solution for the linear closed loop system', 'Interpreter', 'Latex');
xlabel('$$t$$', 'Interpreter', 'Latex');
ylabel('$$\dot{\psi}(t)$$', 'Interpreter', 'Latex');



