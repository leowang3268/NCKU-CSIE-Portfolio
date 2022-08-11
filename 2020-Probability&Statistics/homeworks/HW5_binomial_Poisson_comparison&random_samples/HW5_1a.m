function result = HW5_1a(x, n, p)
    result = nchoosek(n, x) * (p^x) * (1-p)^(n-x);
    