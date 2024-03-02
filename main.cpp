#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

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
    treeNode *getRoot ()
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

struct AVLTreeNode
{
    int value{};
    AVLTreeNode *left{};
    AVLTreeNode *right{};
    int height{};

    AVLTreeNode () = default;

    explicit AVLTreeNode (int value) : value(value)
    {};
};

class AVLTree
{
private:
    AVLTreeNode *root{};
    vector<AVLTreeNode *> vec{};

    int height (AVLTreeNode *node)
    {
        return node == nullptr ? -1 : node->height;
    }

    void updateHeight (AVLTreeNode *node)
    {
        node->height = max(height(node->left), height(node->right)) + 1;
    }

    int balanceFactor (AVLTreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    AVLTreeNode *rightRotate (AVLTreeNode *node)
    {
        AVLTreeNode *child = node->left;
        AVLTreeNode *grandChild = child->right;
        child->right = node;
        node->left = grandChild;
        updateHeight(node);
        updateHeight(child);
        return child;
    }

    AVLTreeNode *leftRotate (AVLTreeNode *node)
    {
        AVLTreeNode *child = node->right;
        AVLTreeNode *grandChild = child->left;
        child->left = node;
        node->right = grandChild;
        updateHeight(node);
        updateHeight(child);
        return child;
    }

    AVLTreeNode *insert (AVLTreeNode *node, int value)
    {
        if (node == nullptr)
        {
            return new AVLTreeNode(value);
        }
        if (value < node->value)
        {
            node->left = insert(node->left, value);
        } else if (value > node->value)
        {
            node->right = insert(node->right, value);
        } else
        {
            return node;
        }
        this->updateHeight(node);
        node = rotate(node);
        return node;
    }

    AVLTreeNode *rotate (AVLTreeNode *node)
    {
        int _balanceFactor = balanceFactor(node);
        if (_balanceFactor > 1)
        {
            if (balanceFactor(node->left) >= 0)
            {
                return this->rightRotate(node);
            } else
            {
                node->left = leftRotate(node->left);
                return this->rightRotate(node);
            }
        }
        if (_balanceFactor < -1)
        {
            if (balanceFactor(node->right) <= 0)
            {
                return leftRotate(node);
            } else
            {
                this->rightRotate(node->right);
                return this->leftRotate(node);
            }
        }
        return node;
    }

    AVLTreeNode *remove (AVLTreeNode *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (value < node->value)
        {
            node->left = remove(node->left, value);
        } else if (value > node->value)
        {
            node->right = remove(node->right, value);
        } else
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                AVLTreeNode *child = node->left == nullptr ? node->right : node->left;
                if (child == nullptr)
                {
                    delete node;
                    return nullptr;
                } else
                {
                    delete node;
                    node = child;
                }
            } else
            {
                AVLTreeNode *temp = node->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                int tempVal = temp->value;
                node->right = remove(node->right, tempVal);
                node->value = tempVal;
            }
        }
        updateHeight(node);
        node = rotate(node);
        return node;
    }

