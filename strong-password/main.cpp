#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim
(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */
 
bool set_int(int& refer, int val) {
    refer = val;
    return 1;
}

int minimumNumber(int n, string password) {
    char special_chars[12] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
    
    int fac[4] = {0, 0, 0, 0};
    int size = password.size();
    int sum = 0;

    for (char &c: password) {
        int ascii = (int)c;
        int scf   = false;
        
        for (char &sc: special_chars) {
            scf |= c == sc;
        }
        
        int ind = 0;
        
        if (ascii > 64 && ascii < 91 && !fac[0]) {
            fac[0] = 1;
            sum++;
        } else if (ascii > 96 && ascii < 123 && !fac[1]) {
            fac[1] = 1;
            sum++;
        } else if (ascii > 47 && ascii < 58 && !fac[2]) {
            fac[2] = 1;
            sum++;
        } else if (scf && !fac[3]) {
            fac[3] = 1;
            sum++;
        }
    }
    
    int os = 6 > size ? 6-size: 0;
    int cn = 4-sum;
    
    cout << cn << os;
    
    return os > 4-sum ? os: 4-sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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

