#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        int a = 0;
        int k = 0;
        int p = 1;

        while(p <= n) {

            int digit = n/p%10;
            int left = n/(p*10);
            int right = n%p;

            if(left) a += 9;
            else if(right >= digit*k) a += digit;
            else a += digit-1;

            k += p;
            p *= 10;

        }

        cout << a << endl;

    }

    return 0;

}