public:
    void insert (int value)
    {
        this->root = insert(root, value);
    }

    void remove (int value)
    {
        this->root = remove(root, value);
    }

    AVLTreeNode *getRoot ()
    {
        return this->root;
    }

    vector<AVLTreeNode *> levelOrder (AVLTreeNode *Root)
    {
        queue<AVLTreeNode *> q;
        q.push(Root);
        vector<AVLTreeNode *> result;
        while (!q.empty())
        {
            AVLTreeNode *node = q.front();
            q.pop();
            result.push_back(node);
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

    void perOrder (AVLTreeNode *Root)
    {
        if (Root == nullptr)
        {
            return;
        }
        cout << Root->value << " ";
        perOrder(Root->left);
        perOrder(Root->right);
    }

    void inOrder (AVLTreeNode *Root)
    {
        if (Root == nullptr)
        {
            return;
        }
        inOrder(Root->left);
        cout << Root->value << " ";
        inOrder(Root->right);
    }

    void postOrder (AVLTreeNode *Root)
    {
        if (Root == nullptr)
        {
            return;
        }
        postOrder(Root->left);
        perOrder(Root->right);
        cout << Root->value << " ";
    }
};

class ArrQueue
{
private:
    vector<int> maxHeap;

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

    int peek ()
    {
        return this->maxHeap[0];
    }

    void siftUp (int i)
    {
        while (true)
        {
            int p = parent(i);
            if (p < 0 || this->maxHeap[p] >= this->maxHeap[i])
            {
                return;
            }
            swap(this->maxHeap[p], this->maxHeap[i]);
            i = p;
        }
    }

    void siftDown (int i)
    {
        while (true)
        {
            int l = left(i);
            int r = right(i);
            int biggest = i;
            if (l < this->maxHeap.size() && this->maxHeap[l] > this->maxHeap[biggest])
            {
                biggest = l;
            }
            if (r < this->maxHeap.size() && this->maxHeap[r] > this->maxHeap[biggest])
            {
                biggest = r;
            }
            if (biggest == i)
            {
                return;
            }
            swap(this->maxHeap[i], this->maxHeap[biggest]);
            i = biggest;
        }
    }

public:
    ArrQueue (vector<int> arr)
    {
        this->maxHeap = arr;
        for (int i = this->parent(this->maxHeap.size() - 1); i >= 0; i--)
        {
            siftDown(i);
        }
    }

    void push (int value)
    {
        this->maxHeap.push_back(value);
        siftUp(maxHeap.size() - 1);
    }

    void pop ()
    {
        if (this->maxHeap.empty())
        {
            throw out_of_range("Queue is empty");
        }
        swap(this->maxHeap[0], this->maxHeap[this->maxHeap.size() - 1]);
        this->maxHeap.pop_back();
        siftDown(0);
    }

    vector<int> getQueue ()
    {
        return this->maxHeap;
    }
};

class sortHeap
{
private:
    vector<int> maxHeap;

    int parent (int i)
    {
        return (i - 1) / 2;
    }

    void siftUp (int i)
    {
        while (true)
        {
            int p = this->parent(i);
            if (p < 0 || this->maxHeap[p] <= this->maxHeap[i])
            {
                return;
            }
            swap(this->maxHeap[p], this->maxHeap[i]);
            i = p;
        }
    }

    void siftDown (int i)
    {
        while (true)
        {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int biggest = i;
            if (l < this->maxHeap.size() && this->maxHeap[l] < this->maxHeap[biggest])
            {
                biggest = l;
            }
            if (r < this->maxHeap.size() && this->maxHeap[r] < this->maxHeap[biggest])
            {
                biggest = r;
            }
            if (biggest == i)
            {
                return;
            }
            swap(this->maxHeap[i], this->maxHeap[biggest]);
            i = biggest;
        }
    }

    void pop ()
    {
        if (this->maxHeap.size() == 0)
        {
            throw out_of_range("Heap is empty");
        }
        swap(this->maxHeap[0], this->maxHeap[this->maxHeap.size() - 1]);
        this->maxHeap.pop_back();
        this->siftDown(0);
    }

public:
    vector<int> sort (int num, vector<int> arr)
    {
        if (arr.size() < num)
        {
            throw out_of_range("Not enough elements");
        }
        for (int i = 0; i < num; i++)
        {
            this->maxHeap.push_back(arr[i]);
            this->siftUp(this->maxHeap.size() - 1);
        }
        for (int i = num; i < arr.size(); i++)
        {
            if (this->maxHeap[0] < arr[i])
            {
                this->pop();
                this->maxHeap.push_back(arr[i]);
                this->siftUp(this->maxHeap.size() - 1);
            }
        }
        return this->maxHeap;
    }
};

class graphAdjMat
{
private:
    vector<int> vertices;
    vector<vector<int>> adjMat;
public:
    graphAdjMat (const vector<int> &vertices, const vector<vector<int>> &adjMat)
    {
        for (auto &i: vertices)
        {
            addVertex(i);
        }
        for (const auto &i: adjMat)
        {
            addEdge(i[0], i[1]);
        }
    }

    int size () const
    {
        return this->vertices.size();
    }

    void addVertex (int value)
    {
        int n = this->size();
        this->vertices.push_back(value);
        this->adjMat.emplace_back(vector<int>(n, 0));
        for (auto &row: this->adjMat)
        {
            row.push_back(0);
        }
    }

    void removeVertex (int index)
    {
        if (index < 0 || index >= this->size())
        {
            throw out_of_range("Invalid vertex");
        }
        this->vertices.erase(this->vertices.begin() + index);
        this->adjMat.erase(this->adjMat.begin() + index);
        for (auto &row: this->adjMat)
        {
            row.erase(row.begin() + index);
        }
    }

    void addEdge (int from, int to)
    {
        if (from < 0 || to < 0 || from >= this->size() || to >= this->size() || from == to)
        {
            throw out_of_range("Invalid edge");
        }
        this->adjMat[from][to] = 1;
        this->adjMat[to][from] = 1;
    }

    void delEdge (int from, int to)
    {
        if (from < 0 || to < 0 || from >= this->size() || to >= this->size() || from == to)
        {
            throw out_of_range("Invalid edge");
        }
        this->adjMat[from][to] = 0;
        this->adjMat[to][from] = 0;
    }

    void print ()
    {
        for (auto &i: this->vertices)
        {
            cout << i << " ";
        }
        cout << endl;
        for (auto &i: this->adjMat)
        {
            for (auto &j: i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

class Vertex
{
public:
    int id;

    Vertex (int id) : id(id)
    {}
};

class graphAdjList
{
public:
    unordered_map<Vertex *, vector<Vertex *>> adjList;

    void remove (vector<Vertex *> &vec, Vertex *ver)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            if (vec[i] == ver)
            {
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }

    graphAdjList (const vector<vector<Vertex *>> &mat)
    {
        for (auto &i: mat)
        {
            this->addVertex(i[0]);
            this->addVertex(i[1]);
            this->addEdge(i[0], i[1]);
        }
    }

    int getSize ()
    {
        return this->adjList.size();
    }

    void addEdge (Vertex *from, Vertex *to)
    {
        if (!this->adjList.count(from) || !this->adjList.count(to) || from == to)
        {
            throw out_of_range("Invalid edge");
        }
        this->adjList[from].push_back(to);
        this->adjList[to].push_back(from);
    }

    void removeEdge (Vertex *from, Vertex *to)
    {
        if (!this->adjList.count(from) || !this->adjList.count(to) || from == to)
        {
            throw out_of_range("Invalid edge");
        }
        this->remove(this->adjList[from], to);
        this->remove(this->adjList[to], from);
    }

    void addVertex (Vertex *ver)
    {
        if (this->adjList.count(ver))
        {
            throw out_of_range("Vertex already exists");
        }
        adjList[ver] = vector<Vertex *>();
    }

    void deleteVertex (Vertex *ver)
    {
        if (!this->adjList.count(ver))
        {
            throw out_of_range("Vertex does not exist");
        }
        this->adjList.erase(ver);
        for (auto &i: this->adjList)
        {
            remove(i.second, ver);
        }
    }

    void print ()
    {
        for (auto &i: this->adjList)
        {
            cout << i.first->id << " ";
            for (auto &j: i.second)
            {
                cout << j->id << " ";
            }
            cout << endl;
        }
    }
};

vector<Vertex *> BFS (graphAdjList &graph, Vertex *start)
{
    vector<Vertex *> result;
    unordered_set<Vertex *> visited = {start};
    queue<Vertex *> q;
    q.push(start);
    while (!q.empty())
    {
        Vertex *current = q.front();
        q.pop();
        result.push_back(current);
        for (auto &i: graph.adjList[current])
        {
            if (visited.count(i))
            {
                continue;
            }
            q.push(i);
            visited.insert(i);
        }
    }
    return result;
}

void dfs (graphAdjList &graph, unordered_set<Vertex *> &visited, vector<Vertex *> &res, Vertex *vet)
{
    res.push_back(vet);
    visited.emplace(vet);
    for (auto &i: graph.adjList[vet])
    {
        if (visited.count(i))
        {
            continue;
        }
        dfs(graph, visited, res, i);
    }
}

vector<Vertex *> DFS (graphAdjList &graph, Vertex *start)
{
    vector<Vertex *> result;
    unordered_set<Vertex *> visited = {};
    dfs(graph, visited, result, start);
    return result;
}

int binarySearch (vector<int> &num, int target)
{
    int i = 0;
    int j = num.size() - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (num[mid] < target)
        {
            i = mid + 1;
        } else if (num[mid] > target)
        {
            j = mid - 1;
        } else
        {
            return mid;
        }
    }
    return -1;
}

int binarySearchInsertionSimple (vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (nums[mid] > target)
        {
            i = mid + 1;
        } else if (nums[mid] < target)
        {
            j = mid - 1;
        } else
        {
            return mid;
        }
    }
    return i;
}

int binarySearchInsertion (vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (nums[mid] > target)
        {
            j = mid - 1;
        } else if (nums[mid] < target)
        {
            i = mid + 1;
        } else
        {
            j = mid - 1;
        }
    }
    return i;
}

int binarySearchLeftEdge (vector<int> &nums, int target)
{
    int i = binarySearchInsertion(nums, target);
    if (i == nums.size() || nums[i] != target)
    {
        return -1;
    }
    return i;
}

int binarySearchRightEdge (vector<int> &nums, int target)
{
    int i = binarySearchInsertion(nums, target + 1);
    int j = i - 1;
    if (j == -1 || nums[j] != target)
    {
        return -1;
    }
    return j;
}

vector<int> twoSumHash (vector<int> &num, int target)
{
    unordered_map<int, int> dic;
    for (int i = 0; i < num.size(); ++i)
    {
        if (dic.find(target - num[i]) != dic.end())
        {
            return {dic[target - num[i]], i};
        }
        dic.insert(pair<int, int>{num[i], i});
    }
    return {};
}

void selectionSort (vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        int k = i;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[j] < nums[k])
            {
                k = j;
            }
            swap(nums[i], nums[k]);
        }
    }
}

