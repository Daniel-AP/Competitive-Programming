#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    long long expected = n*(n+1)/2;
    long long l(0), r(1e5), mid, added;

    while(l <= r) {
        mid = l+(r-l)/2;
        if(mid*(mid+3) <= 2*k+2*n) {
            added = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << n-added << endl;

    return 0;

}