income = [72.2 31.9 26.5 29.1 27.3 8.6 22.3 26.5 20.4 12.8 25.1 19.2 24.1 58.2 68.1 89.2 55.1 9.4 14.5 13.9 20.7 17.9 8.5 55.4 38.1 54.2 21.5 26.2 59.1 43.3];
a = mean(income);
a
b = median(income);
b
c = std(income);
c
d = trimmean(income, 20);
d % 因為資料大多集中在10~50(尤其是20~40)的區間，所以將最小和最大的10%移除掉後得到的平均值會更能代表資料集中的趨勢
h = histogram(income,'Normalization','probability');
xlabel('Percentage of Family in Upper Income Level (%)') 
ylabel('Relative Frequency') 


