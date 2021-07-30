
const int N = 1000001;// NCR
const int mod =1e9+7;
ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];
void InverseofNumber()
{     ll p=mod;
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial()
{    ll p=mod;
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial()
{    ll p=mod;
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
ll Binomial(ll N, ll R)
{    ll p=mod;
    ll ans = ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R])% p;
    return ans;
}
void precompute()
{
    InverseofNumber();
    InverseofFactorial();
    factorial();
    //cout << Binomial(N, R) << endl;
}
