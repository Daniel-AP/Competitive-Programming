#include <bits/stdc++.h>
using namespace std;

unordered_set<int> sieve(int n) {

    if(n <= 2) return {};

    vector<bool> is_prime(n+1, true);
    unordered_set<int> primes;
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i*i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) primes.insert(i);
    }

    return primes;

}

void unbounded_sieve(function<void(int)> callback, function<bool(int)> shouldContinueGen) {

    bool continueGen = shouldContinueGen(2);

    if(!continueGen) return;

    callback(2);
    unordered_map<int, vector<int>> counter;

    for(int i = 3;;i += 2) {

        if(counter.find(i) != counter.end()) {
            
            for(int step: counter[i]) {
                counter[2*step+i].push_back(2*step+i);
            }

            counter.erase(i);
            continue;

        }

        counter[i*i] = {i};
        continueGen = shouldContinueGen(i);

        if(continueGen) callback(i);
        else return;
        
    }

}

bool isPrime(int n) {

    if(n <= 3) return n > 1;

    if(n%2 == 0 or n%3 == 0) return false;

    for(int i = 5; i < (int)sqrt(n)+1; i += 6) {
        if(n%i == 0 or n%(i+2) == 0) return false;
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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;

}