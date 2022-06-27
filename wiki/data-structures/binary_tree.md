### Structure of Binary Tree
Binary Tree is a tree structure with only two children (branches).
```C++
/**
       Head 
       /  \
    left  right
**/

class Node{
private: 
    Node(int data_)

   ~Node{ // destructor
       delete this;
    } 

public: 
   int data_;
   Node* left_node_;
   Node* right_node_;
}
```

### Traversal
![BinaryTreeTraversal](/wiki/media/binary_tree_transverse.png)
```C++
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
```
1. Level Order traversal (root -> left -> right)
```C++
/** 
 * [BFS][Top - Down][Left-Right]
 * 1. Create queue, add root to queue
 * 2. while queue is not empty
 *    1. remove front element in queue
 *    2. explore its child, add them to queue
 *                1
 *              /   \
 *             2     3
 *            / \   / \
 *           4   N N   5
 * 
 * Outout: [1, 2, 3, 4, N, N, 5]
*/
void LevelOrderTraversal(Node* root){
   if (!root) {
      return;
   }
   std::queue<Node*> list;
   list.push(root);
   while (!list.empty()){
      Node* current = list.front();
      list.pop();

      if(current->left_node_){
         // Do something on left node
         std::cout << " L: " << current->left_node_->data;
         list.push(current->left_node_);
      }
      if(current->right_node_){
         // Do something on right node
         std::cout << " R: " << current->right_node_->data;
         list.push(current->right_node_);
      }
   }
}
```
2. In-order Traversal (left -> root -> right)
```C++
/** 
 *                1
 *              /   \
 *             2     3
 *            / \   / \
 *           4   5 6   7
 * 
 * Outout: [4, 2, 5, 1, 6, 3, 7]
*/
void InOrderTraversal(Node* root){
   if (!root) {
      return;
   }
   std::stack<Node*> list;
   Node* current = root;
   while (!list.empty() || current){
      // Travel to left most node
      while(current) {
          list.push(current);
          current = current->left_node_;
      }

      Node* current = list.front();
      list.pop();

      // ------------------------- 
      //  DO SOMETHING ON CURRENT
      // ------------------------- 

      // explore right branch
      current = current->right_node_;
   }
}
```

3. Pre-Order Traversal (root -> left -> right)
```C++
/** 
 * [DFS][Top - Down][Left-Right]
 *                1
 *              /   \
 *             2     3
 *            / \   / \
 *           4   5 6   7
 * 
 * Output: [1, 2, 4, 5, 3, 6, 7]
*/
void PreOrderTraversal(Node* root){
   if (!root) {
      return;
   }
   std::stack<Node*> list;
   Node* current = root;
   while (!list.empty()){
      Node* current = list.front();
      list.pop();

      // ------------------------- 
      //  DO SOMETHING ON CURRENT
      // ------------------------- 
      
      // Add right to stack, explore left first
      if (current->right_node_) list.push(current->right_node_);
      if (current->left_node_) list.push(current->left_node_);
   }
}
```

4. Post-Order Traversal
```C++
// LeftNode -> RightNode -> Root
std::vector<TreeNode*> postorderTraversal(TreeNode* root) {
    vector<TreeNode*> postOrder;
    if (root == NULL)
        return postOrder;
    stack<TreeNode*> stack;
    stack.push(root);
    while(!stack.empty()) {
        TreeNode* curr = stack.top();
        stack.pop();
        postOrder.insert(postOrder.begin(), curr);
        if (curr->left != NULL)
            stack.push(curr->left);
        if (curr->right != NULL)
            stack.push(curr->right);
    }
    return postOrder;
}
```
### References:
1. [LeetCode](https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/992/)




