#ifndef TREE_H
#define TREE_H
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;
typedef Node* Tree;
Node* create_node(int value);
Tree tree_insert(Tree root, int value);
Tree read_tree(void);
void tree_free(Tree root);
int tree_height(Tree root);
#endif 
