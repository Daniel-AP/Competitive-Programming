#include <bits/stdc++.h>
using namespace std;

unordered_set<int> factors(int n) {

    unordered_set<int> f;

    while(n%2 == 0) {
        f.insert(2);
        n /= 2;
    }
    while(n%3 == 0) {
        f.insert(3);
        n /= 3;
    }

    for(int i = 5; i*i <= n; i += 6) {
        while(n%i == 0) {
            f.insert(i);
            n /= i;
        }
        while(n%(i+2) == 0) {
            f.insert(i+2);
            n /= (i+2);
        }
    }

    if(n != 1) f.insert(n);

    return f;

}

void solve() {

    int n;
    cin >> n;

    int count = 0;
    
    for(int i = 1; i <= n; i++) {
        unordered_set<int> f = factors(i);
        if(f.size() == 2) count++;
    }

    cout << count << endl;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}