#include <iostream>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    set<string> color;
    for (int i = 0; i < 4; i++) {
        string s; cin >> s;
        color.insert(s);
    }

    for (const string s1 : color) {
        for (const string s2 : color) {
            cout << s1 << ' ' << s2 << '\n';
        }
    }
}