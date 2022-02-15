/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {        
        if (!root){
            return root;
        }
        queue<Node*> tree;
        tree.push(root);
        do{
            queue<Node*> t0;
            Node *first{nullptr};
            while (!tree.empty()){                
                auto node = tree.front();
                if (!first){
                    first = node;
                }else{
                    first->next = node;
                    first = node;
                }                
                if (node->left){
                    t0.push(node->left);
                }
                if (node->right){
                    t0.push(node->right);
                }
                tree.pop();
            }
            if (t0.empty()){
                break;
            }
            tree = std::move(t0);
        }while(true);
        return root;
    }
};
// O(1) memory, do not use queue
class Solution2 {
public:
    void search(Node* node){        
        if (!node->left){
            return;
        }
        node->left->next = node->right;
        if (node->next){
            node->right->next = node->next->left;
        }
        search(node->left);
        search(node->right);
    }
    Node* connect(Node* root) {        
        if (!root){
            return root;
        }
        search(root);
        return root;
    }
};