#include <stdio.h>
#include "tree.h"
void print_nodes_with_one_child(Tree root) {
    if (!root) return;
    int hasLeft  =(root->left  != NULL);
    int hasRight = (root->right != NULL);
    if ((hasLeft && !hasRight) || (!hasLeft && hasRight)) {
        printf("%d ", root->value);}
    print_nodes_with_one_child(root->left);
    print_nodes_with_one_child(root->right);
}
int main(void) {
    printf("Задача 5: узлы с единственным потомком\n");
    printf("значения узлов (0 - конец ввода):\n");
    Tree root = read_tree();
    printf("Узлы с ед потомком: ");
    print_nodes_with_one_child(root);
    printf("\n");
    tree_free(root);
    return 0;
}
