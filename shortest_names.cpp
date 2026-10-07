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

    int query(const string& s) {

        int node = 0, cnt = 0;

        for(char c: s) {
            int x = c-'a';
            if(trie[node].cnt == 1) break;
            cnt++;
            node = trie[node].next[x];
        }

        return cnt;

    }

};

void solve() {

    int n; cin >> n;

    Trie trie;
    vector<string> a(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        trie.insert(a[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) ans += trie.query(a[i]);

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}