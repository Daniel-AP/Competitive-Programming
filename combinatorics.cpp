#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int powmod(int b, int exp) {

    int ans = 1;
    b %= MOD;

    while(exp) {

        if(exp%2 == 1) {
            ans = (ans%MOD*b%MOD)%MOD;
        }

        b = (b*b)%MOD;
        exp /= 2;

    }

    return ans;

}

int modinv(int a) {
    return powmod(a, MOD-2);
}

int comb(int n, int r) {

    if(n < r) return 0;
    if(n == r || r == 0) return 1;

    r = min(r, n-r);

    int ans = 1;
    for(int i = 0; i < r; i++) {
        ans = (ans*(n-i))%MOD;
        ans = (ans*modinv(i+1))%MOD;
    }

    return ans;

}