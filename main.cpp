#include <iostream>
#include <stack>
using namespace std;

int forLoop(int n)
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
    int n = 0;
    cin >> n;
    cout << forLoop(n) << endl;
    return 0;
}
