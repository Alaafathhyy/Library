#define MAXN   100001 
int spf[MAXN]; 
 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
 
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
 
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

int mult(ll x, ll y, ll &mod) {
    return (1LL * (x%mod) * (y%mod))%mod;
}
 
ll add(ll x, ll y) {
    return (x + y) % MOD;
}
 
ll sub(ll x, ll y) {
    return (x - y + MOD) % MOD;
}
ll fastPow(ll a, int p = MOD - 2, int m = MOD) {
    if (p == 0)
        return 1;
    if (p % 2 == 1)
        return (a * fastPow(a, p - 1, m)) % m;
    ll c = fastPow(a, p / 2, m);
    return (c * c) % m;
}

long long int mult(long long int x,long long int y)
{
    long long int ans =1;
    while(y>0)
    {
        if(y%2)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        y=y>>1;

    }
    return ans;
}
