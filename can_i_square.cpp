#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        long long n, sum(0);
        cin >> n;

        for(long long i = 0; i < n; i++) {

            int w;
            cin >> w;

            sum += w;

        }

        long long l(1), r(sum);
        unsigned long long mid = l+(r-l)/2;
        unsigned long long squared = mid*mid;

        while(l <= r) {

            mid = l+(r-l)/2;

            squared = mid*mid;

            if(squared == sum) break;
            else if(squared > sum) r = mid-1;
            else l = mid+1;

        }

        cout << (squared == sum ? "YES" : "NO") << endl;

    }

    return 0;

}