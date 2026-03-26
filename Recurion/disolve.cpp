#include <bits/stdc++.h>
using namespace std;

string dissolve(string s) {
   
    string bestOutput = s;

    for (int i = 0; i < s.length(); ) {

        int j = i;

        while (j < s.length() && s[j] == s[i]) {
            j++;
        }

        
        if (j - i > 1) {
            string s_ = s.substr(0, i) + s.substr(j);

            string output = dissolve(s_);

            if (output.length() < bestOutput.length()) {
                bestOutput = output;
            }
        }

        i = j;
    }

    return bestOutput;
}

int main() {
    string input = "aabbcccbxxad";
    cout<<dissolve(input)<<endl;
    return 0;
}