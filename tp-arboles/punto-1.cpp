#include <iostream>

struct TreeNode
{
  char data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(char val)
  {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

TreeNode *insert(TreeNode *root, char val)
{
  if (root == nullptr)
  {
    return new TreeNode(val);
  }

  if (val < root->data)
  {
    root->left = insert(root->left, val);
  }
  else if (val > root->data)
  {
    root->right = insert(root->right, val);
  }

  return root;
}

void inOrderTraversal(TreeNode *root)
{
  if (root)
  {
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
  }
}

int main()
{
  char elementos[] = {'G', 'B', 'Q', 'A', 'C', 'K', 'F', 'P', 'D', 'E', 'R', 'H'};
  int n = sizeof(elementos) / sizeof(elementos[0]);

  TreeNode *root = nullptr;

  for (int i = 0; i < n; i++)
  {
    root = insert(root, elementos[i]);
  }

  std::cout << "arbol binario de busqueda construido en orden (in-order traversal): ";
  inOrderTraversal(root);
  std::cout << std::endl;

  return 0;
}
