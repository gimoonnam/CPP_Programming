//
//  Q1_class.cpp
//  SocieteGenerale
//
//  Created by Gi-Moon Nam on 25/03/2019.
//  Copyright © 2019 Gi-Moon Nam. All rights reserved.
//

#include <iostream>

using namespace std;


class Node{
public:
    int value;
    Node *left;
    Node *right;
    Node* find(Node*, int v);
    Node* findMinNode(Node*);
    Node* Insert(Node*, int);
    Node* Delete(Node*,int);
    void node_print(Node* root);
};

Node* Node::Insert(Node* root, int value){
    if (root == NULL){    /// difference between NULL and nullptr???
        root = new Node();
        root -> value = value;
        (*root).left = (*root).right = NULL;
    }
    
    else{
        if(value <= root->value){
            root->left  =  Insert(root->left, value);
        }
        else
            root->right  =  Insert(root->right, value);
    }
    return root;
}

Node* Node::findMinNode(Node* root){
    Node* tmp = root;
    
    while(tmp->left != NULL){
        tmp = tmp->left;
    }
    return tmp;
}


Node* Node::Delete(Node* root, int value){
    Node* tnode = NULL;
    
    if(root == NULL) return NULL;
    
    if(value < root -> value) root->left = Delete(root->left, value);  // 지울 노드값을 찾는 과정.
    else if(value > root -> value) root->right = Delete(root->right, value); // 지울 노드값을 찾는 과정
    else{// root->value == value
        if (root -> left != NULL && root->right != NULL){
            tnode = findMinNode(root->right);
            root -> value = tnode->value;
            root -> right = Delete(root->right, tnode->value);
        }
        else {
            tnode = (root->left==NULL)? root->right : root ->left;
            delete root;
            return tnode;
        }
    }
    
    return root;
}


void Node::node_print(Node* root){
    if(root == NULL)
        return;
    cout <<  root->value << endl;
    node_print(root->left);
    node_print(root->right);
}

Node* Node::find(Node* root, int value){
    if(root == NULL) return root;
    else if(root->value == value) return root;
    else if(value <= root -> value) return find(root -> left, value);
    else if(value > root -> value) return find(root->right, value);
    else return NULL;
}


int main(){
    Node* node=NULL;
    int list[] = {9, 7, 13, 12, 5, 8, 17, 2 , 6, 16};
    int nnode = sizeof(list)/sizeof(list[0]);
    
    //cout << nnode << endl;
    
    for (int i = 0 ; i < nnode ; i ++){
        node = node->Insert(node, list[i]);
    }

    //cout << (node -> find(node, 16)) -> value << endl;
    
    node -> node_print(node);
    node = node->Delete(node, 9);
    
    cout << "\n" << endl;
    node -> node_print(node);
    
    
    
    return 0;
}




