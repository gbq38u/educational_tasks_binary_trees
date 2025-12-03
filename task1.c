#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int value;            
    struct Node *left;    
    struct Node *right;   
} Node;
typedef Node* Tree;
Node* create_node(int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Ошибка\n");
        exit(1);}
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;}
int tree_is_empty(Tree root) {
    return root == NULL; }
Tree tree_insert(Tree root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value < root->value) {
        root->left = tree_insert(root->left, value);
    } else if (value > root->value) {
        root->right = tree_insert(root->right, value);
    } else {
    }
    return root; 
}
void print_preorder(Tree root) {
    if (root == NULL) return;

    printf("%d ", root->value); 
    print_preorder(root->left);   
    print_preorder(root->right);   
}
void print_inorder(Tree root) {
    if (root == NULL) return;

    print_inorder(root->left);
    printf("%d ", root->value);
    print_inorder(root->right);
}
void print_postorder(Tree root) {
    if (root == NULL) return;

    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->value);}
int tree_height(Tree root) {
    if (root == NULL) return 0;
    int hl = tree_height(root->left);
    int hr = tree_height(root->right);
    return (hl > hr ? hl : hr) + 1;}
void tree_free(Tree root) {
    if (root == NULL) return;
    tree_free(root->left);
    tree_free(root->right);
    free(root);}
Node* find_min(Node *root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;}
Tree tree_delete_keep_subtree(Tree root, int value) {
    if (root == NULL) return NULL;

    if (value < root->value) {
        root->left = tree_delete_keep_subtree(root->left, value);
    } else if (value > root->value) {
        root->right = tree_delete_keep_subtree(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        if (root->left == NULL || root->right == NULL) {
            Node *child = (root->left != NULL) ? root->left : root->right;
            free(root);
            return child;}
        Node *minRight = find_min(root->right);
        root->value = minRight->value;         
        root->right = tree_delete_keep_subtree(root->right, minRight->value);
    }
    return root;
}
Tree tree_delete_with_subtree(Tree root, int value) {
    if (root == NULL) return NULL;

    if (value < root->value) {
        root->left = tree_delete_with_subtree(root->left, value);
        return root;
    } else if (value > root->value) {
        root->right = tree_delete_with_subtree(root->right, value);
        return root;
    } else {
        tree_free(root);
        return NULL;
    }
}
int main(void) {
    Tree t = NULL; 
    int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++) {
        t = tree_insert(t, a[i]);
    }
    printf(" пустое? %s\n", tree_is_empty(t) ? "да" : "нет");
    printf("Прямой обход: ");
    print_preorder(t);
    printf("\n");
    printf("Симметричный обход:");
    print_inorder(t);
    printf("\n");
    printf("Обратный обход: ");
    print_postorder(t);
    printf("\n");
    printf("Высота дерева: %d\n", tree_height(t));
    printf("\nУдаляем (без удаления поддерева) узел 3\n");
    t = tree_delete_keep_subtree(t, 3);
    printf("После удаления 3 (inorder):");
    print_inorder(t);
    printf("\n");
    printf("\nУдаляем (с удалением поддерева) узел 10\n");
    t = tree_delete_with_subtree(t, 10);
    printf("После удаления 10 и его поддерева (inorder): ");
    print_inorder(t);
    printf("\n");
    tree_free(t);
    t = NULL;
    printf("\nПосле tree_free  пустое? %s\n",
           tree_is_empty(t) ? "да" : "нет");
    return 0;}
