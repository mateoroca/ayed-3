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

TreeNode *findMin(TreeNode *node)
{
  while (node->left != nullptr)
  {
    node = node->left;
  }
  return node;
}

TreeNode *deleteNode(TreeNode *root, char val)
{
  if (root == nullptr)
  {
    return root;
  }

  if (val < root->data)
  {
    root->left = deleteNode(root->left, val);
  }
  else if (val > root->data)
  {
    root->right = deleteNode(root->right, val);
  }
  else
  {
    if (root->left == nullptr)
    {
      TreeNode *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == nullptr)
    {
      TreeNode *temp = root->left;
      delete root;
      return temp;
    }

    TreeNode *temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
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

  std::cout << "Arbol binario de busqueda construido en orden (in-order traversal): ";
  inOrderTraversal(root);
  std::cout << std::endl;

  root = deleteNode(root, 'E');
  std::cout << "Arbol despues de extraer 'E': ";
  inOrderTraversal(root);
  std::cout << std::endl;

  root = deleteNode(root, 'C');
  std::cout << "Arbol despues de extraer 'C': ";
  inOrderTraversal(root);
  std::cout << std::endl;

  root = deleteNode(root, 'G');
  std::cout << "Arbol despues de extraer 'G': ";
  inOrderTraversal(root);
  std::cout << std::endl;

  return 0;
}
