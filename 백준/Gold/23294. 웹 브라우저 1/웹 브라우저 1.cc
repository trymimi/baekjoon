#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int cash[2001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q, c;
    cin >> n >> q >> c;

    for (int i = 1; i <= n; i++) {
        cin >> cash[i];
    }

    int page = 0;
    int B_cash = 0, F_cash = 0;
    deque<int> back;
    stack<int> front;
    while (q--) {
        char work;
        int k;
        cin >> work;
        // 접속
        if (work == 'A') {
            cin >> k;
            while (!front.empty()) front.pop();
            F_cash = 0;

            if (page) {
                back.push_back(page);
                B_cash += cash[page];
                page = k;

                while (B_cash + F_cash + cash[page] > c) {
                    B_cash -= cash[back.front()];
                    back.pop_front();
                }
            }
            else page = k;
        }
        // 뒤로 가기
        else if (work == 'B' && !back.empty()) {
            front.push(page);
            F_cash += cash[page];
            page = back.back();
            back.pop_back();
            B_cash -= cash[page];
        }
        // 앞으로 가기
        else if (work == 'F' && !front.empty()) {
            back.push_back(page);
            B_cash += cash[page];
            page = front.top();
            front.pop();
            F_cash -= cash[page];
        }
        // 압축
        else if (work == 'C' && !back.empty()) {
            deque<int> temp;
            int prev = -1;
            for (int p : back) {
                if (p != prev) {
                    temp.push_back(p);
                    prev = p;
                }
                else B_cash -= cash[p];
            }
            back = temp;
        }
    }

    // 출력
    cout << page << '\n';
    if (back.empty()) cout << -1;
    else {
        while (!back.empty()) {
            cout << back.back() << ' ';
            back.pop_back();
        }
    }
    cout << '\n';
    if (front.empty()) cout << -1;
    else {
        while (!front.empty()) {
            cout << front.top() << ' ';
            front.pop();
        }
    }
}