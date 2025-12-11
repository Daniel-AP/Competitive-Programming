#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {

    int ans = n;
    
    while(--n) ans *= n;

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    cout << factorial(min(a, b)) << endl;

    return 0;

}