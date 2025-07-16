#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    string L;
    stack<char> Left;
    stack<char> Right;
    while (t--) {
        cin >> L;
        for (char c : L) {
            if (c == '<') {
                if (!Left.empty()) {
                    Right.push(Left.top());
                    Left.pop();
                }
            }
            else if (c == '>') {
                if (!Right.empty()) {
                    Left.push(Right.top());
                    Right.pop();
                }
            }
            else if (c == '-') {
                if (!Left.empty()) {
                    Left.pop();
                }
            }
            else Left.push(c);
        }

        while (!Left.empty()) {
            Right.push(Left.top());
            Left.pop();
        }
        while (!Right.empty()) {
            cout << Right.top();
            Right.pop();
        }
        cout << '\n';
    }
}