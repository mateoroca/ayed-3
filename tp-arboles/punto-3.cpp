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

void preOrderTraversal(TreeNode *root)
{
  if (root)
  {
    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
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

void postOrderTraversal(TreeNode *root)
{
  if (root)
  {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
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

  std::cout << "Arbol binario de busqueda construido en orden (in-order traversal): ";
  inOrderTraversal(root);
  std::cout << std::endl;

  std::cout << "Recorrido en preorden del arbol: ";
  preOrderTraversal(root);
  std::cout << std::endl;

  std::cout << "Recorrido en inorden del arbol: ";
  inOrderTraversal(root);
  std::cout << std::endl;

  std::cout << "Recorrido en postorden del arbol: ";
  postOrderTraversal(root);
  std::cout << std::endl;

  return 0;
}
