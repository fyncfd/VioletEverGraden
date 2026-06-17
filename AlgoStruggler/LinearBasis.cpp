i64 ksm(i64 a, i64 b, i64 p) {
    i64 res = 1;
    while (b) {
        if (b & 1) {
        	res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 x, i64 p) {
    return ksm(x, p - 2, p);
}