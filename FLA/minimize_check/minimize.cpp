#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
//#include <unordered_map>
using namespace std;
#define dbg(x) cerr << #x " = " << x << endl;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define FIN freopen("in.txt", "r", stdin);freopen("out.txt","w",stdout);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cout << "How many states would you like to input?" << endl;
    cin >> n;
    int m;
    cout << "the size of alphbet?" << endl;
    cin >> m;
    map<string ,int> mp;
    map<int, vector<int>> trans_table;
    int cnt = 0;
    cout << "now, input you transition, format : q (q, x1) (q, x2) ... (q, xm)" << endl;
    for(int i = 0; i < n; i++)
    {
        string q;
        cin >> q;
        if(mp.count(q) == 0)
        {
            mp[q] = cnt++;
        }
        for(int j = 0; j < m; j++)
        {
            string trans;
            cin >> trans;
            if(mp.count(trans) == 0)
            {
                mp[trans] = cnt++;
            }
            int qid = mp[q];
            int transid = mp[trans];
            trans_table[qid].push_back(transid);
        }
    }

    vector<vector<int>> result(n+5, vector<int>(n+5, 0)); // result[i][j] == 1 means i and j connot be merged

    cout << "How many final state?" << endl;
    int num_final;
    cin >> num_final;
    cout << "Input final state" << endl;
    set<int> final_state;
    for(int i = 0; i < num_final; i++)
    {
        string st;
        cin >> st;
        final_state.insert(mp[st]);
    }

    /**
     * first step
     */

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(final_state.count(i) != final_state.count(j))
            {
                result[i][j] = 1;
            }
        }
    }


    /**
     * second step
     */
    int new_error = 1;
    while(new_error)
    {
        new_error = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(result[i][j]) continue;
                for(int k = 0; k < m; k++)
                {
                    int flg = 0;
                    if(result[trans_table[i][k]][trans_table[j][k]] || result[trans_table[j][k]][trans_table[i][k]])
                    {
                        result[i][j] = 1;
                        flg = 1;
                        new_error = 1;
                    }
                    if(flg) break;
                }
            }
        }

    }

    /**
     * print info
     */
    cout << "the state and its id as follow:" << endl;
    vector<string> id_to_state(n+5);
    for(auto x : mp)
    {
        id_to_state[x.second] = x.first;
    }
    for(int i = 0; i < n; i++)
    {
        cout << "State " << id_to_state[i] << " : " << i << endl;
    }
    cout << "Row is from 1 to n-1, and col is from 0 to n-2" << endl;
    cout << "The result table is" << endl;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << (result[i][j] ? "X" : "O") << ' ';
        }
        cout << endl;
    }

    cout << "the pairs can be merged are:" << endl;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(result[i][j] == 0)
            {
                cout << "(" << id_to_state[i] << ", " << id_to_state[j] << ")" << endl;
            }
        }
    }
    

    return 0;
}

