#include <iostream>

// Node structure for the BST
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Function to search a key in the BST
Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// Function to insert a new key in the BST
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Function to find the minimum key node in the BST
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// Function to delete a key from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

// Main function to demonstrate the BST operations
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    std::cout << "Inorder traversal of the given tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Delete 20\n";
    root = deleteNode(root, 20);
    std::cout << "Inorder traversal of the modified tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Delete 30\n";
    root = deleteNode(root, 30);
    std::cout << "Inorder traversal of the modified tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Delete 50\n";
    root = deleteNode(root, 50);
    std::cout << "Inorder traversal of the modified tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    Node* result = search(root, 40);
    if (result) {
        std::cout << "Found: " << result->key << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}
