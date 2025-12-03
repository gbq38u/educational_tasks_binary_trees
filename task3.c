#include <stdio.h>
#include "tree.h"

void find_minmax_depth(Tree root, int depth, int *minD, int *maxD) {
    if (!root) return;
    if (root->left == NULL && root->right == NULL) {
        if (depth < *minD) *minD = depth;
        if (depth > *maxD) *maxD = depth;
        return;
    }

    if (root->left)  find_minmax_depth(root->left,  depth + 1, minD, maxD);
    if (root->right) find_minmax_depth(root->right, depth +1, minD, maxD);}

int main(void) {
    printf("Задача 3: min и max глубина\n");
    printf(" значения узлов\n");
    Tree root = read_tree();
    int minD = 1000000000; 
    int maxD = 0;
    find_minmax_depth(root, 1, &minD, &maxD);
    printf("min глубина = %d\n", minD);
    printf("max глубина = %d\n", maxD);
    tree_free(root);
    return 0;
}
