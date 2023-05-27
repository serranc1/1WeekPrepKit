#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int palindromeIndex(string s) 
{
    string r = s;
    reverse(r.begin(), r.end());
    if (s.length() > 1 && s != r)
    {
        for (int i = 0; i < s.length() / 2; i++)
        {
            if(s[i] != s[s.length() - i - 1])
            {
                string s1 = s.substr(0, i) + s.substr(i + 1);
                string s2 = s.substr(0, s.length() - i - 1) + s.substr(s.length() - i);
                string s3 = s1;
                string s4 = s2;
                reverse(s3.begin(), s3.end());
                reverse(s4.begin(), s4.end());
                if (s1 == s3)
                {
                    return i;
                }
                else if (s2 == s4)
                {
                    return s.length() - i - 1;
                }
            }
        }
        return -1;
    }
    else 
    {
        return -1;
    }
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

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
