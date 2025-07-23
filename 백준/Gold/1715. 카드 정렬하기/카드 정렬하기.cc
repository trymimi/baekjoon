#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int m = n - 1;

    while (n--) {
        int card;  cin >> card;
        pq.push(card);
    }

    int result = 0;
    while (m--) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        result += a + b;
        pq.push(a + b);
    }

    cout << result;
}