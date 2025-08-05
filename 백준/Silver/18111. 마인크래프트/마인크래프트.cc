#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, b; cin >> n >> m >> b;

    int minD = 256, maxD = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            minD = min(minD, arr[i][j]);
            maxD = max(maxD, arr[i][j]);
        }
    }

    pair<int, int> result = { 70000000, 0 };
    for (int h = 0; h <= 256; h++) {
        int del = 0, ins = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] > h) {
                    del += arr[i][j] - h;
                }
                else {
                    ins += h - arr[i][j];
                }
            }
        }

        if (ins > del + b) break;
        else {
            int s = ins + del * 2;
            if (s <= result.first) {
                result = { s, h };
            }
        }
    }

    cout << result.first << ' ' << result.second;
}