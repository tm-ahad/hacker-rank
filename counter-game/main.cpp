#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

const unsigned long power_2_63 = 9223372036854775808;

bool is_power_of_2(unsigned long n) {
    return !(n & n-1);
}

string counterGame(unsigned long n) {
    long c = n;
    int g = 0;
    
    while (true) {
        int bits = 0;
        long c2 = c;
            
        while (c2 != 1) {
            c2 >>= 1;
            bits++;
        }

        if (is_power_of_2(c)) {
            g += bits;
            break;
        } else {
            c = c ^ (1ULL<<bits);
        }
        g++;
    }
    
    return g & 0x1 ? "Louise": "Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        string result = counterGame(n);

        fout << result << "\n";
    }

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

