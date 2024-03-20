#include <bits/stdc++.h>

#include <random>

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

bool isMatch (string s, string p)
{
    int m = s.size();
    int n = p.size();
    auto match = [&] (int i, int j)
    {
        if (i == 0)
        {
            return false;
        }
        if (p[j - 1] == '.')
        {
            return true;
        }
        return s[i - 1] == p[j - 1];
    };
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[i][j] |= dp[i][j - 2];
                if (match(i, j - 1))
                {
                    dp[i][j] |= dp[i - 1][j];
                }
            } else
            {
                if (match(i, j))
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
    }
    return dp[n][m];
}

void dfs (vector<string> &res, string &ans, int &n, int &L, int &R)
{
    if (ans.size() == n * 2)
    {
        res.push_back(ans);
        return;
    }
    if (L != n)
    {
        L++;
        dfs(res, ans += '(', n, L, R);
        ans.back() == '(' ? L-- : R--;
        ans.pop_back();
    }
    if (R != n && R < L)
    {
        R++;
        dfs(res, ans += ')', n, L, R);
        ans.back() == '(' ? L-- : R--;
        ans.pop_back();
    }
}

class Solution3
{
public:
    int maximumANDSum (vector<int> &nums, int numSlots)
    {
        int n = numSlots << 1, ans = 0;
        nums.resize(n, 0);
        auto check = [&]
        {
            int sum = 0, cnt[n];
            memset(cnt, 0, sizeof(cnt));
            for (int x: nums)
            {
                int i = 0;
                for (int j = 1; j <= numSlots; ++j)
                {
                    if (cnt[j] < 2 && (x & j) > (x & i)) i = j;
                }
                sum += x & i;
                cnt[i]++;
            }
            return sum;
        };
        auto RD = [&]
        {
            shuffle(begin(nums), end(nums), std::mt19937(std::random_device()()));
            int ret = check();
            return ret;
        };
        for (int i = 0; i < 10000; ++i)
        {
            ans = max(ans, RD());
        }
        return ans;
    }
};

const double epx = 1e-20;
const double delta = 0.999;

class Solution1
{
public:
    vector<int> a;
    int ans = INT_MIN;
    int num = 0;

    int fun ()
    {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
        {
            res += a[i] & ((i / 2) + 1);
        }
        ans = max(res, ans);
        return res;
    }

    int sa ()
    {
        shuffle(a.begin(), a.end(), std::mt19937(std::random_device()()));
        int n = a.size();
        for (double t = 1e6; t > epx; t *= delta)
        {
            int x = rand() % n;
            int y = rand() % n;
            int last = fun();
            swap(a[x], a[y]);
            int now = fun();
            int de = now - last;
            if (de > 0)
            {

            } else if (!(exp(-1.0 * de / t) * RAND_MAX > rand()))
            {
                swap(a[x], a[y]);
            }
        }
        return ans;
    }

    int maximumANDSum (vector<int> &nums, int numSlots)
    {
        for (int i = 0; i < numSlots * 2; i++)
        {
            a.push_back(0);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            a[i] = nums[i];
        }
        return sa();
    }
};

int longestValidParentheses (string s)
{
    int maxLenth = 0;
    int n = s.length();
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
            {
                dp[i] = i > 2 ? dp[i - 2] + 2 : 2;
            } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
            {
                dp[i] = (i - dp[i - 1] - 1 == 0)?dp[i - 1] + 2 : dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
            }
        }
        maxLenth = max(maxLenth, dp[i]);
    }
    return maxLenth;
}

int main ()
{
    longestValidParentheses("()(())");
    return 0;
}