#include <bits/stdc++.h>
using namespace std;
#define BASE 257
#define MOD 202206214218227LL
vector <long long> digests;

long long generateHash(string &s)
{
    long long H = 0;
    for (auto &c : s)
    {
        H = ((H * BASE) + c) % MOD;
    }
    return H;
}

int main()
{
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        auto H = generateHash(s);
        digests.push_back(H);
    }
    int q;
    cin >> q;
    sort(digests.begin(), digests.end());
    while (q--)
    {
        cin >> s;
        if (binary_search(digests.begin(), digests.end(), generateHash(s)))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}
