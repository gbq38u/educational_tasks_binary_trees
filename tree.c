#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
Node* create_node(int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Ошибка\n");
        exit(1);
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;}
Tree tree_insert(Tree root, int value) {
    if (root == NULL) {
        return create_node(value);}
    if (value < root->value) {
        root->left = tree_insert(root->left, value);
    } else if (value > root->value) {
        root->right = tree_insert(root->right, value);
    } else {}

    return root;}
Tree read_tree(void) {
    Tree root = NULL;
    int x;
    while (scanf("%d", &x) ==1 && x != 0) {
        root = tree_insert(root,x);
    }
    return root;
}
void tree_free(Tree root) {
    if (!root) return;
    tree_free(root->left);
    tree_free(root->right);
    free(root);}
int tree_height(Tree root) {
    if (root == NULL) return 0;
    int hl = tree_height(root->left);
    int hr = tree_height(root->right);
    return (hl > hr ? hl : hr)+ 1;
}
