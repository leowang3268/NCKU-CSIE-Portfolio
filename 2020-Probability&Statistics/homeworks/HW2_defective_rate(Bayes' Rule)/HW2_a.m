function result = HW2_a(totalNumber, defectiveRate)
    %totalNumber = 10000;
    %defectveRate = 2;
    RateOfOnes = ((defectiveRate*41/40)-(defectiveRate*39/40)).*rand + (defectiveRate-0.0005); 
    
    numberOfOnes = round(totalNumber * RateOfOnes);
    result = [ones(1, numberOfOnes), zeros(1, totalNumber - numberOfOnes)];
    result = result(randperm(length(result)));


