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

class Pair
{
public:
    int key;
    int value;

    Pair (int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class ArrayHashMap
{
private:
    vector<Pair *> hashArray;
public:
    ArrayHashMap ()
    {
        this->hashArray.resize(100);
    }

    ~ArrayHashMap ()
    {
        for (auto &i: hashArray)
        {
            delete i;
        }
        this->hashArray.clear();
    }

    int hashFunc (int key)
    {
        int index = key % 100;
        return index;
    }

    int get (int key)
    {
        int index = this->hashFunc(key);
        Pair *pair = this->hashArray[index];
        if (pair == nullptr)
        {
            return -1;
        }
        return pair->value;
    }

    void put (int key, int value)
    {
        int index = this->hashFunc(key);
        Pair *pair = new Pair(key, value);
        this->hashArray[index] = pair;
    }

    int remove (int key)
    {
        return this->hashArray[this->hashFunc(key)]->value;
        delete this->hashArray[this->hashFunc(key)];
        this->hashArray[this->hashFunc(key)] = nullptr;
    }

    vector<Pair *> getHashArray ()
    {
        vector<Pair *> tempArr;
        for (auto &i: this->hashArray)
        {
            if (i != nullptr)
            {
                tempArr.push_back(i);
            }
        }
        return tempArr;
    }

    vector<int> getKey ()
    {
        vector<int> tempKey;
        for (auto &i: this->hashArray)
        {
            if (i != nullptr)
            {
                tempKey.push_back(i->key);
            }
        }
        return tempKey;
    }

    vector<int> getValue ()
    {
        vector<int> tempValue;
        for (auto &i: this->hashArray)
        {
            if (i != nullptr)
            {
                tempValue.push_back(i->value);
            }
        }
        return tempValue;
    }

    void printHashArray ()
    {
        for (auto &i: this->hashArray)
        {
            if (i != nullptr)
            {
                cout << "key:" << i->key << "value:" << i->value << endl;
            }
        }
    }
};

class HashMapChaing
{
private:
    int size;
    int capacity;
    double loadFactor;
    int extendRating;
    vector<vector<Pair *>> buckets;

public:
    HashMapChaing ()
    {
        this->size = 0;
        this->capacity = 4;
        this->loadFactor = 0.75;
        this->extendRating = 2;
        this->buckets.resize(this->capacity);
    }

    ~HashMapChaing ()
    {
        for (auto &i: this->buckets)
        {
            for (auto &j: i)
            {
                delete j;
                j = nullptr;
            }
        }
        this->buckets.clear();
    }

    int hashFunction (int key)
    {
        return key % this->capacity;
    }

    double getLoadFactor ()
    {
        return (double) this->size / (double) this->capacity;
    }

    int getValue (int key)
    {
        int index = this->hashFunction(key);
        for (auto &i: this->buckets[index])
        {
            if (i->key == key)
            {
                return i->value;
            }
        }
        return -1;
    }

    void extend ()
    {
        vector<vector<Pair *>> tempBuckets = this->buckets;
        capacity *= this->extendRating;
        buckets.clear();
        this->buckets.resize(this->capacity);
        this->size = 0;
        for (auto &i: tempBuckets)
        {
            for (auto &j: i)
            {
                put(j->key, j->value);
                delete j;
                j = nullptr;
            }
        }
    }

    void put (int key, int value)
    {
        if (this->getLoadFactor() >= this->loadFactor)
        {
            this->extend();
        }
        int index = this->hashFunction(key);
        for (auto &i: this->buckets[index])
        {
            if (i->key == key)
            {
                i->value = value;
                return;
            }
        }
        this->buckets[index].push_back(new Pair(key, value));
        this->size++;
    }

    int remove (int key)
    {
        int index = this->hashFunction(key);
        for (auto i = this->buckets[index].begin(); i != this->buckets[index].end(); i++)
        {
            if (((*i)->key = key))
            {
                this->buckets[index].erase(i);
                this->size--;
                return (*i)->value;
            }
        }
        return -1;
    }

    void printHash ()
    {
        for (auto &i: this->buckets)
        {
            for (auto &j: i)
            {
                cout << j->key << " " << j->value << endl;
            }
        }
    }
};

class hashMapOpen
{
private:
    int size;
    int capacity = 4;
    const double loadFactor = 0.75;
    const int extendRation = 2;
    vector<Pair *> buckets;
    Pair *TOMBSTONE = new Pair(-1, -1);

public:
    hashMapOpen ()
    {
        this->size = 0;
        this->buckets.resize(this->capacity);
    }

    ~hashMapOpen ()
    {
        for (auto &i: this->buckets)
        {
            if (i != TOMBSTONE && i != nullptr)
            {
                delete i;
            }
        }
        delete this->TOMBSTONE;
    }

    int hashFunction (int key)
    {
        return key % this->capacity;
    }

    double getLoadFactor ()
    {
        return (double) this->size / (double) this->capacity;
    }

    int findBucket (int key)
    {
        int index = this->hashFunction(key);
        int firstTombstone = -1;
        while (this->buckets[index] != nullptr)
        {
            if (buckets[index]->key == key)
            {
                if (firstTombstone != -1)
                {
                    this->buckets[firstTombstone] = this->buckets[index];
                    this->buckets[index] = TOMBSTONE;
                    return firstTombstone;
                }
                return index;
            }
            if (firstTombstone == -1 && this->buckets[index] == this->TOMBSTONE)
            {
                firstTombstone = index;
            }
            index = (index + 1) % this->capacity;
        }
        return firstTombstone == -1 ? index : firstTombstone;
    }
};

int main ()
{

    return 0;
}
