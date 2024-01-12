#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int N = 2 * n;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    // split into intervals [istart, iend]
    // such that nums[istart] > nums[i] for all i in [istart+1, iend]
    vector<pair<int, int>> s; // size, start
    int istart = 0, start = nums[0];

    for (int i = 1; i < N; i++)
    {
        if (nums[i] > start)
        {
            s.push_back({i - istart, istart}); // size, start
            istart = i;
            start = nums[i];
        }
    }
    s.push_back({N - istart, istart}); // size, start
    int S = s.size();

    // knapsack problem, items have weight w, can we fill 2 bags of size n?
    // dp[i+1][a] = can we fill bag of size a with items 0 to i?
    vector<vector<bool>> dp(S + 1, vector<bool>(n + 1, false));
    int w, iend;
    dp[0][0] = true;
    for (int i = 0; i < S; i++)
    {
        w = s[i].first;
        for (int a = 0; a <= n; a++)
        {
            dp[i + 1][a] = (dp[i][a] || (a >= w && dp[i][a - w]));
        }
    }

    if (!dp[S][n])
    {
        cout << -1 << endl;
        return;
    }

    vector<pair<int, int>> A, B;
    int a = n, b = n;
    for (int i = S - 1; i >= 0; i--) // backtracking: fill in reverse order
    {
        w = s[i].first;
        istart = s[i].second;
        iend = s[i].second + s[i].first;

        if (a - w >= 0 && dp[i][a - w])
        {
            A.push_back({istart, iend});
            a -= w;
        }
        else
        {
            B.push_back({istart, iend});
            b -= w;
        }
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (auto p : A)
        for (int i = p.first; i < p.second; i++)
            cout << nums[i] << " ";
    cout << endl;
    for (auto p : B)
        for (int i = p.first; i < p.second; i++)
            cout << nums[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}