#include <bits/stdc++.h>

long long binexp(long long a, long long b) {
    assert(b >= 0);
    if (b == 0)
        return 1;
    
    long long x = binexp(a, b / 2);
    long long res = x * x; // careful, may overflow
    if (b % 2)
        return  res * a;
    return res;
}

long long binexp(long long a, long long b, long long M) {
    assert(a >= 0 and b >= 0);
    if (b == 0)
        return 1 % M;
    
    long long x = binexp(a, b / 2, M);
    long long res = (x * x) % M; // careful, may overflow
    if (b % 2)
        return (res * a) % M;
    return res;
}