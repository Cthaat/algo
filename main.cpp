#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int arr[5];
int *arr1 = new int[5];

int fac (int n)
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

struct Node
{
    int val;
    Node *next;

    Node (int n)
    {
        val = n;
    }
};

Node *test ()
{
    Node *n0 = new Node(1);
    Node *n1 = new Node(2);
    Node *n2 = new Node(3);
    Node *n3 = new Node(4);
    Node *n4 = new Node(5);
    Node *head = n0;
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;
    return n0;
}

void insert (Node *n0, int n)
{
    Node *Temp = new Node(n);
    Temp->next = n0->next;
    n0->next = Temp;
}

void del (Node *n0, int n)
{
    Node *p = n0;
    for (int i = 0; i < n; ++i)
    {
        p = n0;
        n0 = n0->next;
    }
    p->next = n0->next;
    delete n0;
    n0 = nullptr;
}

vector<int> num1;
vector<int> num2 = {1, 2, 3, 4, 5};

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode (int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedListStack
{
private:
    ListNode *stackTop{};
    int stkSize;

public:
    LinkedListStack ()
    {
        stackTop = nullptr;
        stkSize = 0;
    }

    ~LinkedListStack ()
    {
        ;
    }

    int getSize ()
    {
        return stkSize;
    }

    bool isEmpty ()
    {
        return stkSize == 0;
    }

    void push (int val)
    {
        ListNode *node = new ListNode(val);
        node->next = stackTop;
        this->stackTop = node;
        stkSize++;
    }

    int pop ()
    {
        int number = this->getTop();
        ListNode *temp = stackTop;
        stackTop = temp->next;
        delete temp;
        temp = nullptr;
        stkSize--;
        return number;
    }

    int getTop ()
    {
        return this->stackTop->val;
    }

    vector<int> toVector ()
    {
        ListNode *temp = this->stackTop;
        vector<int> vec;
        while (temp != nullptr)
        {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        return vec;
    }
};

class arrayStack
{
private:
    vector<int> arr;

public:
    int getSize ()
    {
        return arr.size();
    }

    bool isEmpty ()
    {
        return arr.empty();
    }

    void push (int val)
    {
        arr.push_back(val);
    }

    int pop ()
    {
        int num = this->getTop();
        arr.pop_back();
        return num;
    }

    int getTop ()
    {
        return arr[arr.size() - 1];
    }
};

class doubleListNode
{
public:
    int val;
    doubleListNode *prev;
    doubleListNode *next;

    doubleListNode (int val)
    {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class linkListDeque
{
private:
    doubleListNode *head;
    doubleListNode *tail;
    int size;

public:
    linkListDeque ()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~linkListDeque ()
    {
        doubleListNode *temp = this->head;
        while (temp != nullptr)
        {
            doubleListNode *delNode = temp->next;
            delete temp;
            temp = delNode;
        }
    }

    int getSize ()
    {
        return this->size;
    }

    bool isEmpty ()
    {
        return this->getSize() == 0;
    }

    void pushFront (int val)
    {
        doubleListNode *node = new doubleListNode(val);
        if (this->head == nullptr)
        {
            this->head = node;
            this->tail = node;
        } else
        {
            head->next = node->next;
            head = node;
        }
    }
};

int main ()
{

    return 0;
}
