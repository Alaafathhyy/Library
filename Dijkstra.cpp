vector<pair<int,int>>adj;
int dist[N];
void dijkstra(int src) {
    memset(dis, '?', n * sizeof dis[0]);
    priority_queue<pair<ll, int>> q;
    dis[src] = 0;
    q.emplace(0, src);
    while (!q.empty()) {
        int u = q.top().second;
        ll d = -q.top().first;
        q.pop();
        if (d != dis[u]) continue;
        for (auto &e : adj[u]) {
            int v = e.first;
            ll nd = dis[u] + e.second;
            if (nd < dis[v]) {
                dis[v] = nd;
                q.emplace(-nd, v);
            }
        }
    }
}
