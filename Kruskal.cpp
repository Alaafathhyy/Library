typedef long long ll;
const int N = 1e5 + 7, M = 2 * N;
 
struct DSU {
    int par[N], sz[N], nSets;
 
    void init(int nNodes) {
        nSets = nNodes;
        iota(par, par + nNodes, 0); //par[i] = i
        fill(sz, sz + nNodes, 1);
    }
 
    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }
 
    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return 0;
 
        if (sz[u] > sz[v]) swap(u, v);
        nSets--;
        par[u] = v;
        sz[v] += sz[u];
 
        return 1;
    }
};
 
DSU dsu;
 
int n, m;
 
int from[M], to[M], cst[M], sorted[M];
 
unsigned int kruskal() {
    dsu.init(n);
    sort(sorted, sorted + m, [](int a, int b) {
        return cst[a] < cst[b];
    });
    int res = 0;
    for (int i = 0; i < m; ++i) {
        int e = sorted[i];
        if (dsu.join(from[e], to[e])) {
            res += cst[e];
        }
    }
    return res;
}
