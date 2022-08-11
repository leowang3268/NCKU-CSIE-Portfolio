result_1 = HW7_1a(1);
result_2 = HW7_1a(2);
result_20 = HW7_1a(20);

mu_1 = 0.5;
sigma_1 = 0.288;
mu_2 = 1;
sigma_2 = 0.408;
mu_20 = 10;
sigma_20 = 1.291;

figure('name','n = 1','NumberTitle','off'); 
histogram(result_1, 100, 'Normalization', 'pdf')
hold on; 
x_1 = (-3 * sigma_1:0.01:3 * sigma_1) + mu_1;
y_1 = exp(-0.5 * ((x_1 - mu_1) / sigma_1) .^2) / (sigma_1 * sqrt(2* pi));
plot (x_1, y_1);
hold off;
xlabel('X Value'); 
ylabel('Relative Frequency'); 

figure('name','n = 2','NumberTitle','off'); 
histogram(result_2, 100, 'Normalization', 'pdf')
hold on; 
x_2 = (-3 * sigma_2:0.01:3 * sigma_2) + mu_2;
y_2 = exp(-0.5 * ((x_2 - mu_2) / sigma_2) .^2) / (sigma_2 * sqrt(2* pi));
plot (x_2, y_2);
hold off;
xlabel('X Value'); 
ylabel('Relative Frequency'); 

figure('name','n = 20','NumberTitle','off'); 
histogram(result_20, 100, 'Normalization', 'pdf')
hold on; 
x_20 = (-3 * sigma_20:0.01:3 * sigma_20) + mu_20;
y_20 = exp(-0.5 * ((x_20 - mu_20) / sigma_20) .^2) / (sigma_20 * sqrt(2* pi));
plot (x_20, y_20);
hold off;
xlabel('X Value'); 
ylabel('Relative Frequency'); 