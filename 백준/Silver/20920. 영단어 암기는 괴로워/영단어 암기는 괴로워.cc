#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    // 단어, 빈도 저장
    map<string, int> freq;
    while (n--) {
        string s; cin >> s;
        if (s.length() >= m) {
            freq[s]++;
        }
    }

    vector<string> word;
    for (auto& p : freq) {
        word.push_back(p.first);
    }

    // 빈도, 길이, 사전 순으로 정렬
    sort(word.begin(), word.end(), [&](const string& a, const string& b) {
        if (freq[a] != freq[b]) return freq[a] > freq[b];
        if (a.length() != b.length()) return a.length() > b.length();
        return a < b;
    });

    for (const auto& w : word) cout << w << '\n';
}