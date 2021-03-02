
ll dijkstra(int src) {
    memset(dis, '?', sizeof dis);
    priority_queue<pll, vector<pll >, greater<pll > > q;
    dis[src] = 0;
    q.emplace(0, 1);
    while (!q.empty()) {
        int u = q.top().second;
        ll c = q.top().first;
        q.pop();
        if (dis[u] != c)continue;
        if (u == n) return dis[u];
        for (auto a:vec[u]) {
            if (dis[a.first] > a.second + c)
                dis[a.first] = a.second + c, q.emplace(dis[a.first], a.first);
        }
    }
    return -1;
}
