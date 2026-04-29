#include <bits/stdc++.h>
using namespace std;

#define int long long

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

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << isPrime(9780995117389) << '\n';

    return 0;

}