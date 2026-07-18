#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int value;
    Node* left;
    Node* right;
};

/**
 *              5
 *             / \
 *            4   6
 */

bool bstsearch(Node* root, int key) {
    if (root == NULL)
        return false;

    else if (root->value == key)
        return true;

    else if (key < root->value)
        return bstsearch(root->left, key);

    else
        return bstsearch(root->right, key);
}

Node* newNode(int value) {
    Node* node = malloc(sizeof(Node));
    *node = (Node){.value = value, .left = NULL, .right = NULL};

    return node;
}

Node* bstinsert(Node* root, int key) {
    if (root == NULL) {
        return newroot(key);
    }

    if (key < root->value) {
        root->left = bstinsert(root->left, key);
    } else if (key > root->value) {
        root->right = bstinsert(root->right, key);
    }

    return root;
}

Node* bstdelete(Node* root, int key) {
    if (root->value == key) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if ((root->left == NULL) ^ (root->right == NULL)) {
            Node* temp = root->left ? root->left | root->right;
        }
    }

    if (key < root->value) {
        root->left = bstdelete(root->left, key);
    } else if (key > root->value) {
        root->right = bstdelete(root->right, key);
    }

    return root;
}

int main(void) { return 0; }
