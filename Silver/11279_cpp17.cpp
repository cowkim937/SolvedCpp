#include <iostream>
#include <memory>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Node {
public:
    int data;
    unique_ptr<Node> left, right;
    Node* parent;

    explicit Node(int val, Node* parent = nullptr);
};

class BinaryTree {
public:
    BinaryTree();
    void insert(int data);
    int extractMax();
    bool IsEmpty();
private:
    unique_ptr<Node> root;

    void swap(Node* a, Node* b);
    void heapifyUp(Node* node);
    void heapifyDown(Node* node);
    Node* findInsertionPoint();
    Node* findLastNode();
};

// Node 생성자
Node::Node(int val, Node* parent) : data(val), parent(parent) {}

// BinaryTree 생성자
BinaryTree::BinaryTree() : root(nullptr) {}

// Heap이 비었는지 확인
bool BinaryTree::IsEmpty() {
    return root == nullptr;
}

// 두 노드의 데이터를 교환
void BinaryTree::swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Heapify Up (삽입 후 위로 이동)
void BinaryTree::heapifyUp(Node* node) {
    while (node->parent && node->parent->data < node->data) {
        swap(node, node->parent);
        node = node->parent;
    }
}

// Heapify Down (삭제 후 아래로 이동)
void BinaryTree::heapifyDown(Node* node) {
    while (node->left) {
        Node* largest = node->left.get();
        if (node->right && node->right->data > node->left->data)
            largest = node->right.get();

        if (node->data > largest->data)
            break;

        swap(node, largest);
        node = largest;
    }
}

// 삽입 위치 찾기 (BFS)
Node* BinaryTree::findInsertionPoint() {
    if (!root) return nullptr;

    queue<Node*> q;
    q.push(root.get());

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (!current->left || !current->right)
            return current;

        q.push(current->left.get());
        q.push(current->right.get());
    }
    return nullptr;
}

// 마지막 노드 찾기 (BFS)
Node* BinaryTree::findLastNode() {
    if (!root) return nullptr;

    queue<Node*> q;
    q.push(root.get());
    Node* lastNode = nullptr;

    while (!q.empty()) {
        lastNode = q.front();
        q.pop();
        if (lastNode->left) q.push(lastNode->left.get());
        if (lastNode->right) q.push(lastNode->right.get());
    }
    return lastNode;
}

// 삽입 연산
void BinaryTree::insert(int data) {
    if (!root) {
        root.reset(new Node(data));  // make_unique 대신 reset 사용
        return;
    }

    Node* parent = findInsertionPoint();
    unique_ptr<Node> newNode(new Node(data, parent));  // make_unique 대신 new 사용

    if (!parent->left)
        parent->left = move(newNode);
    else
        parent->right = move(newNode);

    heapifyUp(parent->left ? parent->left.get() : parent->right.get());
}

// 최대값 추출
int BinaryTree::extractMax() {
    if (IsEmpty()) {
        cerr << "Heap is empty!\n";
        return -1;
    }

    int maxVal = root->data;
    Node* lastNode = findLastNode();

    if (root.get() == lastNode) {
        root.reset();
        return maxVal;
    }

    root->data = lastNode->data;

    // 마지막 노드 삭제
    if (lastNode->parent->left.get() == lastNode)
        lastNode->parent->left.reset();
    else
        lastNode->parent->right.reset();

    heapifyDown(root.get());

    return maxVal;
}

// Main function to test
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    BinaryTree heap;

    cin >> n;
    while(n--){
        cin >> x;
        if(x == 0)
            cout << (heap.IsEmpty() ? 0 : heap.extractMax()) << "\n";
        else
            heap.insert(x);
    }
    return 0;
}
