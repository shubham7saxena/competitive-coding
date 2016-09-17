#include <bits/stdc++.h>

using namespace std;

void kmp(const string &needle, const string &haystack) {
    int m = needle.size();
    vector<int> lps(m + 1);
    lps[0] = -1;
    for (int i = 0; i < m; ++i) {
        lps[i+1] = lps[i];
        while (lps[i+1] > -1 and needle[lps[i+1]] != needle[i]) {
          lps[i+1] = lps[lps[i+1]];
        }
        lps[i+1]++;
    }

    int n = haystack.size();
    int seen = 0;
    for (int i = 0; i < n; ++i){
        while (seen > -1 and needle[seen] != haystack[i]) {
            seen = lps[seen];
        }
        if (++seen == m) {
            printf("%d\n", i - m + 1);
    	   seen = lps[m]; // There are no more characters in needle, so with the next input character let's try with the lps of the whole needle.
        }
    }
}

int main(){
    string needle;
    getline(cin, needle);
    string haystack;
    getline(cin, haystack);
    kmp(needle, haystack);
    return 0;
}