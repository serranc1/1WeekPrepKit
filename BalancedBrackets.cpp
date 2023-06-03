#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) 
{
    stack<char> brackets; //stack will keep outermost brackets on bottom and innermost brackets on top
    for (int i = 0; i < s.length(); i++)
    {
        char bracket = s[i];
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') //if opening bracket, add to stack
        {
            brackets.push(s[i]);
        }
        else //if closing bracket, compare to innermost opening bracket in the stack
        {
            if(brackets.empty()) //if no opening bracket exists for closing bracket
            {
                return "NO";
            }
            char top = brackets.top();
            brackets.pop();
            //if innermost opening bracket and innermost closing bracket don't match, return NO 
            if((s[i] == ')' && top != '(') || (s[i] == '}' && top != '{') || (s[i] == ']' && top != '['))
            {
                return "NO";
            }
        }
    }
    if(brackets.empty()) //if all opening brackets were closed
    {
        return "YES";
    }
    else 
    {
        return "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

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
