function randomSamples = GenerateSample(number)
X = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14];
sample = [1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,8,8,8,8,8,8,9,9,9,9,9,10,10,10,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,13,13,13,14,14,14,14,14,14,14,14,14,14,14];
result = zeros(1, number);
randomSamples = zeros(1, 14);
for i = 1:number
    result(1, i) = sample(1, randi(100));
    if(result(1, i) == 1)
        randomSamples(1, 1) = randomSamples(1, 1) + 1;
    end
    if(result(1, i) == 2)
        randomSamples(1, 2) = randomSamples(1, 2) + 1;
    end
    if(result(1, i) == 3)
        randomSamples(1, 3) = randomSamples(1, 3) + 1;
    end
    if(result(1, i) == 4)
        randomSamples(1, 4) = randomSamples(1, 4) + 1;
    end
    if(result(1, i) == 5)
        randomSamples(1, 5) = randomSamples(1, 5) + 1;
    end
    if(result(1, i) == 6)
        randomSamples(1, 6) = randomSamples(1, 6) + 1;
    end
    if(result(1, i) == 7)
        randomSamples(1, 7) = randomSamples(1, 7) + 1;
    end
    if(result(1, i) == 8)
        randomSamples(1, 8) = randomSamples(1, 8) + 1;
    end
    if(result(1, i) == 9)
        randomSamples(1, 9) = randomSamples(1, 9) + 1;
    end
    if(result(1, i) == 10)
        randomSamples(1, 10) = randomSamples(1, 10) + 1;
    end
    if(result(1, i) == 11)
        randomSamples(1, 11) = randomSamples(1, 11) + 1;
    end
    if(result(1, i) == 12)
        randomSamples(1, 12) = randomSamples(1, 12) + 1;
    end
    if(result(1, i) == 13)
        randomSamples(1, 13) = randomSamples(1, 13) + 1;
    end
    if(result(1, i) == 14)
        randomSamples(1, 14) = randomSamples(1, 14) + 1;
    end
end
for i = 1:14
    randomSamples(1, i) = randomSamples(1, i) / number;
end
figure('name','Histogram(Generate in Random)','NumberTitle','off'); 
bar(X, randomSamples);
xlabel('X Value');
ylabel('Relative Frequency');
end