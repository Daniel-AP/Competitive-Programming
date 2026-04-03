#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> primes{2};

const int N = 1000000;
vector<int> spf(N+1);

void sieve() {

    for(int i = 2; i <= N; i++) spf[i] = i;

    for(int i = 2; i*i <= N; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

}

// meter antes 2 en PRIMES
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

// linear sieve
void sieve(int n) {

    if(n <= 2) return;

    int m = n/2;
    vector<bool> s(m, true);
    s[0] = false;

    for(int i = 1; i < m; i++) {
        int x = 2*i + 1;

        if(s[i]) primes.push_back(x);

        for(int p : primes) {
            if(p == 2) continue;
            if(x*p >= n) break;
            s[(x*p)/2] = false;
            if(x%p == 0) break;
        }
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

map<int, int> primeFactors(int n) {

    map<int, int> factors;

    while(n%2 == 0) {
        factors[2]++;
        n /= 2;
    }

    while(n%3 == 0) {
        factors[3]++;
        n /= 3;
    }

    for(int i = 5; i*i <= n; i += 6) {
        while(n%i == 0) {
            factors[i]++;
            n /= i;
        }
        while(n%(i+2) == 0) {
            factors[i+2]++;
            n /= (i+2);
        }
    }

    if(n != 1) factors[n]++;

    return factors;

}

vector<int> primes;
bitset<M> s;

void sieve() {

    s.set();

    for(int i = 3; i*i < N; i += 2) {
        if(s[i/2]) {
            for(int j = (i*i)/2; j < M; j += i) {
                s[j] = false;
            }
        }
    }

    for(int i = 1; i < M; i++) {
        if(s[i]) primes.push_back(2*i+1);
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << isPrime(9780995117389) << '\n';

    return 0;

}