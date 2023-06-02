#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q; //number of queries
    stack<int> stackMain;
    stack<int> stackTemp;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int t; //type of query
        cin >> t;
        if (t == 1)
        {
            //store elements to be added in temp stack until they need to be added to main
            int x; //element to be added if query is type 1
            cin >> x;
            stackTemp.push(x);
        }
        else 
        {
            if(stackMain.empty()) //need to get elements from temp stack
            {
                while(!stackTemp.empty()) //elements in temp stack moved to main stack in order
                {
                    stackMain.push(stackTemp.top());
                    stackTemp.pop();
                }
            }
            if (t == 2)
            {
                stackMain.pop();
            }
            else 
            {
                cout << stackMain.top() << endl;
            }
        }
    }
    return 0;
}
