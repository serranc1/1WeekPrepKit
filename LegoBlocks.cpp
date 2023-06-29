#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

int legoBlocks(int n, int m) {
    //n = height, m = width
    if(m == 1)
    {
        return 1;
    }
    if(n == 1 && m > 4)
    {
        return 0;
    }
    const int modulo = 1000000007;
    //height/width will always be at least 1, so ignore row/column 0 and compensate with additional index
    long long A[1001][1001];
    long long B[1001];
    long long C[1001];
    //initialize matrix
    //check for possible combinations at height = 1
    A[1][0] = 1;
    for (int j = 1; j <= 1000; j++)
    {
        A[1][j] = A[1][j - 1];
        if(j >= 2) 
        {
            A[1][j] += A[1][j - 2];
        }
        if(j >= 3)
        {
            A[1][j] += A[1][j - 3];
        }
        if(j >= 4)
        {
            A[1][j] += A[1][j - 4];
        }
        A[1][j] %= modulo;
    }
    //check for combinations at height >= 2;
    for (int i = 2; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            A[i][j] = A[i - 1][j] * A[1][j];
            A[i][j] %= modulo;
        }
    }
    //need to read up on why this part works
    B[1] = 0;
    C[1] = 1;
    for (int j = 2; j <= m; j++)
    {
        B[j] = 0;
        for (int k = 1; k < j; k++)
        {
            B[j] += A[n][j - k] * C[k];
            B[j] %= modulo;
        }
        C[j] = (A[n][j] + modulo - B[j]) % modulo;
    }
    return C[m];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