void print (vector<int> &num)
{
    for (auto &i: num)
    {
        cout << i << " ";
    }
}

void bubbleSort (vector<int> &nums)
{
    for (int i = nums.size() - 1; i > 0; --i)
    {
        bool flag = true;
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

void insertionSort (vector<int> &nums)
{
    for (int i = 1; i < nums.size(); ++i)
    {
        int base = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > base)
        {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = base;
    }
}

int partition (vector<int> &nums, int low, int high)
{
    int i = low;
    int j = high;
    while (i < j)
    {
        while (i < j && nums[j] >= nums[low])
        {
            j--;
        }
        while (i < j && nums[i] <= nums[low])
        {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[low]);
    return i;
}

void quickSort (vector<int> &nums, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pivot = partition(nums, low, high);
    quickSort(nums, low, pivot - 1);
    quickSort(nums, pivot + 1, high);
}

void merge (vector<int> &nums, int low, int mid, int high)
{
    vector<int> tem(high - low + 1);
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (nums[i] <= nums[j])
        {
            tem[k++] = nums[i++];
        } else
        {
            tem[k++] = nums[j++];
        }
    }
    while (i <= mid)
    {
        tem[k++] = nums[i++];
    }
    while (j <= high)
    {
        tem[k++] = nums[j++];
    }
    for (k = 0; k < tem.size(); k++)
    {
        nums[low + k] = tem[k];
    }
}

void mergeSort (vector<int> &nums, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

void siftDown (vector<int> &nums, int n, int i)
{
    while (true)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int max = i;
        if (l < n && nums[l] > nums[max])
        {
            max = l;
        }
        if (r < n && nums[r] > nums[max])
        {
            max = r;
        }
        if (max == i)
        {
            break;
        }
        swap(nums[i], nums[max]);
        i = max;
    }
}

void heapSort (vector<int> &nums)
{
    for (int i = nums.size() / 2 - 1; i >= 0; i--)
    {
        siftDown(nums, nums.size(), i);
    }
    for (int i = nums.size() - 1; i > 0; --i)
    {
        swap(nums[0], nums[i]);
        siftDown(nums, i, 0);
    }
}

void countingSortNaive (vector<int> &nums)
{
    int max = 0;
    for (auto &i: nums)
    {
        max = max > i ? max : i;
    }
    vector<int> count(max + 1, 0);
    for (auto &i: nums)
    {
        count[i]++;
    }
    int num = 0;
    for (int i = 0; i < max + 1; ++i)
    {
        for (int j = 0; j < count[i]; ++j, ++num)
        {
            nums[num] = i;
        }
    }
}

void countingSort (vector<int> &nums)
{
    int m = 0;
    for (auto &num: nums)
    {
        m = m > num ? m : num;
    }
    vector<int> count(m + 1, 0);
    for (auto &num: nums)
    {
        count[num]++;
    }
    for (int i = 0; i < m + 1; ++i)
    {
        count[i + 1] += count[i];
    }
    int n = nums.size();
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
    {
        int num = nums[i];
        res[count[num] - 1] = num;
        count[num]--;
    }
    nums = res;
}

int digit (int num, int exp)
{
    return (num / exp) % 10;
}

void countingSortDigit (vector<int> &nums, int exp)
{
    vector<int> counter(10, 0);
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        int d = digit(nums[i], exp);
        counter[d]++;
    }
    for (int i = 1; i < 10; ++i)
    {
        counter[i] += counter[i - 1];
    }
    vector<int> res(n, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        int d = digit(nums[i], exp);
        int j = counter[d] - 1;
        res[j] = nums[i];
        counter[d]--;
    }
    nums = res;
}

void radixSort (vector<int> &nums)
{
    int max = *max_element(nums.begin(), nums.end());
    for (int exp = 1; exp <= max; exp *= 10)
    {
        countingSortDigit(nums, exp);
    }
}

int dfsSearch (vector<int> &nums, int target, int begin, int end)
{
    if (begin > end)
    {
        return -1;
    }
    int mid = (begin + end) / 2;
    if (nums[mid] > target)
    {
        return dfsSearch(nums, target, begin, mid - 1);
    } else if (nums[mid] < target)
    {
        return dfsSearch(nums, target, mid + 1, end);
    } else
    {
        return mid;
    }
}

treeNode *dfsBuildTree (vector<int> &pre, unordered_map<int, int> &inorder, int i, int r, int l)
{
    if (r - l < 0)
    {
        return nullptr;
    }
    treeNode *root = new treeNode(pre[i]);
    int mid = inorder[pre[i]];
    root->left = dfsBuildTree(pre, inorder, i + 1, mid - 1, l);
    root->right = dfsBuildTree(pre, inorder, i + mid - l + 1, r, mid + 1);
    return root;
}

treeNode *buildTree (vector<int> &pre, vector<int> &in)
{
    unordered_map<int, int> inorder;
    for (int i = 0; i < in.size(); ++i)
    {
        inorder[in[i]] = i;
    }
    treeNode *root = dfsBuildTree(pre, inorder, 0, pre.size() - 1, 0);
    return root;
}

void move (stack<int> &src, stack<int> &tar)
{
    tar.push(src.top());
    src.pop();
}

void dfsHanota (int n, stack<int> &src, stack<int> &buf, stack<int> &tar)
{
    if (n == 1)
    {
        move(src, tar);
        return;
    }
    dfsHanota(n - 1, src, tar, buf);
    move(src, tar);
    dfsHanota(n - 1, buf, src, tar);
}

void hanota (stack<int> &A, stack<int> &B, stack<int> &C)
{
    int n = A.size();
    dfsHanota(n, A, B, C);
}

void backTrack (vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res)
{
    if (state.size() == choices.size())
    {
        res.push_back(state);
        for (auto &i: state)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < choices.size(); i++)
    {
        int choice = choices[i];
        if (!selected[i])
        {
            selected[i] = true;
            state.push_back(choice);
            backTrack(state, choices, selected, res);
            selected[i] = false;
            state.pop_back();
        }
    }
}

vector<vector<int>> permute (vector<int> &nums)
{
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backTrack(state, nums, selected, res);
    return res;
}

void backtrace (vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res)
{
    if (state.size() == choices.size())
    {
        res.push_back(state);
        for (auto &i: state)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    unordered_set<int> dulicated;
    for (int i = 0; i < choices.size(); i++)
    {
        int choice = choices[i];
        if (!selected[i] && dulicated.find(choice) == dulicated.end())
        {
            dulicated.insert(choice);
            selected[i] = true;
            state.push_back(choice);
            backtrace(state, choices, selected, res);
            selected[i] = false;
            state.pop_back();
        }
    }
}

void backtrack (vector<int> &state, vector<int> &choices, int target, int total, vector<vector<int>> &res)
{
    if (total == target)
    {
        res.push_back(state);
        return;
    }
    for (int i = 0; i < choices.size(); ++i)
    {
        if (total + choices[i] > target)
        {
            return;
        }
        state.push_back(choices[i]);
        backtrack(state, choices, target, total + choices[i], res);
        state.pop_back();
    }
}

vector<vector<int>> subsetSumINaive (vector<int> &choice, int target)
{
    sort(choice.begin(), choice.end());
    int total = 0;
    vector<vector<int>> res;
    vector<int> state;
    backtrack(state, choice, target, total, res);
    return res;
}

vector<vector<int>> permute1 (vector<int> &nums)
{
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backtrace(state, nums, selected, res);
    return res;
}

void backtrack1 (vector<int> &choices, vector<int> &state, int start, int target, int total, vector<vector<int>> &res)
{
    if (target == total)
    {
        res.push_back(state);
        return;
    }
    for (int i = start; i < choices.size(); ++i)
    {
        if (total + choices[i] > target)
        {
            return;
        }
        state.push_back(choices[i]);
        backtrack1(choices, state, i, target, total + choices[i], res);
        state.pop_back();
    }
}

vector<vector<int>> subsetSumI (vector<int> &nums, int target)
{
    set<int> num;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        num.insert(nums[i]);
    }
    std::vector<int> choices(num.begin(), num.end());
    std::vector<vector<int>> res;
    vector<int> state;
    backtrack1(choices, state, 0, target, 0, res);
    return res;
}

void backtrack2 (vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(state);
        return;
    }
    for (int i = start; i < choices.size(); i++)
    {
        if (target - choices[i] < 0)
        {
            break;
        }
        state.push_back(choices[i]);
        backtrack2(state, target - choices[i], choices, i, res);
        state.pop_back();
    }
}

