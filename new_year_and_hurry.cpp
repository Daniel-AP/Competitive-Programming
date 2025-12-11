#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int l(0), r(n);
    int mid = l+(r-l)/2;
    int available = 4*60-k;

    while(l <= r) {

        mid = l+(r-l)/2;
        int total_mid = 5*mid*(mid+1)/2;

        if(total_mid > available) r = mid-1;
        else l = mid+1;
    }

    cout << r << endl;

    return 0;

}