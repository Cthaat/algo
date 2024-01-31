#include <iostream>
#include <stack>
#include <vector>
#include <queue>

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

    void remove (int key)
    {
        int index = this->findBucket(key);
        if (index != -1)
        {
            this->buckets[index] = this->TOMBSTONE;
            this->size--;
        }
    }

    void extend ()
    {
        vector<Pair *> oldBuckets = this->buckets;
        this->capacity *= this->extendRation;
        this->buckets.resize(this->capacity);
        for (auto &i: oldBuckets)
        {
            this->put(i->key, i->value);
        }
    }

    void put (int key, int value)
    {
        if (this->getLoadFactor() > this->loadFactor)
        {
            this->extend();
        }
        int index = this->findBucket(key);
        if (this->buckets[index] != nullptr && this->buckets[index] != this->TOMBSTONE)
        {
            if (this->buckets[index]->key == key)
            {
                this->buckets[index]->value = value;
                return;
            }
        }
        this->buckets[index] = new Pair(key, value);
        this->size++;
    }

    void printHash ()
    {
        for (auto &i: this->buckets)
        {
            if (i != nullptr && i != this->TOMBSTONE)
            {
                cout << "Key: " << i->key << " Value: " << i->value << endl;
            }
        }
    }
};

struct treeNode
{
    int value;
    treeNode *left;
    treeNode *right;

    treeNode (int value) : value(value), left(nullptr), right(nullptr)
    {}
};

class treeTest1
{
private:
    treeNode *n1 = new treeNode(1);
    treeNode *n2 = new treeNode(2);
    treeNode *n3 = new treeNode(3);
    treeNode *n4 = new treeNode(4);
    treeNode *n5 = new treeNode(5);
public:
    treeTest1 ()
    {
        n1->left = n2;
        n1->right = n3;
        n2->left = n4;
        n2->right = n5;
    }

    void put (int value)
    {
        treeNode *current = new treeNode(value);
        current->left = n1->left;
        n1->left = current;
    }

    vector<int> levelOrder ()
    {
        queue<treeNode *> q;
        q.push(n1);
        vector<int> result;
        while (!q.empty())
        {
            treeNode *node = q.front();
            q.pop();
            result.push_back(node->value);
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        return result;
    }

    treeNode *getRoot ()
    {
        return this->n1;
    }
};

class order
{
private:
    vector<int> vec;
public:
    vector<int> getVec ()
    {
        return this->vec;
    }

    void perOrder (treeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        vec.push_back(node->value);
        perOrder(node->left);
        perOrder(node->right);
    }

    void inOrder (treeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrder(node->left);
        vec.push_back(node->value);
        inOrder(node->right);
    }

    void postOrder (treeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        vec.push_back(node->value);
    }
};

class arrayBinaryTree
{
private:
    vector<int> tree;

    void dfs (int i, string order, vector<int> &res)
    {
        if (val(i) == INT_MAX)
        {
            return;
        }
        if (order == "pre")
        {
            res.push_back(val(i));
        }
        dfs(left(i), order, res);
        if (order == "in")
        {
            res.push_back(val(i));
        }
        dfs(right(i), order, res);
        if (order == "post")
        {
            res.push_back(val(i));
        }
    }

public:
    arrayBinaryTree (vector<int> tree)
    {
        this->tree = tree;
    }

    int getSize ()
    {
        return tree.size();
    }

    int val (int i)
    {
        if (i < 0 || i >= getSize())
        {
            return INT_MAX;
        }
        return tree[i];
    }

    int left (int i)
    {
        return 2 * i + 1;
    }

    int right (int i)
    {
        return 2 * i + 2;
    }

    int parent (int i)
    {
        return (i - 1) / 2;
    }

    vector<int> levelOrder ()
    {
        vector<int> res;
        for (int i = 0; i < this->getSize(); ++i)
        {
            if (val(i) != INT_MAX)
            {
                res.push_back(val(i));
            }
        }
        return res;
    }

    vector<int> preOrder ()
    {
        vector<int> res;
        dfs(0, "pre", res);
        return res;
    }

    vector<int> inOrder ()
    {
        vector<int> res;
        dfs(0, "in", res);
        return res;
    }

    vector<int> postOrder ()
    {
        vector<int> res;
        dfs(0, "post", res);
        return res;
    }
};

class BinarySearchTree
{
private:
    treeNode *root;
    vector<int> vec;
public:
    treeNode* getRoot ()
    {
        return root;
    }
    vector<int> getVec ()
    {
        return vec;
    }

    treeNode *search (int number)
    {
        treeNode *node = this->root;
        while (node != nullptr)
        {
            if (node->value == number)
            {
                return node;
            }
            if (node->value > number)
            {
                node = node->left;
                continue;
            }
            if (node->value < number)
            {
                node = node->right;
                continue;
            }
        }
        return nullptr;
    }

    void insert (int number)
    {
        if (this->search(number) != nullptr)
        {
            return;
        }
        treeNode *node = new treeNode(number);
        treeNode *parent = nullptr;
        treeNode *current = this->root;
        if (this->root == nullptr)
        {
            root = node;
            return;
        }
        while (current != nullptr)
        {
            parent = current;
            if (current->value > number)
            {
                current = current->left;
            } else
            {
                current = current->right;
            }
        }
        if (parent->value > number)
        {
            parent->left = node;
        } else
        {
            parent->right = node;
        }
    }

    void remove (int number)
    {
        if (this->search(number) == nullptr)
        {
            return;
        }
        treeNode *current = this->root;
        treeNode *parent = nullptr;
        while (current != nullptr)
        {
            if (current->value == number)
            {
                break;
            }
            parent = current;
            if (current->value > number)
            {
                current = current->left;
            } else
            {
                current = current->right;
            }
        }
        if (current->left == nullptr && current->right == nullptr)
        {
            treeNode *child = current->left == nullptr ? current->right : current->left;
            if (parent == nullptr)
            {
                this->root = child;
            } else
            {
                if (parent->left == current)
                {
                    parent->left = child;
                } else
                {
                    parent->right = child;
                }
                delete current;
                current = nullptr;
            }
        } else
        {
            treeNode *temp = current->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            int tem = temp->value;
            remove(temp->value);
            current->value = tem;
        }
    }

    void inOrder (treeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrder(node->left);
        vec.push_back(node->value);
        inOrder(node->right);
    }
};

int main ()
{

    return 0;
}