vector<vector<int>> subsetSumI2 (vector<int> &nums, int target)
{
    vector<int> state;
    sort(nums.begin(), nums.end());
    int start = 0;
    vector<vector<int>> res;
    backtrack2(state, target, nums, start, res);
    return res;
}

void backtrack (int row, int n, vector<vector<int>> &state, vector<vector<vector<int>>> &res, vector<bool> &cols,
                vector<bool> &diags1, vector<bool> &diags2)
{
    if (row == n)
    {
        res.push_back(state);
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        int diag1 = row - i + n - 1;
        int diag2 = row + i;
        if (!cols[i] && !diags1[diag1] && !diags2[diag2])
        {
            state[row][i] = 1;
            cols[i] = diags1[diag1] = diags2[diag2] = true;
            backtrack(row + 1, n, state, res, cols, diags1, diags2);
            state[row][i] = 0;
            cols[i] = diags1[diag1] = diags2[diag2] = false;
        }
    }
}

vector<vector<vector<int>>> nQueens (int n)
{
    vector<vector<int>> state(n, vector<int>(n, 0));
    vector<bool> cols(n, false);
    vector<bool> diags1(2 * n - 1, false);
    vector<bool> diags2(2 * n - 1, false);
    vector<vector<vector<int>>> res;
    backtrack(0, n, state, res, cols, diags1, diags2);
    return res;
}

