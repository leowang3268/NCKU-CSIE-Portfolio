totalNumber = 10000;
defectiveRateB1 = 0.02;
numOfOnes = zeros(1, 1000);
for i = 1:1000
    result = HW2_a(totalNumber, defectiveRateB1);
    numOfOnes(i) = sum(result);
end
h = histogram(numOfOnes, 'Normalization','probability');
xlabel('Number of Defective Products Out of 10000 Made by B1 for 1000 Times') 
ylabel('Relative Frequency') 