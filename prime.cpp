#include <bits/stdc++.h>

using namespace std;

class prime_helper {
    int limit;
    vector<bool> sieve;

public:
    prime_helper(int n) {
        assert (n > 1);
        limit = n;
        sieve.resize(n + 1);
        fill(sieve.begin(), sieve.end(), true);

        for (int i = 4; i <= n; i += 2)
            sieve[i] = false;
        
        for (long long i = 3; i <= n; i += 2)
            for (long long j = i * i; j <= n; j += 2 * i)
                sieve[j] = false; 
    }

    int is_prime(int x) {
        assert (x > 1 and x <= limit);
        return sieve[x];
    }
};

int main() {
    prime_helper ph(100);
    for (int i = 2; i <= 30; i++)
        cout << i << " " << ph.is_prime(i) << '\n';
    return 0;
}