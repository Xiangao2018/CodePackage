#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node
{
    Node(string name): name(name) {}
    string name;
    Node *left;
    Node *right;
};


void preOrderPrint(Node *node)
{
    if( node == NULL )
        return;

    std::cout << node->name  << " ";

    preOrderPrint(node->left);
    preOrderPrint(node->right);
}

void inOrderPrint(Node *node)
{
    if ( node == NULL)
        return;

    inOrderPrint(node->left);
    std::cout << node->name << " ";
    inOrderPrint(node->right);
}


void postOrderPrint(Node *node)
{
    if ( node == NULL)
        return;

    postOrderPrint(node->left);    
    postOrderPrint(node->right);
    std::cout << node->name << " ";
}

void levelOrderPrint1(Node *node)
{
    if( node == NULL )
        return;

    std::queue<Node *> q;
    q.push(node);

    Node *current = NULL;
    while( !q.empty() )
    {
        current = q.front();
        std::cout << current->name << " ";
        if( current->left != NULL )
            q.push(current->left);
        if( current->right != NULL )
            q.push(current->right);

        q.pop();
    }
}

void levelOrderPrint2(Node *node)
{
    if( node == NULL )
        return;

    std::vector<Node *>v1;
    v1.push_back(node);

    Node *current = NULL;
    while( v1.size() != 0)
    {
        current = v1.front();
        v1.erase(v1.begin());

        std::cout << current->name << " ";
        if( current->left != NULL )
            v1.push_back(current->left);
        if( current->right != NULL )
            v1.push_back(current->right);
    }

    // int start = 0;
    // while( start < v1.size() )
    // {
    //     current = v1[start++];
    //     std::cout << current->name << " "; 
    //     if( current->left != NULL )
    //         v1.push_back(current->left);
    //     if( current->right != NULL )
    //         v1.push_back(current->right);
    // }

    // for( auto iter = v1.begin(); iter != v1.end(); iter++)
    // {
    //     std::cout << (*iter)->name << " ";
    // }
}



int main(int argc, char const *argv[])
{
    Node A("A");
    Node B("B");
    Node C("C");
    Node D("D");
    Node E("E");
    Node F("F");
    Node G("G");

    A.left = &B;
    A.right = &C;
    B.left = &D;
    B.right = &E;
    C.left = &F;
    C.right = &G;


    preOrderPrint(&A);
    std::cout << std::endl;
    inOrderPrint(&A);
    std::cout << std::endl;
    postOrderPrint(&A);
    std::cout << std::endl;
    levelOrderPrint1(&A);
    std::cout << std::endl;
    levelOrderPrint2(&A);




    return 0;
}
