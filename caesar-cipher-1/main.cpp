#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string caesarCipher(string s, int k) {
    string res;
    
    for (char &c: s) {
        int ascii = (int)c;
        
        if (ascii > 96 && ascii < 123) {
            int ea = ascii + k%26;
            
            if (ea > 122) {
                ea = 96 + (ea - 122);
            }
        
            res.push_back((char)ea);
            
        } else if (ascii > 64 && ascii < 91) {
            int ea = ascii + k%26;
            
            if (ea > 90) {
                ea = 64 + (ea - 90);
            }
        
            res.push_back((char)ea);
        } else {
            res.push_back(c);
        }
        
        //cout << ascii << c << ascii+k << ch << " ";
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

