#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s = "";
    stack<string> sLog;
    sLog.push(s);
    int ops;
    cin >> ops;
    for (int i = 0; i <= ops; i++)
    {
        string type;
        getline(cin, type);
        if(type[0] == '1') //append string to the end of s
        {
            s.append(type.substr(2, type.length() - 1));
            sLog.push(s);
        }
        else if(type[0] == '2') //delete the last k characters
        {
            //subtract 2 to make it a 1 character substring
            s = s.substr(0, s.length() - stoi(type.substr(2, type.length() - 2)));
            sLog.push(s);
        }
        else if(type[0] == '3') //print character at position k + 1
        {
            //subtract 1 to account for array index
            cout << s[stoi(type.substr(2, type.length() - 2)) - 1] << endl; 
        }
        else if(type[0] == '4') //undo
        {
            sLog.pop();
            s = sLog.top();
        }
    }   
    return 0;
}
