#include <iostream>
#include <stack>
using namespace std;

int r[1000001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    stack<int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.push(a);
    }

    int m = 0;
    stack<int> result;
    for (int i = 0; i < n; i++) {
        int a = s.top();
        r[i] = a;
        s.pop();
        if (a >= m) {
            result.push(-1);
            m = a;
        }
        else {
            for (int j = i - 1; j >= 0; j--) {
                if (r[j] > a) {
                    result.push(r[j]);
                    break;
                }
                else if (result.top() > a) {
                    result.push(result.top());
                    break;
                }
            }
        }
    }

    while (!result.empty()) {
        int a = result.top();
        result.pop();
        cout << a << ' ';
    }
}