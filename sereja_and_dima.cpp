#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> cards(n);
    for(int i = 0; i < n; i++) cin >> cards[i];

    int sereja = 0;
    int dima = 0;

    int i = 0;
    int j = n-1;

    while(i <= j) {
        if((i+n-1-j)%2 == 0) {
            sereja += max(cards[i], cards[j]);
        } else {
            dima += max(cards[i], cards[j]);
        }
        if(cards[i] > cards[j]) i++;
        else j--;
    }

    cout << sereja << " " << dima << endl;

    return 0;

}