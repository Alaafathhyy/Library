
vector<pair<int, ll>> adj[N];
 
ll dis[N];
int n, m, k;
 
int vis[N], vid;
 
ll prim(int src = 0) {
    ll ret = 0;
 
    vid++;
    memset(dis, '?', n * sizeof dis[0]);
    priority_queue<pair<ll, int>> q;
    dis[src] = 0;
    q.emplace(0, src);
    while (!q.empty()) {
        int u = q.top().second;
        ll d = -q.top().first;
        q.pop();
        if (d != dis[u]) continue;
        ret += d;
        vis[u] = vid;
        for (auto &e : adj[u]) {
            int v = e.first;
            ll nd = e.second;
            if (nd < dis[v] && vis[v] != vid) {
                dis[v] = nd;
                q.emplace(-nd, v);
            }
        }
    }
    return ret;
}
 
