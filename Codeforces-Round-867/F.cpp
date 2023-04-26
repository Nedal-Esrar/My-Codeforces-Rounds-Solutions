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

ll n, k, c;

vector<int> adj[(int) 2e5 + 5];

int lvl[(int) 2e5 + 5], dist1[(int) 2e5 + 5], dist2[(int) 2e5 + 5];

int l[(int) 2e5 + 5];

vector<int> v;

int end1, end2, mx;
ll ans;

void findFirstEnd(int u, int p) {
  l[u] = 1 + l[p];

  if (l[u] > mx) {
    mx = l[u];
    end1 = u;
  }

  for (int e : adj[u]) {
    if (e != p) {
      findFirstEnd(e, u);
    }
  }
}

void clear(int n) {
  mx = 0;
  dist1[0] = dist2[0] = -1;
}

void findSecondEnd(int u, int p) {
  lvl[u] = 1 + lvl[p];

  if (lvl[u] > mx) {
    mx = lvl[u];

    end2 = u;
  }

  for (int e : adj[u]) {
    if (e != p) {
      findSecondEnd(e, u);
    }
  }
}

void findDistancefromFirst(int u, int p)
{
  dist1[u] = 1 + dist1[p];

  for (int e : adj[u]) {
    if (e != p) {
      findDistancefromFirst(e, u);
    }
  }
}

void findDistancefromSecond(int u, int p) {
  dist2[u] = 1 + dist2[p];

  for (int e: adj[u]) {
    if (e != p) {
      findDistancefromSecond(e, u);
    }
  }
}

void findDistances(){
  findFirstEnd(1, 0);

  clear(n);

  findSecondEnd(end1, 0);

  findDistancefromFirst(end1, 0);

  findDistancefromSecond(end2, 0);

  for (int i = 1; i <= n; i++) {
    int x = dist1[i];
    int y = dist2[i];

    if (x >= y) {
      v.pb(x);
    }
    else {
      v.pb(y);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  tc {
    cin >> n >> k >> c;

    for (int i = 1; i <= n; ++i) {
      adj[i].clear();
      lvl[i] = dist1[i] = dist2[i] = 0;
    }

    end1 = end2 = mx = 0;

    ans = MIN;

    v.clear();

    v.pb(0);

    for (int i = 0; i < n - 1; ++i) {
      ll u, v;

      cin >> u >> v;

      adj[u].pb(v);
      adj[v].pb(u);
    }

    findDistances();

    for (int i = 1; i <= n; ++i) {
      ans = max(ans, v[i] * k - c * (l[i] - 1));
    }

    cout << ans << el;
  }

  return 0;
}