void backtrack (vector<int> &choice, int total, int state, vector<vector<int>> &res)
{
    if (total == state)
    {
        res.push_back(choice);
        return;
    }
    if (state > total)
    {
        return;
    }
    choice.push_back(1);
    backtrack(choice, total, state + 1, res);
    choice.pop_back();
    choice.push_back(2);
    backtrack(choice, total, state + 2, res);
    choice.pop_back();
}

vector<vector<int>> climbingStairsBacktrack (int num)
{
    vector<int> choices;
    vector<vector<int>> res;
    backtrack(choices, num, 0, res);
    return res;
}

int dfs (int i)
{
    if (i == 1 || i == 2)
    {
        return i;
    }
    int count = dfs(i - 1) + dfs(i - 2);
    return count;
}

int dfs (int i, vector<int> &num)
{
    if (i == 1 || i == 2)
    {
        return i;
    }
    if (num[i] != -1)
    {
        return num[i];
    }
    int count = dfs(i - 1) + dfs(i - 2);
    num[i] = count;
    return count;
}

int climbingStairsDFSMem (int i)
{
    vector<int> nums(i + 1, -1);
    return dfs(i, nums);
}

int climbingStairsDP (int i)
{
    if (i == 1 || i == 2)
    {
        return i;
    }
    int DP1 = 1;
    int DP2 = 2;
    int DP3 = DP1 + DP2;
    for (int j = 3; j <= i; j++)
    {
        DP3 = DP1 + DP2;
        DP1 = DP2;
        DP2 = DP3;
    }
    return DP3;
}

