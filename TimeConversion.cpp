#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) 
{
    stringstream ss;
    string hour0(1, s[0]);
    string hour1(1, s[1]);
    string hour = hour0 + hour1;
    int intHour = stoi(hour);

    if(s[s.size() - 2] == 'A')
    {
        if(intHour == 12)
        {
            hour0 = '0';
            hour1 = '0';
        }
        else 
        {
            hour0 = to_string(intHour / 10)[0];
            hour1 = to_string(intHour % 10)[0];
        }
    }
    if(s[s.size() - 2] == 'P')
    {
        intHour += 12;
        if (intHour == 24)
        {
            hour0 = '1';
            hour1 = '2';
            
        }
        else
        {
            hour0 = to_string(intHour / 10)[0];
            hour1 = to_string(intHour % 10)[0];
        }
    }
    s[0] = hour0[0];
    s[1] = hour1[0];
    s.erase(s.end()-2, s.end());
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
