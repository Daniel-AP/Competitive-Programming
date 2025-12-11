#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int l(1), r(a*c/b), mid, result;

    while(l <= r) {
        mid = l+(r-l)/2;
        if((mid+c)*b >= a*c) {
            result = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << result << endl;

    return 0;

}