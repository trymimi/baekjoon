#include <iostream>
#include <algorithm>
#include <vector>
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

    vector<pair<string, int>> word;
    for (auto& p : freq) {
        word.push_back(p);
    }

    // 빈도, 길이, 사전 순으로 정렬
    sort(word.begin(), word.end(), [&](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second > b.second;
        if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
        return a.first < b.first;
    });

    for (const auto& w : word) cout << w.first << '\n';
}