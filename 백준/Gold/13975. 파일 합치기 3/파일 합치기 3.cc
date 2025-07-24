#include <iostream>
#include <queue>
using namespace std;

int t, k;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;

    while (t--) {
        cin >> k;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        while (k--) {
            long long f; cin >> f;
            pq.push(f);
        }

        long long result = 0;
        while (pq.size() != 1) {
            long long a = pq.top();
            pq.pop();

            long long b = pq.top();
            pq.pop();

            result += a + b;
            pq.push(a + b);
        }
        cout << result << '\n';
    }
}