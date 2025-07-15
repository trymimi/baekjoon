#include <iostream>
#include <stack>
using namespace std;

int num[26];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) cin >> num[i];
    stack<double> temp;
    for (char c : s) {
        if (c <= 'Z' && c >= 'A') temp.push(num[c - 'A']);
        else {
            double b = temp.top();
            temp.pop();
            double a = temp.top();
            temp.pop();
            if (c == '+') temp.push(a + b);
            else if (c == '-')
                temp.push(a - b);
            else if (c == '*')
                temp.push(a * b);
            else if (c == '/')
                temp.push(a / b);
        }
    }
    printf("%.2f", temp.top());
}