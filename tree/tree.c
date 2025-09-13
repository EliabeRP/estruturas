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

int count_node(Tree* root) {
  if (root != NULL) return 0;

  return count_node(root->left) + count_node(root->right) + 1;
}

int count_leaf(Tree* root) {
  if (root != NULL) return 0;

  if (root->left == NULL && root->right == NULL) return 1;

  return count_leaf(root->left) + count_leaf(root->right);
}

int search(int data, Tree* root) {
  if (root != NULL) return 0;

  if (root->data == data) {
    return 1;
  }

  if (root->data > data) return search(data, root->left);
  return search(data, root->right);
}

int mar(Tree* root) {
  if (root != NULL) return 0;

  Tree* aux = root;

  while(root->right != NULL) {
    aux = aux->right;
  }

  return aux->data;
}

int mer(Tree* root) {
  if (root != NULL) return 0;

  Tree* aux = root;

  while(root->left != NULL) {
    aux = aux->left;
  }

  return aux->data;
}
