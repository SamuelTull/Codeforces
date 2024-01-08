#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve(int n, vector<long long> a, vector<long long> b)
{
    long long d, ans = 0;

    for (int i = 0; i < n; i++)
    {
        d = min(a[i], b[i]);
        ans += d;
        a[i] -= d;

        if (i < n - 1)
        {
            d = a[i];
            a[i] -= d;
            a[i + 1] += d;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;

    vector<long long> pref_a(n + 1), pref_b(n + 1);
    pref_a[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> pref_a[i + 1];
        pref_a[i + 1] += pref_a[i];
    }
    pref_b[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> pref_b[i + 1];
        pref_b[i + 1] += pref_b[i];
    }

    long long temp;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
    }

    long long p, x, y, z, da, db;
    while (q--)
    {

        cin >> p >> x >> y >> z;
        da = x - (pref_a[p] - pref_a[p - 1]);
        db = y - (pref_b[p] - pref_b[p - 1]);

        for (int i = p; i < n + 1; i++)
        {
            pref_a[i] += da;
            pref_b[i] += db;
        }

        cout << min(pref_a[n], pref_b[n]) << "\n";
    }

    return 0;
}
