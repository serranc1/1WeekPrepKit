#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) 
{
    vector<int> distances;
    map<int, bool> visited; //map of nodes and whether or not they're visited
    map<int, vector<int>> edgesMap; //map of doubly linked node pairs with edges
    for (int i = 0; i < edges.size(); i++)
    {
        vector<int> par = edges[i];
        edgesMap[par[0]].push_back(par[1]);
        edgesMap[par[1]].push_back(par[0]);
    }
    //set all nodes as not visited
    for (auto x : edgesMap)
    {
        visited[x.first] = false;
    }
    map<int, int> distances2; //map to track current calculated distance to a node from s
    queue<pair<int, int>> q; //queue of nodes that need to be visited with their current distances
    q.push({s, 0});
    visited[s] = true;
    //while nodes still need to be checked
    while(!q.empty())
    {
        pair<int, int> fr = q.front(); //front of queue to be checked
        q.pop();
        if (fr.second > 0) //if there is already a distance to a node, use in adding distance later
        {
            distances2[fr.first] = fr.second;
        }
        for (int x : edgesMap[fr.first]) //go through each node directly connected to front node
        {
            if (!visited[x]) //if not visited yet, mark as visited, push node into queue with added edge distance of 6
            {
                visited[x] = true;
                q.push({x,fr.second+6});
            }
        }
    }
    //go through all the nodes
    for (int i = 1; i <= n; i++)
    {
        if (i != s) //if not starting node
        {
            if (visited[i]) //if node was able to be reached, push distance to it
            {
                distances.push_back(distances2[i]);
            }
            else //if node isn't connected to start node by any means, return -1
            {
                distances.push_back(-1);
            }
        }
    }
    return distances;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
