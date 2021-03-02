struct BIT {
    vector<ll> v;
    int sz;
 
    explicit BIT(int n) {
        v.resize(n);
        sz = n;
    }
 
    //gets sum of range [0, i]
    ll get(int i) {
        ll ret = 0;
        for (++i; i; i -= i & -i)
            ret += v[i - 1];
        return ret;
    }
 
    void update(int i, ll x) {
        for (++i; i <= sz; i += i & -i)
            v[i - 1] += x;
    }
 
    ll query(int st, int en) {
        return get(en) - get(st - 1);
    }
};