int minCostClimbingStairsDP (vector<int> &cost)
{
    int n = cost.size() - 1;
    if (n == 1 || n == 2)
    {
        return cost[n];
    }
    vector<int> dp(n + 1, 0);
    dp[1] = cost[1];
    dp[2] = cost[2];
    for (int i = 3; i <= n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return dp[n];
}

int climbingStairsConstraintDP (int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    }
    return dp[n][1] + dp[n][2];
}

int minPathSumDFS (vector<vector<int>> &grid, int i, int j)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    int up = minPathSumDFS(grid, i - 1, j);
    int left = minPathSumDFS(grid, i, j - 1);
    return min(up, left) != INT_MAX ? grid[i][j] + min(up, left) : INT_MAX;
}

int minPathSumDFSMem (vector<vector<int>> &grid, int i, int j, vector<vector<int>> &mem)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    int up = minPathSumDFSMem(grid, i - 1, j, mem);
    int left = minPathSumDFSMem(grid, i, j - 1, mem);
    mem[i][j] = min(up, left) != INT_MAX ? grid[i][j] + min(up, left) : INT_MAX;
    return mem[i][j];
}

int minPathSumDP (vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    std::vector<vector<int>> dp(n, std::vector<int>(m, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; ++i)
    {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

int minPathSumDPComp (vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> dp(m, 0);
    dp[0] = grid[0][0];
    for (int j = 1; j < m; ++j)
    {
        dp[j] = dp[j - 1] + grid[0][j];
    }
    for (int i = 1; i < n; ++i)
    {
        dp[0] += grid[i][0];
        for (int j = 1; j < m; ++j)
        {
            dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
        }
    }
    return dp[m - 1];
}

int knapsackDFS (vector<int> &wgt, vector<int> &val, int i, int cap)
{
    if (i == 0 || cap == 0)
    {
        return 0;
    }
    if (wgt[i - 1] > cap)
    {
        return knapsackDFS(wgt, val, i - 1, cap);
    }
    int no = knapsackDFS(wgt, val, i - 1, cap);
    int yes = val[i - 1] + knapsackDFS(wgt, val, i - 1, cap - wgt[i - 1]);
    return max(no, yes);
}

int knapsackDFSmem (vector<int> &wgt, vector<int> &val, int i, int cap, vector<vector<int>> &mem)
{
    if (i == 0 || cap == 0)
    {
        return 0;
    }
    if (mem[i][cap] != -1)
    {
        return mem[i][cap];
    }
    if (wgt[i - 1] > cap)
    {
        return knapsackDFS(wgt, val, i - 1, cap);
    }
    int no = knapsackDFS(wgt, val, i - 1, cap);
    int yes = val[i - 1] + knapsackDFS(wgt, val, i - 1, cap - wgt[i - 1]);
    mem[i][cap] = max(no, yes);
    return mem[i][cap];
}

int knapsackBF (vector<int> &wgt, vector<int> &val, int cap)
{
    int n = wgt.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= cap; ++j)
        {
            if (wgt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            } else
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wgt[i - 1]]);
            }
        }
    }
    return dp[n][cap];
}

