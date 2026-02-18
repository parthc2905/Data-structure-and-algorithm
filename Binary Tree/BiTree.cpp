#include<iostream>
#include "biTreecpp.h"
using namespace std;

class Tree{
    public:
        Node *root;
        Tree(){root=NULL;}
        void CreateTree();
        void Preorder(Node *p);
        void Postorder(Node *p);
        void Inorder(Node *p);
        void Levelorder(Node *p);
        void Height(Node *root);

};

int main(){
    
    return 0;
}