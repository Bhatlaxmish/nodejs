
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007

#define powe pow(2, 31)
ll araisetobwithmod(ll base, ll exp)
{
    ll result = 1;
    for (;;)
    {
        if (exp & 1)
            result = (result * base) % mod;
        ;
        exp >>= 1;
        if (!exp)
            break;
        base = (base * base) % mod;
    }

    return result;
}
ll factorialwithmod(ll n)
{
    if (n >= mod)
        return 0;

    ll result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % mod;

    return result;
}
bool isprimeornot(ll n)
{
    if (n == 1)
    {
        return false;
    }
    ll i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            return false;
        }
        i += 1;
    }
    return true;
}

ll araisetob(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a);
        }
        a = (a * 1LL * a);
        b >>= 1;
    }
    return ans;
}
bool isperfectsquareornot(ll x)
{
    if (sqrt(x) * sqrt(x) == x)
    {
        return true;
    }
    return false;
}
bool ispoweroftwoornot(ll n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}
ll factorial(ll n)
{

    return (n == 1 || n == (ll)0) ? (ll)1 : n * factorial(n - 1);
}
ll maximumsubarraysum(vector<int> a, ll size)
{
    ll currmax = -1111111111, until = 0;

    for (ll i = 0; i < size; i++)
    {
        until = until + a[i];
        if (currmax < until)
            currmax = until;

        if (until < 0)
            until = 0;
    }
    return currmax;
}
bool ispalindromeornot(string s, ll n)
{
    ll l = 0;
    ll h = n - 1;
    while (h > l)
    {
        if (s[l++] != s[h--])
        {

            return false;
        }
    }
    return true;
}

ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll araisetobwithmodeasy(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)

            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

ll ncr(ll n, ll r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    vector<ll> fact(n + 1);
    vector<ll> ifact(n + 1);
    int i;
    fact[0] = 1;
    for (i = 1; i <= n; i++)
    {
        fact[i] = i * fact[i - 1] % mod;
    }
    i--;
    ifact[i] = araisetobwithmod(fact[i], mod - 2);
    for (i--; i >= 0; i--)
    {
        ifact[i] = ifact[i + 1] * (i + 1) % mod;
    }
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % mod) * val3) % mod;
}

ll countnoofdivisors(int n)
{
    ll cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            // cout<<i<<" ";
            if (i != (n / i))
            {
                cnt++;
                // cout<<n/i<<" ";
            }
        }
    }
    return cnt;
}
int rotateBinary(int number)
{
    int res = 0;
    while (number > 0)
    {
        res = res << 1;
        res = res | (number & 1);
        number = number >> 1;
    }
    return res;
}

void dfs(vector<int> adj[], vector<bool> &visited, int i)
{
    visited[i] = true;
    // cout<<i<<" ";
    for (auto x : adj[i])
    {
        if (!visited[x])
        {
            dfs(adj, visited, x);
        }
    }
}

void SieveOfEratosthenes(ll int n)
{

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (ll int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {

            for (ll int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
bool compi(pair<int, int> v1, pair<int, int> v2)
{
    return v1.second < v2.second;
}
int upperbound(vector<pair<int, int>> d, int r)
{
    ll int low = 0;
    ll int index = -1;
    ll int high = d.size();
    while (low <= high)
    {
        ll int mid = (low + high) / 2;
        if (d[mid].first > r)
        {
            index = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return index;
}
int main()
{

    //    bool ispalindromeornot(string s, ll n)
    //    ll factorial(ll n)
    //    ll factorialwithmod(ll n)
    //    bool ispoweroftwoornot(ll n)
    //    bool isperfectsquareornot(ll x)
    //    bool isprimeornot(ll n)
    //    ll araisetobwithmod(ll base, ll exp)
    //    ll araisetob(ll a, ll b)
    //    bool powof2ornot(ll x)
    //    ll maximumsubarraysum(vector<int>a, ll size)
    //    ll countnoofdivisors(int n)
    //    ll ncr(ll n, ll r)
    //    ll araisetobwithmodeasy(ll a, ll b)
    //    ll gcd(ll a, ll b)
    //    void dfs(int c,vector<int>adj[],vector<int>v,vector<bool>visited,int n)
    //    ll countnoofdivisors(int n)
    // float rt= ((float) a/(float) c);
    // pos[s[z]-'a'].push_back(z);
    int t;
    cin >> t;
    while (t--)
    {
        // https://codeforces.com/problemset/problem/1555/B
        int n, m;
        cin >> n >> m;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int q, p;
        int sum = 0;
        cin >> p >> q;
        if ((n - x2 - x1 < p && p > n) || (m - y2 - y1 < q && q > m))
        {
            cout << -1 << "\n";
       }
       else {

        if(n-x2<p)
        {
            if(x1<p)
            {
                sum+=p-max(n-x2,x1);
            }


        }
        if(m-y2<q)
        {
            if(y1<q)
            {
                sum+=q-max(m-y2,y1);
            }
        }
        cout<<sum<<"\n";
       }
       
        

        
    }
}
