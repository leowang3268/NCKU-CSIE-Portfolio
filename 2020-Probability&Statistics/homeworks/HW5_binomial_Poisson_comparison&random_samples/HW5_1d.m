r = [0; 1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 11; 12; 13; 14; 15; 16; 17; 18; 19; 20; 21; 22; 23; 24];
mean = [5.5, 6.0, 6.5, 7.0, 7.5, 8.0, 8.5, 9.0, 9.5];

sum_result = zeros(25, 9);
sum = zeros(1, 9);
for i = 1:25
    for j = 1:9
        sum(1, j) = sum(1, j) + HW5_1b(i-1, mean(j));
        sum_result(i, j) = sum(1, j);
    end
end

mean_k = zeros(25, 9);
for i = 1:25
    for j = 1:9
        mean_k(i, j) = roundn(sum_result(i, j), -4);
    end
end

mean5_5 = mean_k(:,1);
mean6_0 = mean_k(:,2);
mean6_5 = mean_k(:,3);
mean7_0 = mean_k(:,4);
mean7_5 = mean_k(:,5);
mean8_0 = mean_k(:,6);
mean8_5 = mean_k(:,7);
mean9_0 = mean_k(:,8);
mean9_5 = mean_k(:,9);

T = table(r, mean5_5, mean6_0, mean6_5, mean7_0, mean7_5, mean8_0, mean8_5, mean9_0, mean9_5);
TString = evalc('disp(T)');
figure('name','Poisson','NumberTitle','off'); 
TString = strrep(TString,'<strong>','\bf');
TString = strrep(TString,'</strong>','\rm');
TString = strrep(TString,'_','\_');
FixedWidth = get(0,'FixedWidthFontName');
annotation(gcf,'Textbox','String',TString,'Interpreter','Tex','FontName',FixedWidth,'Units','Normalized','Position',[0 0 1 1]);