int knapsackDPComp (vector<int> &wgt, vector<int> &val, int cap)
{
    int n = wgt.size();
    vector<int> dp(cap + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = cap; j >= 1; --j)
        {
            if (wgt[i - 1] > j)
            {
                continue;
            } else
            {
                dp[j] = max(dp[j], val[i - 1] + dp[j - wgt[i - 1]]);
            }
        }
    }
    return dp[cap];
}

int knapsackDPCompSame (vector<int> &wgt, vector<int> &val, int cap)
{
    int n = wgt.size();
    vector<int> dp(cap + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= cap; ++j)
        {
            if (wgt[i - 1] > j)
            {
                continue;
            } else
            {
                dp[j] = max(dp[j], val[i - 1] + dp[j - wgt[i - 1]]);
            }
        }
    }
    return dp[cap];
}

int knapsackBFSame (vector<int> &wgt, vector<int> &val, int cap)
{
    int n = wgt.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= cap; ++j)
        {
            if (wgt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            } else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][cap];
}

int coinChangeDP (vector<int> &coins, int amount)
{
    int n = coins.size();
    int MAX_COUNT = amount + 1;
    vector<vector<int>> dp(n + 1, vector<int>(MAX_COUNT, 0));
    for (int i = 1; i <= amount; ++i)
    {
        dp[0][i] = MAX_COUNT;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= amount; ++j)
        {
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            } else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
    }
    return dp[n][amount] == MAX_COUNT ? -1 : dp[n][amount];
}

