#include <stdbool.h>
#include <stdio.h>

typedef struct node Node;
struct node {
    int value;
    Node* left;
    Node* right;
};

typedef struct bst BST;
struct bst {
    Node* root;
    int height;
};

BST* mkBST() {
    BST* bst = malloc(sizeof(BST));
    if (!bst) return NULL;

    *bst = (BST){.height = -1, .root = NULL};
    return bst;
}

bool searchR(Node* node, int key);
bool search(BST* bst, int key) {
    if (!bst) return false;

    return searchR(bst->root, key);
}

bool searchR(Node* node, int key) {
    if (node == NULL) return false;

    if (node->value == key) return true;

    if (key < node->value) return searchR(node->left, key);

    return searchR(node->right, key);
}

bool addR(Node* node, int value);
bool add(BST* bst, int value) {
    if (!bst) {
        return NULL;
    }

    return addR(bst->root, value);
}

bool addR(Node* node, int value) {
    if (node == NULL) {
        return 1;
    }
}
