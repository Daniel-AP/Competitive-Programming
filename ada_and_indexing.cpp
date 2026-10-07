#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Trie {
    struct Node {
        array<int, 26> next;
        int cnt = 0;       // strings passing through this node
        int end = 0;       // strings ending at this node

        Node() {
            next.fill(-1);
        }
    };

    vector<Node> trie;

    Trie() {
        trie.emplace_back();  // root
    }

    void insert(const string& s) {
        int node = 0;
        trie[node].cnt++;

        for (char c : s) {
            int x = c - 'a';

            if (trie[node].next[x] == -1) {
                trie[node].next[x] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].next[x];
            trie[node].cnt++;
        }

        trie[node].end++;
    }

    int count(const string& s) {
        int node = 0;

        for (char c : s) {
            int x = c - 'a';

            if (trie[node].next[x] == -1)
                return 0;

            node = trie[node].next[x];
        }

        return trie[node].end;
    }

    bool contains(const string& s) {
        return count(s) > 0;
    }

    int count_prefix(const string& s) {
        int node = 0;

        for (char c : s) {
            int x = c - 'a';

            if (trie[node].next[x] == -1)
                return 0;

            node = trie[node].next[x];
        }

        return trie[node].cnt;
    }

    bool erase(const string& s) {
        if (!contains(s))
            return false;

        int node = 0;
        trie[node].cnt--;

        for (char c : s) {
            node = trie[node].next[c - 'a'];
            trie[node].cnt--;
        }

        trie[node].end--;
        return true;
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
        cout << trie.count_prefix(s) << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}