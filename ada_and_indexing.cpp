#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Trie {
    struct Node {
        Node* nxt[26]{};
        int cnt = 0;
        bool end = false;
    };

    Node* root = new Node();

    void insert(const string& s) {
        Node* cur = root;
        for(char c: s) {
            int x = c-'a';
            if(!cur->nxt[x]) cur->nxt[x] = new Node();
            cur = cur->nxt[x];
            cur->cnt++;
        }
        cur->end = true;
    }

    int count(const string& s) {
        Node* cur = root;
        for(char c: s) {
            int x = c-'a';
            if(!cur->nxt[x]) return 0;
            cur = cur->nxt[x];
        }
        return cur->cnt;
    }

};

void solve() {

    int n, q; cin >> n >> q;

    Trie trie;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        trie.insert(s);
    }

    for(int i = 0; i < q; i++) {
        string s; cin >> s;
        cout << trie.count(s) << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}