#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    queue<string> st;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        st.push(s);
    }

    queue<string> en;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        en.push(s);
    }

    int cnt = 0;
    set<string> exit;
    while (!st.empty() && !en.empty()) {
        if (st.front() == en.front()) {
            st.pop();
            en.pop();
        }
        else if (exit.find(st.front()) != exit.end()) st.pop();
        else {
            exit.insert(en.front());
            en.pop();
            cnt++;
        }
    }
    cout << cnt;
}