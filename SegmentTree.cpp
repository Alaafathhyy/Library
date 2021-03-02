const int N = 1e5, SEG = 2 << (int) ceil(log2(N));
int arr[N], n, q;

struct SEGTREE {
    int seg[SEG];

    void build(int si = 0, int ss = 0, int se = n - 1) {
        if (ss == se) {
            seg[si] = arr[ss];
            return;
        }
        int md = (ss + se) / 2, lf = 2 * si + 1, rt = 2 * si + 2;
        build(lf, ss, md);
        build(rt, md + 1, se);
        seg[si] = min(seg[lf], seg[rt]);
    }

    void update(int qi, int val, int si = 0, int ss = 0, int se = n - 1) {
        if (ss > qi || se < qi)
            return;
        if (ss == se) {
            seg[si] = (arr[ss] = val);
            return;
        }
        int md = (ss + se) / 2, lf = 2 * si + 1, rt = 2 * si + 2;
        update(qi, val, lf, ss, md);
        update(qi, val, rt, md + 1, se);
        seg[si] = min(seg[lf], seg[rt]);
    }

    int query(int qs, int qe, int si = 0, int ss = 0, int se = n - 1) {
        if (ss >= qs && se <= qe) //[qs ss se qe]
            return seg[si];

        if (ss > qe || se < qs) //[qs qe ss se] or [ss se qs qe]
            return INT_MAX;

        int md = (ss + se) / 2, lf = 2 * si + 1, rt = 2 * si + 2;
        int left = query(qs, qe, lf, ss, md);
        int right = query(qs, qe, rt, md + 1, se);
        return min(left, right);
    }
}
