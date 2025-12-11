#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll count_digits_before(ll n) {

    ll count = 0;
    ll place = 1;

    while(place <= n) {

        ll higher = n/(place*10);
        ll current = (n/place)%10;
        ll lower = n%place;

        count += higher * place;

        if(current > 1) {
            count += place;
        } else if(current == 1) {
            count += lower+1;
        }

        place *= 10;

    }

    return count;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll l(1), r(1e18), mid, result(1);

    while(l <= r) {
        mid = l+(r-l)/2;
        ll count_before = count_digits_before(mid);
        if(count_before <= n) {
            result = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << result << endl;

    return 0;

}