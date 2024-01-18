#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int solve()
{
    int n;
    string num;
    cin >> n;
    // [num digits][sum in first n, sum in remaining]
    vector<vector<map<pair<int, int>, int>>> cnt(5, vector<map<pair<int, int>, int>>(5));
    while (n--)
    {
        cin >> num;
        int sum = 0, curr = 0, L = num.size();
        for (int i = 0; i < L; i++)
            sum += num[i] - '0';
        for (int i = 0; i < L; i++)
        {
            curr += num[i] - '0';
            cnt[L - 1][i][{curr, sum - curr}]++;
        }
    }
    int ans = 0;

    // L1 == L2
    for (int L = 0; L < 5; L++)
        for (auto &p1 : cnt[L][L])
            ans += p1.second * p1.second;

    // L1 < L2
    for (int L1 = 0; L1 < 5; L1++)
        for (int L2 = L1 + 2; L2 < 5 && L1 + L2 < 8; L2 += 2)
        {
            int split = (L1 + L2) / 2 - L1 - 1;
            for (auto &p1 : cnt[L1][L1])
                for (auto &p2 : cnt[L2][split])
                {
                    int LHS = p1.first.first + p2.first.first;
                    int RHS = p2.first.second;
                    if (LHS == RHS)
                        ans += p1.second * p2.second;
                }
            split = (L1 + L2) / 2;
            for (auto &p1 : cnt[L2][split])
                for (auto &p2 : cnt[L1][L1])
                {
                    int LHS = p1.first.first;
                    int RHS = p1.first.second + p2.first.first;
                    if (LHS == RHS)
                        ans += p1.second * p2.second;
                }
        }

    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << solve() << "\n";
    return 0;
}