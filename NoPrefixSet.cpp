#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

void noPrefix(vector<string> words) 
{
    unordered_set<string> words_to_check;
    unordered_set<string> prefixes;
    for (const auto &word: words) 
    {
        if (prefixes.count(word)) 
        {
            cout << "BAD SET" << endl;
            cout << word << endl;
            return;
        }
        
        string prefix = "";
        for (const auto& letter: word) 
        {
            prefix.push_back(letter);
            if (words_to_check.count(prefix)) 
            {
                cout << "BAD SET" << endl;
                cout << word;
                return;
            }
            prefixes.insert(prefix);
        }
        words_to_check.insert(word);
    }
    cout << "GOOD SET" << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

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
