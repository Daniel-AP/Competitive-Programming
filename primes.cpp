#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> primes{2};

void sieve(int n) {

    if(n <= 2) return;

    int m = n/2;
    vector<bool> s(m, true);

    for(int i = 3; i*i < n; i += 2) {
        if(s[i/2]) {
            for(int j = (i*i)/2; j < m; j += i) {
                s[j] = false;
            }
        }
    }

    for(int i = 1; i < m; i++) {
        if(s[i]) primes.push_back(2*i+1);
    }

}

bool isPrime(int n) {

    if(n <= 3) return n > 1;

    if(n%2 == 0 || n%3 == 0) return false;

    for(int i = 5; i*i <= n; i += 6) {
        if(n%i == 0 || n%(i+2) == 0) return false;
    }

    return true;

}

vector<int> primeFactors(int n) {

    vector<int> factors;

    while(n%2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    while(n%3 == 0) {
        factors.push_back(3);
        n /= 3;
    }

    for(int i = 5; i < (int)sqrt(n)+1; i += 6) {
        while(n%i == 0) {
            factors.push_back(i);
            n /= i;
        }
        while(n%(i+2) == 0) {
            factors.push_back(i+2);
            n /= (i+2);
        }
    }

    if(n != 1) factors.push_back(n);

    return factors;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << isPrime(9780995117389) << '\n';

    return 0;

}