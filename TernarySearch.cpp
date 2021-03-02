ll go(ll k) {}
 
ll dif = 1e9, val;
ll L,R;
void ternary(ll l, ll r) {
    if (r - l <=100) {
        ll ret;
        for (int kk = l; kk <= r; ++kk) {
            ret = go(kk);
            if (ret < dif) {
                dif = ret;
                val = kk;
            }
        }
        return;
    }
    ll div = (r - l) / 3.0;
    ll mid1 = l + div;
    ll mid2 = l + div + div;
    ll mid = (mid1 + mid2) / 2.0;
 
    ll valmid1 = go(mid1);
    ll valmid2 = go(mid2);
    ll valmid = go(mid);
 
    if (valmid <= valmid1 && valmid <= valmid2) {
        ternary(mid1, mid2);
    } else if (valmid >= valmid1 && valmid2 >= valmid) {
        ternary(l, mid2);
    } else if (valmid <= valmid1 && valmid2 <= valmid) {
        ternary(mid1, r);
    }
}
