#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int result = 0;
        int s;

        cin >> s;

        while(s) {

            int spend = 10*(s/10) == 0 ? s : 10*(s/10);
            int cashback = spend/10;

            s -= spend-cashback;
            result += spend;
            
        }

        cout << result << endl;

    }

    return 0;

}