#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;    
    Node(int item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node*root){
    if(root==nullptr)
    return ;
    else{
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
void pre(Node*root){
    if(root==nullptr)
    return ;
    else{
        pre(root->left);
        pre(root->right);
        cout<<root->key<<" ";
    }
}
void post(Node*root){
    if(root==nullptr)
    return ;
    else{
        cout<<root->key<<" ";
        post(root->left);
        post(root->right);
    }
}
Node* insert(int d,Node*root){
    if(root==NULL){
        return new Node(d);
    }
    else if(root->key==d)
    return root;
    else if(root->key>d){
       root->right= insert(d,root->right);
    }
    else if(root->key<d){
       root->left= insert(d,root->left);
    }
    return root;
}
vector<vector<int>> levelOrder(Node* root) {
        // Create a 2D vector to store levels
        vector<vector<int>> ans; 
        if (root == nullptr) {
            // If the tree is empty,
            // return an empty vector
            return ans; 
        }
        
        // Create a queue to store nodes
        // for level-order traversal
        queue<Node*> q; 
        // Push the root node to the queue
        q.push(root); 

        while (!q.empty()) {
            // Get the size of the current level
            int size = q.size(); 
            // Create a vector to store
            // nodes at the current level
            vector<int> level; 

            for (int i = 0; i < size; i++) {
                // Get the front node in the queue
                Node* node = q.front(); 
                // Remove the front node from the queue
                q.pop(); 
                // Store the node keyue
                // in the current level vector
                level.push_back(node->key); 

                // Enqueue the child nodes if they exist
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            // Store the current level
            // in the answer vector
            ans.push_back(level); 
        }
        // Return the level-order
        // traversal of the tree
        return ans; 
    }

// Function to print
// the elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the
    // vector and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}
// Driver program to test the above functions
int main() {
    // Creating the following BST
    //      50
    //     /  \
    //    30   70
    //   / \   / \
    //  20 40 60 80

    Node* root = new Node(50);
    root = insert(30,root);
    root = insert(20,root);
    root = insert(40,root);
    root = insert(70,root);
    root = insert(60,root);
    root = insert(80,root);
    vector<vector<int>> ans=levelOrder(root);
for (const vector<int>& level : ans) {
        printVector(level);
    }    // Print inorder traversal of the BST
    // inorder(root);

    return 0;
}
