#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        long long n, h;
        cin >> n >> h;

        long long first = -1e18;
        long long second = -1e18;
        vector<long long> damage(n);

        for(int i = 0; i < n; i++) {

            cin >> damage[i];

            if(damage[i] > first) {
                second = first;
                first = damage[i];
            }
            else if(damage[i] > second) second = damage[i];

        }

        long long l(1), r(h);
        long long mid = l+(r-l)/2;
        long long result = 0;

        while(l <= r) {

            mid = l+(r-l)/2;

            if((mid/2+mid%2)*first+(mid/2)*second >= h) {
                result = (mid/2+mid%2)+(mid/2);
                r = mid-1;
            } else {
                l = mid+1;
            }

        }

        cout << result << endl;

    }

    return 0;

}