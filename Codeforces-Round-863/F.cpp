// EIEN

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define fr first
#define sc second
#define pb(x) push_back(x)
#define nxt continue
#define sz(container) ((ll) container.size())
#define umap unordered_map
#define uset unordered_set
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define mkpr(f, s) make_pair(f, s)
#define el '\n'
#define mxpq priority_queue
#define tc int T; cin >> T; while (T--)
#define ld long double

template <class T>
using mnpq = mxpq<T, vector<T>, greater<T>>;

template <class T, class S>
using oset = tree<T, null_type, S, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 1e9 + 7, OO = 1e9;
const double PI = 4 * atan(1), EPS = 1e-7;

int no_of_ver(int x, vector<set<int>>& adj, vector<bool>& vis) {
  if (vis[x]) {
    return 0;
  }

  vis[x] = 1;

  int ret = 1;

  for (ll e:  adj[x]) {
    ret += no_of_ver(e, adj, vis);
  }

  return ret;
}

void solve() {
  int n, m;

  cin >> n >> m;

  vector<set<int>> adj(n);

  for (int i = 0; i < m; ++i) {
    int u, v;

    cin >> u >> v;

    adj[--u].insert(--v);
    adj[v].insert(u);
  }

  int k = sqrt(n);

  if (k * k != n || k * (k + 1) != m) {
    cout << "NO\n";
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (sz(adj[i]) != 2 && sz(adj[i]) != 4) {
      cout << "NO\n";
      return;
    }
  }

  vector<bool> vis(n);

  if (no_of_ver(0, adj, vis) != n) {
    cout << "NO\n";
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (sz(adj[i]) == 2) {
      nxt;
    }

    // disconnect center
    vector<int> v(adj[i].begin(), adj[i].end());

    for (int e : v) {
      if (sz(adj[e]) > 2) {
        adj[e].erase(i);
        adj[i].erase(e);
      }
    }
  }

  vis = vector<bool>(n);

  for (int i = 0; i < n; ++i) {
    if (!vis[i] && no_of_ver(i, adj, vis) != k) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  tc {
    solve();
  };

  return 0;
}
