figure('name','p = 0.01','NumberTitle','off'); 
x = 0:10000;
b1 = binopdf(x, 10000, 0.01)
p1 = poisspdf(x,100);
plot(x, b1);
hold on
plot(x, p1);
hold off
legend('binomial distribution', 'poisson distribution');

figure('name','p = 0.1','NumberTitle','off'); 
x = 0:10000;
b1 = binopdf(x, 10000, 0.1)
p1 = poisspdf(x,1000);
plot(x, b1);
hold on
plot(x, p1);
hold off
legend('binomial distribution', 'poisson distribution');

figure('name','p = 0.2','NumberTitle','off'); 
x = 0:10000;
b1 = binopdf(x, 10000, 0.2)
p1 = poisspdf(x,2000);
plot(x, b1);
hold on
plot(x, p1);
hold off
legend('binomial distribution', 'poisson distribution');

figure('name','p = 0.5','NumberTitle','off'); 
x = 0:10000;
b1 = binopdf(x, 10000, 0.5)
p1 = poisspdf(x,5000);
plot(x, b1);
hold on
plot(x, p1);
hold off
legend('binomial distribution', 'poisson distribution');