#include <iostream>
#include <string>
using namespace std;

int bigint(string a, string b) {
    int lena = a.length();
    int lenb = b.length();

    if (lena > lenb) return 1;
    if (lena < lenb) return 0;

    for (int i = 0; i < lena; i++) {
        if (a[i] > b[i]) return 1; // a가 더 큼
        if (a[i] < b[i]) return 0; // b가 더 큼
    }
    return 2;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string a, b, result;
    cin >> a >> b;

    int carry = 0, negative = 0;
    int lena = a.length();
    int lenb = b.length();

    // 부호가 다를 때
    if ((a[0] == '-' || b[0] == '-') && a[0] != b[0]) {
        if (a[0] == '-') {
            // a가 음수, b가 양수인 경우
            a = a.substr(1); // a에서 부호 제거
            lena--;
			negative = bigint(a, b);
            if (negative == 0) {
                swap(a, b);
                swap(lena, lenb);
            }
            else if (negative == 2) {
                cout << 0;
                return 0;
			}
        }

        else {
            // a가 양수, b가 음수인 경우
            b = b.substr(1); // b에서 부호 제거
            lenb--;
			negative = bigint(b, a);
            if (negative == 1) {
                swap(a, b);
                swap(lena, lenb);
			}
            else if (negative == 2) {
                cout << 0;
                return 0;
			}
        }

        while (true) {
            lena--;
            lenb--;
            if (lena < 0 && lenb < 0) break;
            // 숫자 선택
			int inta = lena >= 0 ? (int)a[lena] - '0' : 0;
			int intb = lenb >= 0 ? (int)b[lenb] - '0' : 0;

            // 계산
            int temp = inta - intb - carry;       
            if (temp < 0 && lena > 0) {
                temp += 10;
                carry = 1;
            } 
            else carry = 0;
			result += (char)(abs(temp) + '0');
        }

        while (!result.empty() && result.back() == '0') {
            result.pop_back();
		}
        if (result.empty()) {
            cout << 0;
            return 0;
        }
    }

    // 부호가 같을 때
    else {
        if (a[0] == '-') {
            // a와 b가 모두 음수인 경우
            a = a.substr(1); // a에서 부호 제거
            b = b.substr(1); // b에서 부호 제거
            lena--;
            lenb--;
            negative = 1; // 결과는 음수
        } 

        while (true) {
            lena--;
            lenb--;
            if (lena < 0 && lenb < 0) {
                if (carry) result += (char)(carry + '0');
                break;
            }

            // 숫자 선택
			int inta = lena >= 0 ? (int)a[lena] - '0' : 0;
			int intb = lenb >= 0 ? (int)b[lenb] - '0' : 0;

            // 계산
            result += (char)((inta + intb + carry) % 10 + '0');
            carry = (inta + intb + carry) / 10;
        }
    }

    // 음수인 경우 부호 추가
	if (negative) cout << '-'; 
    // 출력
    for (int i = result.length() - 1; i >= 0; i--) {
        cout << result[i];
    }
}