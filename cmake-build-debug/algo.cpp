#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int P9242 ()
{
    vector<int> dp;
    int n;
    string a;
    vector<int> nums;
    cin >> n;
    nums.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a;
        dp[a[a.length() - 1] - '0'] = max(dp[a[a.length() - 1] - '0'], dp[a[0] - 48] + 1);
    }
    cout << *(dp.end()--) << endl;
    return 0;
}

class student
{
public:
    string name;
    int sore1;
    int sore2;
    int sore3;
    int average;

    student (string name, int sore1, int sore2, int sore3)
    {
        this->name = name;
        this->sore1 = sore1;
        this->sore2 = sore2;
        this->sore3 = sore3;
        this->average = (sore1 + sore2 + sore3) / 3; // 计算平均分
    }

    void toString ()
    {
        cout << name << " " << sore1 << " " << sore2 << " " << sore3 << " " << average << endl;
    }
};


class Solution
{
public:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> result;
    bool valid = true;

    void dfs (int u)
    {
        visited[u] = 1;
        for (auto &v: edges[u])
        {
            if (visited[v] == 0)
            {
                dfs(v);
                if (!valid)
                {
                    return;
                }
            } else if (visited[v] == 1)
            {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
        result.push_back(u);
    }

    vector<int> findOrder (int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (auto &info: prerequisites)
        {
            edges[info[0]].push_back(info[1]);
        }
        for (int i = 0; i < numCourses; ++i)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        if (!valid)
        {
            return {};
        }
        return result;
    }
};

string addBinary (string a, string b)
{
    bool flag = false;
    string ans = "";
    int i = a.length();
    int j = b.length();
    while (j != 0 && i != 0)
    {
        if (a[i - 1] == '1' && b[j - 1] == '1')
        {
            if (flag == true)
            {
                ans.push_back('1');
            }
            if (flag == false)
            {
                ans.push_back('0');
                flag = true;
            }
        }
        if (a[i - 1] == '1' && b[j - 1] == '0' || a[i - 1] == '0' && b[j - 1] == '1')
        {
            if (flag == true)
            {
                ans.push_back('0');
            }
            if (flag == false)
            {
                ans.push_back('1');
            }
        }
        if (a[i - 1] == '0' && b[j - 1] == '0')
        {
            if (flag == false)
            {
                ans.push_back('0');
            }
            if (flag == true)
            {
                ans.push_back('1');
                flag = false;
            }

        }
        i--;
        j--;
    }
    if (i == 0)
    {
        while (j != 0)
        {
            if (b[j - 1] == '1' && flag == true)
            {
                ans.push_back('0');
            }
            if (flag == false)
            {
                ans.push_back(b[j - 1]);
            }
            if (b[j - 1] == '0' && flag == true)
            {
                ans.push_back('1');
                flag = false;
            }

            j--;
        }
    }
    if (j == 0)
    {
        while (i != 0)
        {
            if (a[i - 1] == '1' && flag == true)
            {
                ans.push_back('0');
            }
            if (flag == false)
            {
                ans.push_back(a[i - 1]);
            }
            if (a[i - 1] == '0' && flag == true)
            {
                ans.push_back('1');
                flag = false;
            }
            i--;
        }
    }
    if (flag == true)
    {
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string longestPalindrome (string s)
{
    int n = s.size();
    if (n < 2)
    {
        return s;
    }
    int maxLenth = 1;
    int begin = 0;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = L + i - 1;
            if (j >= n)
            {
                break;
            }
            if (s[i] != s[j])
            {
                dp[i][j] = false;
            } else
            {
                if (j - i < 3)
                {
                    dp[i][j] = true;
                } else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            if (dp[i][j] && j - i + 1 > maxLenth)
            {
                maxLenth = j - i + 1;
                begin = i;
            }
        }
    }
    return s.substr(begin, maxLenth);
}

pair<int, int> exture (const string &s, int L, int R)
{
    while (L >= 0 && R < s.size() && s[L] == s[R])
    {
        L--;
        R++;
    }
    return {L + 1, R - 1};
}

string longestPalindrome2 (string s)
{
    int begin = 0;
    int end = 0;
    for (int i = 0; i < s.size(); i++)
    {
        auto [L1, R1] = exture(s, i, i);
        auto [L2, R2] = exture(s, i, i + 1);
        if (end - begin < max(R1 - L1, R2 - L2))
        {
            (R1 - L1) > (R2 - L2) ? (end = R1, begin = L1)
                                  : (end = R2, begin = L2);
        }
    }
    return s.substr(begin, end - begin + 1);
}

int main ()
{
    longestPalindrome2("babad");
    return 0;
}