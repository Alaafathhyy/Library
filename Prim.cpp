bool vis[N];
int n, m;

vector<pair<ll, ll>> vec[N];

ll prim(int src) {
    ll ans = 0;
    priority_queue<pll, vector<pll >, greater<pll > > q;
    vis[src] = 1;
    for (auto v:vec[src])
        q.emplace(v.second, v.first);
    while (!q.empty()) {
        int u = q.top().second;
        ll c = q.top().first;
        q.pop();
        if (vis[u])continue;
        vis[u] = 1;
        ans += c;
        for (auto a:vec[u]) {
            q.emplace(a.second, a.first);
        }
    }
    return ans;
}
