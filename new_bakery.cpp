#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        long long n, a, b;
        cin >> n >> a >> b;

        long long l(0), r(min(n, b)), mid;
        long long k = 0;

        mid = l+(r-l)/2;

        while(l <= r) {

            mid = l+(r-l)/2;

            if(b-mid+1 > a) {
                k = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }

        }

        cout << k*(b+b-k+1)/2 + a*(n-k) << endl;

    }

    return 0;

}