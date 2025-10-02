#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k; 
        cin >> n >> k;
        vector<int> a(n), tot(n+1, 0);
        for (int i = 0; i < n; ++i) { cin >> a[i]; tot[a[i]]++; }

        // If any value's total count isn't divisible by k, answer is 0.
        bool ok = true;
        for (int v = 1; v <= n; ++v) if (tot[v] % k != 0) { ok = false; break; }
        if (!ok) { cout << 0 << "\n"; continue; }

        vector<int> need(n+1, 0);
        for (int v = 1; v <= n; ++v) need[v] = tot[v] / k;

        // Count subarrays where each value appears at most need[v] times.
        vector<int> cnt(n+1, 0);
        long long ans = 0;
        int l = 0, over = 0; // 'over' = how many values currently exceed need
        for (int r = 0; r < n; ++r) {
            int x = a[r];
            cnt[x]++;
            if (cnt[x] == need[x] + 1) over++;      // x just exceeded its cap
            while (over > 0) {                       // shrink until valid
                int y = a[l++];
                if (cnt[y] == need[y] + 1) over--;   // y drops back to cap
                cnt[y]--;
            }
            ans += (r - l + 1); // all starts in [l..r] make valid subarrays ending at r
        }
        cout << ans << "\n";
    }
    return 0;
} 