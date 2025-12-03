#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
void fill_level_counts(Tree root, int level, int *counts) {
    if (!root) return;
    counts[level]++;  
    fill_level_counts(root->left,  level +1, counts);
    fill_level_counts(root->right, level + 1, counts);}
int tree_width(Tree root) {
    if (!root) return 0;
    int h = tree_height(root);              
    int *counts = (int*)calloc(h, sizeof(int));
    if (!counts) {
        printf("Ошибка \n");
        exit(1);
    }
    fill_level_counts(root,0, counts);

    int max = 0;
    for (int i =0; i< h; ++i) {
        if (counts[i] > max) max = counts[i];}
    free(counts);
    return max;}
int main(void) {
    printf("задача 2:ширина дерева\n");
    printf("значения узлов (0 -конец ввода):\n");
    Tree root = read_tree();
    int width = tree_width(root);
    printf("ширина= %d\n", width);
    tree_free(root);
    return 0;
}
