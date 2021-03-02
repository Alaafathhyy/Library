//Iterative method
void ncr(int n,int k){
 
        k = min(k, n - k);
        for (int i = 1; i <= k; i++) {
            ans = ans * (n - k + i) / i;
        }
        cout << ans << endl;
} 
ll fact[N];
 
void compFact() {
    fact[0] = 1;
    for (ll i = 1; i < N; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
ll nCr(ll n, ll r) {
    ll ret = fact[n];
    ret = (ret * fastPow(fact[r])) % MOD;
    ret = (ret * fastPow(fact[n - r])) % MOD;
    return ret;
}
