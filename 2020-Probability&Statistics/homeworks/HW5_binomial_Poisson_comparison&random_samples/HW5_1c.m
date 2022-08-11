%digits(4);
n = ['1'; ' '; '2'; ' '; ' '; '3'; ' '; ' '; ' '; '4'; ' '; ' '; ' '; ' '; '5' ; ' '; ' '; ' '; ' '; ' '; '6'; ' '; ' '; ' '; ' '; ' '; ' '; '7'; ' '; ' '; ' '; ' '; ' '; ' '; ' '];
r = [0; 1; 0; 1; 2; 0; 1; 2; 3; 0; 1; 2; 3; 4; 0; 1; 2; 3; 4; 5; 0; 1; 2; 3; 4; 5; 6; 0; 1; 2; 3; 4; 5; 6; 7];
p = [0.1, 0.2, 0.25, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9];
sum_result = zeros(35, 10);
sum_1 = zeros(1, 10);
for i = 1:2
    for j = 1:10
        sum_1(1,j) = sum_1(1, j) + HW5_1a(i-1,1,p(1,j));
        sum_result(i, j) = sum_1(1, j);
    end
end
sum_2 = zeros(1, 10);
for i = 1:3
    for j = 1:10
        sum_2(1,j) = sum_2(1, j) + HW5_1a(i-1,2,p(1,j));
        sum_result(i+2, j) = sum_2(1, j);
    end
end
sum_3 = zeros(1, 10);
for i = 1:4
    for j = 1:10
        sum_3(1,j) = sum_3(1, j) + HW5_1a(i-1,3,p(1,j));
        sum_result(i+5, j) = sum_3(1, j);
    end
end
sum_4 = zeros(1, 10);
for i = 1:5
    for j = 1:10
        sum_4(1,j) = sum_4(1, j) + HW5_1a(i-1,4,p(1,j));
        sum_result(i+9, j) = sum_4(1, j);
    end
end
sum_5 = zeros(1, 10);
for i = 1:6
    for j = 1:10
        sum_5(1,j) = sum_5(1, j) + HW5_1a(i-1,5,p(1,j));
        sum_result(i+14, j) = sum_5(1, j);
    end
end
sum_6 = zeros(1, 10);
for i = 1:7
    for j = 1:10
        sum_6(1,j) = sum_6(1, j) + HW5_1a(i-1,6,p(1,j));
        sum_result(i+20, j) = sum_6(1, j);
    end
end
sum_7 = zeros(1, 10);
for i = 1:8
    for j = 1:10
        sum_7(1,j) = sum_7(1, j) + HW5_1a(i-1,7,p(1,j));
        sum_result(i+27, j) = sum_7(1, j);
     end
end

p_k = zeros(35, 10);
for i = 1:35
    for j = 1:10
        p_k(i, j) = roundn(sum_result(i, j), -4);
    end
end

p0_1 = p_k(:,1);
p0_2 = p_k(:,2);
p0_25 = p_k(:,3);
p0_3 = p_k(:,4);
p0_4 = p_k(:,5);
p0_5 = p_k(:,6);
p0_6 = p_k(:,7);
p0_7 = p_k(:,8);
p0_8 = p_k(:,9);
p0_9 = p_k(:,10);

T = table(n, r, p0_1, p0_2, p0_25, p0_3, p0_4, p0_5, p0_6, p0_7, p0_8, p0_9);
%display(T);
figure('name','Binomial','NumberTitle','off'); 
TString = evalc('disp(T)');
TString = strrep(TString,'<strong>','\bf');
TString = strrep(TString,'</strong>','\rm');
TString = strrep(TString,'_','\_');
FixedWidth = get(0,'FixedWidthFontName');
annotation(gcf,'Textbox','String',TString,'Interpreter','Tex', 'FontName',FixedWidth,'Units','Normalized','Position',[0 0 1 1]);