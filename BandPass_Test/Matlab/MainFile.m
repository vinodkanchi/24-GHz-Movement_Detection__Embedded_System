close all;
clear all;
clc;

raw = LTspice2Matlab_new('LMV385', [5 10 11]);
figure;
grid 

Freq = [20 50 100 150 200 250 300 350 400 450 500];
A1 = [35.73368 38.60126633 38.42603748 39.13879999 37.63710893 38.07842011 37.85893817 37.80789636 37.62965466 37.22441132 37.22120738];
A2 = [12.54708 9.572751571 8.799319482 8.725649515 8.808261702 8.517080303 8.744753543 8.519374645 8.702855119 8.392329162 8.027487072];
A = [48.28075 48.1740179 47.22535696 47.8644495 46.44537063 46.59550041 46.60369171 46.327271 46.33250978 45.61674048 45.24869445];

%Plotting the extracted data on a logarthmic scale
semilogx(raw.freq_vect, mag2db(abs(raw.variable_mat)));
hold on;

%Plotting measured datapoints on the same Plot
semilogx(Freq,A1,'*');
semilogx(Freq,A2,'o');
semilogx(Freq,A,'x');

%Adding title, legend, and x-y labels to the Plot
title( 'LTspice vs Matlab') ;
legend( char(raw.variable_name_list(5)), char(raw.variable_name_list(10)), char(raw.variable_name_list(11)),...
    'A1', 'A2', 'A');
ylabel( 'Voltage (V) in dB' );
xlabel( 'Freq (Hz)');