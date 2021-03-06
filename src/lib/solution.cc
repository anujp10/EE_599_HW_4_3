#include "solution.h"
#include <iostream>

void BST::push(int key)
{
  root_ = pushNode(BST::root_, key);
}

bool BST::find(int key)
{
  TreeNode *temp = findNode(root_, key);
  if (temp == nullptr)
    return false;
  else
    return true;
}

bool BST::erase(int key)
{
  if (find(key))
  {
    TreeNode *temp = eraseNode(root_, key);
    if (temp == nullptr)
      return false;
    else
      return true;
  }
  else
    return false;
}

TreeNode *BST::pushNode(TreeNode *node, int key)
{
  if (node == nullptr)
  {
    return (new TreeNode(key));
  }
  else if (key < node->val)
  {
    node->left = pushNode(node->left, key);
  }
  else if (key > node->val)
  {
    node->right = pushNode(node->right, key);
  }
  return node;
}

TreeNode *BST::findNode(TreeNode *node, int key)
{
  if (node == nullptr || node->val == key)
    return node;

  if (key < node->val)
    return findNode(node->left, key);
  else
    return findNode(node->right, key);
}

TreeNode *BST::eraseNode(TreeNode *node, int key)
{
  if (node == nullptr)
    return node;

  if (key < node->val)
    node->left = eraseNode(node->left, key);
  else if (key > node->val)
    node->right = eraseNode(node->right, key);
  else
  {
    if (node->left == nullptr)
    {
      TreeNode *temp = node->right;
      free(node);
      return temp;
    }
    else if (node->right == nullptr)
    {
      TreeNode *temp = node->left;
      free(node);
      return temp;
    }

    TreeNode *temp = minNode(node->right);
    node->val = temp->val;
    node->right = eraseNode(node->right, temp->val);
  }
  return node;
}

TreeNode *BST::minNode(TreeNode *node)
{
  TreeNode *temp = node;

  while (temp != nullptr && temp->left != nullptr)
  {
    temp = temp->left;
  }

  return temp;
}

void BST::Inorder()
{
  InorderBST(root_);
}

void BST::InorderBST(TreeNode *node)
{
  if (node == nullptr)
  {
    return;
  }
  InorderBST(node->left);
  std::cout << "data = " << node->val << std::endl;
  InorderBST(node->right);
}