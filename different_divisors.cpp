#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {

    if(n <= 2) return {};

    int m = n/2;
    vector<bool> s(m, true);
    vector<int> primes = {2};

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

    return primes;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int d;
        cin >> d;

        vector<int> primes = sieve(1e5);

        int p1 = *lower_bound(primes.begin(), primes.end(), d+1);
        int p2 = *lower_bound(primes.begin(), primes.end(), p1+d);

        cout << p1*p2 << endl;

    }

    return 0;

}