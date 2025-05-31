#include <iostream>

using namespace std;

class BinaryTree {
public:
    typedef struct _node {
        char data;
        struct _node* left;
        struct _node* right;
        _node(char d, _node* l = nullptr, _node* r = nullptr) : data(d), left(l), right(r) {}
    }Node;

    Node* root;

    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { destroyTree(root); }

    void insert(char data, char left, char right);
    void preOrder() { preOrder(root); }
    void inOrder() { inOrder(root); }
    void postOrder() { postOrder(root); }
    Node* InnerSearch(Node* node, char data);

private:
    void destroyTree(Node* node);
    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);
};

void BinaryTree::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BinaryTree::insert(char data, char left, char right) {
    if (root == nullptr) {
        root = new Node(data);
        if (left != '.') root->left = new Node(left);
        if (right != '.') root->right = new Node(right);
    } else {
        Node* node = InnerSearch(root, data);
        if (node != nullptr) {
            if (left != '.') node->left = new Node(left);
            if (right != '.') node->right = new Node(right);
        }
    }
}

BinaryTree::Node* BinaryTree::InnerSearch(Node *node, char data) {
    if (node == nullptr) return nullptr;
    if (node->data == data)
        return node;

    Node* result = InnerSearch(node->left, data);
    if (result == nullptr)
        result = InnerSearch(node->right, data);
    return result;
}

void BinaryTree::preOrder(Node* node) {
    if (node) {
        cout << node->data;
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BinaryTree::inOrder(Node* node) {
    if (node) {
        inOrder(node->left);
        cout << node->data;
        inOrder(node->right);
    }
}

void BinaryTree::postOrder(Node* node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data;
    }
}

int main() {
    BinaryTree node;
    int n;
    char a,b,c;
    cin >> n;

    while(n--){
        cin >> a >> b >> c;
        node.insert(a, b, c); 
    }

    node.preOrder();
    cout << endl;

    node.inOrder();
    cout << endl;

    node.postOrder();
    cout << endl;

    return 0;
}