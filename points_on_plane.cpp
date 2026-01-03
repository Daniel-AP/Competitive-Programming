#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        long long n;
        cin >> n;

        long long l(0), r(pow(2, 32)), mid;

        mid = l+(r-l)/2;

        while(l <= r) {
        
            mid = l+(r-l)/2;

            if(mid*mid < n) l = mid+1;
            else r = mid-1;

        }

        cout << r << endl;

    }

    return 0;

}