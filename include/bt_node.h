/**
 * @file BTNode.h
 * @author Sapan Agrawal (ssagrawal@wpi.edu)
 * @brief
 * @version 0.1
 * @date 2022-03-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <iostream>
#include <queue>
#include <stack>

enum Node {
  BASE=0,
  LEFT,
  RIGHT
};

template <typename T> class BTNode {
public:
  BTNode() {}
  BTNode(T data) : data_(data) {}
  T data_;
  BTNode<T> *left_node_;
  BTNode<T> *right_node_;
};

namespace util {

/**
 * @brief Takes input from the user and makes the tree online. Assumes all
 * elements are whole numbers. Terminates node when received -1.
 *
 * @tparam T
 * @return BTNode<T>
 */
BTNode<int> *MakeTreeLevelwise() {
  BTNode<int> *root = new BTNode<int>(0);
  std::cout << "Enter elements of Binary Tree in level order\n";
  std::cout << "To end tree node use -1 \n";
  std::cin >> root->data_;

  if (root->data_ == -1) {
    delete root;
    return nullptr;
  }

  std::queue<BTNode<int> *> list;
  list.push(root);

  while (!list.empty()) {
    BTNode<int> *current_node = list.front();
    list.pop();

    int new_elem;
    std::cout << "Enter next element\n";
    std::cin >> new_elem;
    if (new_elem == -1) {
      current_node->left_node_ = nullptr;
    } else {
      current_node->left_node_ = new BTNode<int>(0);
      current_node->left_node_->data_ = new_elem;
      list.push(current_node->left_node_);
    }

    std::cout << "Enter next element\n";
    std::cin >> new_elem;
    if (new_elem == -1) {
      current_node->right_node_ = nullptr;
    } else {
      current_node->right_node_ = new BTNode<int>(0);
      current_node->right_node_->data_ = new_elem;
      list.push(current_node->right_node_);
    }
  }
  return root;
}

/**
 * @brief Takes input from the user and makes the tree online. Assumes all
 * elements are whole numbers. Terminates node when received -1.
 *
 *  * Traversals in Binary Tree
 *                1
 *              /   \
 *             2     3
 *            / \   / \
 *           4   N N   5
 * 
 * 1. Levelwise Travsersal [1, 2, 3, 4, N, N, 5]
 * @tparam T
 * @return BTNode<T>
 */
template<size_t size>
BTNode<int> *MakeTreeFromArray(int (&array)[size]) {
  std::queue<BTNode<int>*> list;
  int idx = 0;
  BTNode<int>* root = new BTNode<int>(array[idx]);
  list.push(root);
  while (!list.empty()){
    BTNode<int>* current = list.front();
    list.pop();

    if (array[++idx] != -1 && idx < size){
      current->left_node_ = new BTNode<int> (array[idx]);
      list.push(current->left_node_);
    } else {
      current->left_node_ = NULL;
    }
    if (array[++idx] != -1 && idx < size){
      current->right_node_ = new BTNode<int> (array[idx]);
      list.push(current->right_node_);
    } else {
      current->right_node_ = NULL;
    }
  }
  return root;
}

template <typename T> void PrintTreeLevelwise(BTNode<T> *root) {
  if (!root) {
    std::cout << "Null\n";
    return;
  }
  std::cout << "Root: " << root->data_ << std::endl;
  std::queue<BTNode<int> *> list;
  list.push(root);

  while (!list.empty()) {
    BTNode<int> *current_node = list.front();
    list.pop();

    if (current_node->left_node_) {
      std::cout << "L: " << current_node->left_node_->data_;
      list.push(current_node->left_node_);
    } else {
        std::cout << "L: Null";
    }

    if (current_node->right_node_) {
      std::cout << " R: " << current_node->right_node_->data_ << std::endl;
      list.push(current_node->right_node_);
    } else {
        std::cout << " R: Null\n";
    }
  }
}

/**
 * Traversals in Binary Tree
 *                1
 *              /   \
 *             2     3
 *            / \   / \
 *           4   N N   5
 * 
 * 1. Levelwise Travsersal [1, 2, 3, 4, N, N, 5]
 * 2. In-order Travsersal (Left, Root, Right)[4, 2, N, 1, N, 3, 5]
 * 3. Pre-order Travsersal (Root, Left, Right)[1, 2, 4, N, 3, N, 5]
 * 4. Post-order Travsersal (Left, Right, Root)[4, N, 2, N, 5, 3, 1]
 */

/**
 * @brief Traverses the tree in level order. The method stores the nodes in the same level in a vector. This vector is then operated by the input function as required. 
 * 
 * @tparam T template data_type for the binary tree
 * @tparam ret template return type for the function operating on the level order vector list
 * @param root root node of the binary tree
 * @param function Function that performs some operation on the level order of the tree. 
 */
template <typename T, typename ret> void LevelOrderTraversal(BTNode<T>* root, ret result, void(*function)(const std::vector<BTNode<T>*>&)){
  // If root is nullptr, return empty 
  if (!root) {
    return;
  }

  // Store the nodes in the tree in a queue as they are explored
  std::queue<BTNode<T> *> list;
  list.push(root);
  list.push(NULL);
  
  // Store the nodes' data_ at same level in a list
  std::vector<BTNode<T>*> level_list;
  
  // Run the function for the root
  level_list.push_back(root);
  function(level_list);
  level_list.clear();

  while (!list.empty()) {
    BTNode<T> *current_node = list.front();
    list.pop();

    // If reached end of parent node level order 
    if(current_node == NULL){

      // Add NULL to the queue to mark end of current level as we have visited the right most node of the current level in previos iteration.
      if (!list.empty()){
        // pass the level list into operator function
        function(level_list);

        // clear the list for storing nodes in subsequent level
        level_list.clear();
        list.push(NULL);
        continue;
      } else {
        return;
      }
    }

    // We are exploraing the children of the nodes in the parent level.
    if (current_node->left_node_) {
      list.push(current_node->left_node_);
      level_list.push_back(current_node->left_node_);
    } else {
      level_list.push_back(NULL);
    }

    if (current_node->right_node_) {
      list.push(current_node->right_node_);
      level_list.push_back(current_node->right_node_);
    } else {
      level_list.push_back(NULL);
    }
  }
}

/**
 * @brief Inorder Traversal
 * 
 * @tparam T 
 * @tparam ret 
 * @param root 
 * @param function 
 */
template <typename T> void InOrderTraversal(BTNode<T>* root, void(*function)(const std::vector<BTNode<T>*>&)){
  // If root is nullptr, return empty 
  if (!root) {
    return;
  }

  // Store the nodes in the tree in a queue as they are explored
  std::stack<BTNode<T>*> list;
  list.push(root);
  BTNode<T>* current = root;

  // result vector
  std::vector<BTNode<T>*> inorder_list;

  while (!list.empty()) {
    // travel to left most node in the current sub-tree
    while (!current){
      current = current->left_node_;
      list.push(current);
    }
    
    // add current to the result
    current = list.top();
    list.pop();
    inorder_list.push_back(current);

    // explore right sub-tree if it exists
    current = current->right_node_;
  }
  function(inorder_list);
}
 
}; // namespace util
