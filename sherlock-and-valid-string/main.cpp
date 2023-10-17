#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

int hash_char(char c) {
    return (int)c;
}

string isValid(string s) {
    string no  = "NO";
    string yes = "YES";
    
    int freqs_a[255] = {0};
    bool max_c = 0;
    int len = 0;
    
    for (char &c: s) {
        freqs_a[hash_char(c)] += 1;
    }
    
    vector<int> freqs;
    
    for (int i: freqs_a) {
        if (i == 0) {
            continue;
        }
        
        freqs.push_back(i);
    }
    
    int avg = freqs[0];
    
    for (int i = 1; i < freqs.size(); i++) {
        int curr    = freqs[i];
         
        int p = abs(curr - avg);
                
        if (max_c && p > 0) {
            return no;
        } else {
            max_c |= p>0;
        }
    }
    
    return yes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

