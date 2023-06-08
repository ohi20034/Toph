#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int MAX = 1e5;
bool prime[MAX];
int largePrimeRange[MAX];
void Sieve()
{
    memset(prime, true, sizeof prime);
    memset(largePrimeRange, -1, sizeof largePrimeRange);
    prime[1] = false;
    for (int i = 2; i * i <= MAX; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                prime[j] = false;
            }
        }
    }
    int largePrime = -1;
    for (int i = 2; i <= MAX; ++i)
    {
        if (prime[i])
        {
            largePrime = i;
        }
        largePrimeRange[i] = largePrime;
    }
}
void sol()
{
    int l, r;
    cin >> l >> r;
    if (largePrimeRange[r] < l)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << largePrimeRange[r] << endl;
    }
}
int32_t main()
{
    Sieve();
    //_ohi_
    int t;
    cin >> t;
    while (t--)
    {
        sol();
        // cout << '\n';
    }
    return 0;
}
