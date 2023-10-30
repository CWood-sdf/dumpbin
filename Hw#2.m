
gasCoef = [
    38.91  3.904*10^-2  -3.105*10^-1  8.606*10^-9;
    48.50  9.188*10^-2  -8.54*10^-5   32.4*10^-9 ;
    29.10  1.158*10^-2  -0.6076*10^-5 1.311*10^-9;
    29.00  0.2199*10^-2 -0.5723*10^-5 -2.871*10^-9
];
disp("yo select gass: SO2: 1, SO3: 2, O2: 3, N2: 4")
gas = scanf("%d", "");
coef = gasCoef(gas, :);
% print(coef);

% scanf("%s", "");
disp("yo what the temperature")


temp = scanf("%f", "");

Cp = coef(1) + coef(2)*temp + coef(3)*temp^2 + coef(4)*temp^3;
printf("Cp: %f\n", Cp);

