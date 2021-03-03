#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    string s;
    cin >> s;

    // calculate character frequency
    int counter[26] = {0};
    for(char ch : s) counter[ch-'A'] += 1;

    // number of characters that have odd freq, if it is greater than 1 then NO SOLUTION
    int numOdd = 0;
    for(int freq : counter) {
        if(freq&1) numOdd++;
    }
    if(numOdd > 1) {
        cout << "NO SOLUTION";
        return 0;
    }

    // half of the even chars
    string t;
    for(int i = 0; i < 26; ++i) {
        int freq = counter[i];
        if(!(freq&1)) {
            for(int j = 0; j < freq/2; ++j) t.push_back(i+'A');
        }
    }
    cout << t;
    // odd chars
    for(int i = 0; i < 26; ++i) {
        int freq = counter[i];
        if(freq&1) {
            for(int j = 0; j < freq; ++j) cout << (char)(i+'A');
        }
    }
    // another half of the even chars
    reverse(t.begin(), t.end());
    cout << t;
}