int coinChangeDPComp (vector<int> &coins, int amt)
{
    int n = coins.size();
    int MAX_COUNT = amt + 1;
    vector<int> dp(MAX_COUNT, MAX_COUNT);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= amt; ++j)
        {
            if (coins[i - 1] > j)
            {
                dp[j] = dp[j];
            } else
            {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }
    }
    return dp[amt] == MAX_COUNT ? -1 : dp[amt];
}

void DFS (vector<int> &coins, int amount, int total, vector<int> &choices, vector<vector<int>> &allComb,
          vector<bool> &selected)
{
    if (amount == 0)
    {
        return;
    }
    if (total == amount && !selected[choices.size() - 1])
    {
        selected[choices.size() - 1] = true;
        allComb.push_back(choices);
        return;
    }
    for (int i = 0; i < coins.size() && total < amount; ++i)
    {
        choices.push_back(coins[i]);
        DFS(coins, amount, total + coins[i], choices, allComb, selected);
        choices.pop_back();
    }
}

vector<vector<int>> coinChangeIIDFS (vector<int> &coins, int amount)
{
    sort(coins.begin(), coins.end());
    vector<bool> selected;
    vector<vector<int>> res;
    selected.resize(amount / coins[0] + 1, false);
    vector<int> choices;
    DFS(coins, amount, 0, choices, res, selected);
    return res;
}

int main ()
{
    vector<int> coins = {1, 2, 5};
    vector<vector<int>> res = coinChangeIIDFS(coins, 11);
    return 0;
}
