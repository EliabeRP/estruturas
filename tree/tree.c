#include <stdio.h>

typedef struct
{
  Tree* left;
  int data;
  Tree* right;
} Tree;

Tree* insert(int data, Tree* root) {
  if (root == NULL) {
    return create_node(data);
  }

  if (data < root->data) return insert(data, root->left);
  if (data > root->data) return insert(data, root->right);
  return root;
}

Tree* create_node(int data) {
  Tree * new_node = (Tree*) malloc(sizeof(Tree));

  new_node-> data = data;
  new_node->left = NULL;
  new_node-> right = NULL;

  return new_node;
}

void pre_ordem(Tree* root) {
  if (root != NULL) {
    printf("%d", root->data);
    pre_ordem(root->left);
    pre_ordem(root->right);
  }

}

void in_ordem(Tree* root) {
  if (root != NULL) {
    in_ordem(root->left);
    printf("%d", root->data);
    in_ordem(root->right);
  }

}

void pos_ordem(Tree* root) {
  if (root != NULL) {
    pos_ordem(root->left);
    pos_ordem(root->right);
    printf("%d", root->data);
  }
}

int size_tree(Tree* root) {
  if (root == NULL) return -1;

  int size_left = size_tree(root->left);
  int size_right = size_tree(root->right);

  return (size_left > size_right ? size_left : size_right) + 1;
}