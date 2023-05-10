#include <stdio.h>
#include <stdlib.h>

typedef struct treenode tree_node;

struct treenode {
    int data;
    tree_node *left;
    tree_node *right;
};

tree_node *root = NULL;

tree_node* insertLeftNode(tree_node **root, int data){
    tree_node *left = (tree_node*)malloc(sizeof(tree_node));
    tree_node *i = *root;
    tree_node *r = i;

    r->left = left;

    return r->left;
}

tree_node* insertRightNode(tree_node **root, int data){
    tree_node *right = (tree_node*)malloc(sizeof(tree_node));
    tree_node *i = *root;
    tree_node *r = i;
    r->right = right;

    return r->right;
}

tree_node* create_node(int data) {
    tree_node *newNode = (tree_node*)malloc(sizeof(tree_node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

void preorder_traversal(tree_node **root){
    if (root != NULL) {
        tree_node *i = *root;
        tree_node *r = i;
        printf("%d ", r->data);
        preorder_traversal(&r->left);
        preorder_traversal(&r->right);
    }
}

void inorder_traversal(tree_node *root){
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(tree_node *root){
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    tree_node *root = create_node(1);
    tree_node *left = insertLeftNode(root, 2);
    tree_node *right = insertRightNode(root, 3);

    insertLeftNode(left, 4);
    insertRightNode(left, 5);

    root = create_node(1);
    tree_node *left = insertLeftNode(&root, 2);
    tree_node *right = insertRightNode(&root, 3);

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    preorder_traversal(&root);
    inorder_traversal(&root);
    postorder_traversal(&root);

    return 0;
}
