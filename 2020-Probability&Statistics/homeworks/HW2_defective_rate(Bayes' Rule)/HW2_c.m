totalNumber = 100000;
RateOfB1 = 0.3;
RateOfB2 = 0.45;
RateOfB3 = 0.25;
defectiveRateB1 = 0.02;
defectiveRateB2 = 0.03;       
defectiveRateB3 = 0.02;
defectiveRateAll = RateOfB1 * defectiveRateB1 + RateOfB2 * defectiveRateB2 + RateOfB3 * defectiveRateB3; %0.245
NumOfB1 = round(totalNumber * RateOfB1);
NumOfB2 = round(totalNumber * RateOfB2);
NumOfB3 = round(totalNumber * RateOfB3);
ActuallProbability = zeros(1, 10);
%numOfOnesB3 = zeros(1, 1000);
%numOfOnesAll = zeros(1, 1000);

for i = 1:10
    %for j = 1:1000
        resultB3 = HW2_a(NumOfB3, defectiveRateB3);
        numOfOnesB3 = sum(resultB3);
        resultAll = HW2_a(totalNumber, defectiveRateAll);
        numOfOnesAll = sum(resultAll);
    %end

    ActuallProbability(i) = numOfOnesB3 / numOfOnesAll;   
end
ActuallProbability

% Theoretically, P(B3|A) = RateOfB3 * defectiveRateB3 / defectiveRateAll
%         =  0.25 * 0.02 / (0.006 + 0.0135 + 0.005) = 0.20408.
% Compared to actuall P(B3|A)s by using my function, we can see  
% actuall P(B3|A)s may not necessarily be 0.20408, but they are not far from it. 