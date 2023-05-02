// EIEN

#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

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

const ll MOD = 1e9 + 7, OO = 1e15;
const double PI = 4 * atan(1), EPS = 1e-7;

const ll N = 2e3 + 5;

ll n, m;

bool found;

set<ll> adj[N];

set<ll> vis;
vector<ll> cyc;

void dfs(ll x, ll start) {
  if (vis.count(x)) {
    return;
  }

  vis.insert(x);

  cyc.pb(x);

  if (sz(cyc) > 2 && adj[x].find(start) != adj[x].end()) {
    found = 1;
    return;
  }

  for (ll e : adj[x]) {
    dfs(e, start);

    if (found) {
      return;
    }
  }

  cyc.pop_back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  tc {
    cin >> n >> m;

    for (ll i = 1; i <= n; ++i) {
      adj[i].clear();
    }

    for (ll i = 0; i < m; ++i) {
      ll u, v;

      cin >> u >> v;

      adj[u].insert(v);
      adj[v].insert(u);
    }

    found = 0;

    set<pair<ll, ll>> ans;

    for (ll i = 1; i <= n && !found; ++i) {
      if (sz(adj[i]) >= 4) {
        vis.clear();
        cyc.clear();

        dfs(i, i);
        
        if (found) {
          for (ll j= 0; j < sz(cyc); ++j) {
            ans.insert({cyc[j], cyc[(j + 1) % sz(cyc)]});
          }

          ll cnt = 0;

          for (ll e : adj[i]) {
            if (cnt == 2) {
              break;
            }

            if (ans.count({i, e}) || ans.count({e, i})) {
              nxt;
            }

            ans.insert({i, e});

            ++cnt;
          }
        }
      }
    }

    if (found) {
      cout << "YES\n" << sz(ans) << el;

      for (auto& [f, s] : ans) {
        cout << f << ' ' << s << el;
      }
    }
    else {
      cout << "NO\n";
    }
  };

  return 0;
}
