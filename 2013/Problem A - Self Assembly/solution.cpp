#include <bits/stdc++.h>

using namespace std;

int chem[52][52];

int main() {
    int N;
    while (cin >> N) {
        memset(chem, 0, sizeof(chem));
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int i = 0; i < 8; i += 2) if (s[i] != '0')
            for (int j = 0; j < 8; j += 2) if (s[j] != '0' && j != i) {
                chem[s[i]-'A' + (s[i+1]=='+'?0:26)][s[j]-'A' + (s[j+1]=='+'?26:0)] = true;
            }
        }
        for (int k = 0; k < 52; k++)
        for (int i = 0; i < 52; i++)
        for (int j = 0; j < 52; j++)
            chem[i][j] |= (chem[i][k] & chem[k][j]);
        bool bounded = true;
        for (int i = 0; i < 52; i++)
            if (chem[i][i]) bounded = false;
        if (bounded)
            cout << "Bounded" << endl;
        else
            cout << "UnBounded" << endl;
    }
    
}