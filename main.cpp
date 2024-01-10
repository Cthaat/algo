#include <iostream>
#include <stack>

using namespace std;

int fac(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * fac(n - 1);
}

int line (float n)
{
    if (n <= 1)
    {
        return 1;
    }
    int count = line(n / 2) + line(n / 2);
    for (int i = 0; i < (int) n + 1; i++)
    {
        count++;
    }
    return count;
}

int log (float n)
{
    if (n <= 1)
    {
        return 0;
    }
    return log(n / 2) + 1;
}

int exp (int n)
{
    int count = 0;
    int base = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < base; ++j)
        {
            count++;
        }
        base *= 2;
    }
    return count;
}

int forLoop (int n)
{
    stack<int> sta;
    int res = 0;
    for (int i = n; i > 0; i--)
    {
        sta.push(i);
    }
    while (!sta.empty())
    {
        res += sta.top();
        sta.pop();
    }
    return res;
}


int main ()
{
    cout << fac(5) << endl;
    return 0;
}
