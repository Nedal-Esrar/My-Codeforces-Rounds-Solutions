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

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  tc {
    ll n;

    cin >> n;

    map<ll, set<array<ll, 3>>> mp;

    for (ll i = 1; i < n; ++i) {
      ll u, v;

      cin >> u >> v;

      mp[u].insert({i, u, v});
      mp[v].insert({i, u, v});
    }

    set<array<ll, 3>> later, now;

    ll cnt_edge = 0, ans = 0;

    for (array<ll, 3> arr : mp[1]) {
      now.insert(arr);
      mp[max(arr[1], arr[2])].erase(arr);
    }

    mp[1].clear();

    map<ll, bool> used;

    used[1] = 1;

    while (cnt_edge != n - 1) {
      while (!now.empty()) {
        auto edge = *now.begin();

//        cout << edge[0] << ' ' << edge[1] << ' ' << edge[2] << el;

        now.erase(edge);

        ++cnt_edge;

        if (used[edge[1]] && used[edge[2]]) {
          nxt;
        }

        ll not_used = used[edge[1]] ? edge[2] : edge[1];

        used[not_used] = 1;

        for (auto arr : mp[not_used]) {
          if (arr[0] < edge[0]) {
            later.insert(arr);
          }
          else {
            now.insert(arr);
          }

          mp[not_used ^ arr[1] ^ arr[2]].erase(arr);
        }

        mp[not_used].clear();
      }

      ++ans;

      now = later;
      later.clear();
    }

    cout << ans << el;
  }

  return 0;
}
