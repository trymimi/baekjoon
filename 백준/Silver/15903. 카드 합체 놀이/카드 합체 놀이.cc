#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> card;
    while (n--) {
        long long a; cin >> a;
        card.push(a);
    }

    while (m--) {
        long long a1 = card.top();
        card.pop();

        long long a2 = card.top();
        card.pop();

        card.push(a1 + a2);
        card.push(a1 + a2);
    }

    long long result = 0;
    while (!card.empty()) {
        result += card.top();
        card.pop();
    }
    cout << result;
}