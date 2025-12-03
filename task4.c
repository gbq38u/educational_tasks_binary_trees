#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
void find_paths_with_sum(Tree root,
                         int S,
                         int *path, int pathLen,
                         int curSum,
                         int *countPaths)
{
    if (!root) return;
    path[pathLen] = root->value;
    curSum += root->value;
    pathLen++;
    if (root->left == NULL && root->right == NULL) {
        if (curSum == S) {
            (*countPaths)++;
            printf("Путь %d: ", *countPaths);
            for (int i=0; i< pathLen; ++i) {
                printf("%d ", path[i]);
            }
            printf("\n");}
        return;}
    find_paths_with_sum(root->left,  S, path, pathLen, curSum, countPaths);
    find_paths_with_sum(root->right, S, path, pathLen, curSum, countPaths);
}
int main(void) {
    printf("Задача 4: пути с заданной суммой S\n");
    printf("значения узлов (0 - конец ввода):\n");
    Tree root = read_tree();
    int S;
    printf("Введите сумму S:");
    if (scanf("%d", &S) !=1) {
        printf("Ошибка\n");
        tree_free(root);
        return 1;
    }
    int h = tree_height(root); 
    int *path = (int*)malloc(h * sizeof(int));
    if (!path) {
        printf("Ошибка\n");
        tree_free(root);
        return 1;
    }
    int countPaths = 0;
    find_paths_with_sum(root,S, path, 0, 0, &countPaths);
    printf("всего путей с суммой %d: %d\n",S, countPaths);
    free(path);
    tree_free(root);
    return 0;}
