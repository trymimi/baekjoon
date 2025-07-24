#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;

    while (t--) {
        int k; cin >> k;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        while (k--) {
            long long f; cin >> f;
            pq.push(f);
        }

        long long result = 0;
        while (true) {
            int m = pq.size() / 2;
            if (m < 1) break;

            vector<int> temp;
            while (pq.size() > 1) {
                long long a = pq.top();
                pq.pop();

                long long b = pq.top();
                pq.pop();

                result += a + b;
                pq.push(a + b);
            }
        }
        cout << result << '\n';
    }
}