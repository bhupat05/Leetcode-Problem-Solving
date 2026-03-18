// Last updated: 3/18/2026, 2:20:37 PM
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

ull mulmod(ull a, ull b, ull mod) {
    ull result = 0;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            result = (result + a) % mod;
        }
        a = (a << 1) % mod;
        b >>= 1;
    }
    return result;
}

ull powmod(ull base, ull exponent, ull mod) {
    ull result = 1 % mod;
    ull cur = base % mod;
    while (exponent > 0) {
        if (exponent & 1) result = mulmod(result, cur, mod);
        cur = mulmod(cur, cur, mod);
        exponent >>= 1;
    }
    return result;
}

bool millerTest(ull d, ull n, ull a) {
    ull x = powmod(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (d != n - 1) {
        x = mulmod(x, x, n);
        d <<= 1;
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}

bool isPrime(ull n) {
    if (n < 2) return false;
    static const vector<ull> smallPrimes = {2,3,5,7,11,13,17,19,23};
    for (auto p : smallPrimes) {
        if (n == p) return true;
        if (n % p == 0 && n != p) return false;
    }
    ull d = n - 1;
    while ((d & 1) == 0) d >>= 1;
    vector<ull> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (auto a : bases) {
        if (a % n == 0) return true;
        if (!millerTest(d, n, a)) return false;
    }
    return true;
}

class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        int n = (int)s.size();
        unordered_set<ull> primes;
        for (int i = 0; i < n; i++) {
            ull num = 0;
            for (int j = i; j < n; j++) {
                if (j > i && s[i] == '0') break;
                num = num * 10 + (s[j] - '0');
                if (isPrime(num)) primes.insert(num);
                if (num > 1e18) break;
            }
        }
        vector<ull> v(primes.begin(), primes.end());
        sort(v.rbegin(), v.rend());
        long long ans = 0;
        for (int i = 0; i < (int)v.size() && i < 3; i++) {
            ans += v[i];
        }
        return ans;
    }
};
