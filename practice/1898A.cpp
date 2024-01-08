#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> B(n + 1), A(n + 1);
    char c;
    for (int i = 0; i < n; i++)
    {
        cin >> c;

        B[i + 1] = B[i] + (c == 'B');
        A[i + 1] = A[i] + (c == 'A');
    }

    if (B[n] == k)
    {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    if (B[n] < k)
    {
        for (int i = 0; i <= n; i++)
        {
            if (A[i] == k - B[n])
            {
                cout << i << " B" << endl;
                return;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (B[i] == B[n] - k)
        {
            cout << i << " A" << endl;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
