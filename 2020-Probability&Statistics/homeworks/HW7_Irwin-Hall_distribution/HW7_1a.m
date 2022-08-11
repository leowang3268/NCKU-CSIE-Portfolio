function result = HW7_1a(n)

totalNum = 1000000;
result = zeros(1, totalNum);
for i = 1: n
    X = rand(1, totalNum);
    result = result + X;
end

end