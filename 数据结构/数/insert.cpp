#include <iostream>
#include <string>
#include <queue>

using namespace std;

// 二叉树的插入基本都是放在叶子节点上

struct Node
{
    Node(int value): value(value), left(nullptr), right(nullptr) {}
    int value;
    Node *left;
    Node *right;
};

void preOrderPrint(Node *node)
{
    if( node == NULL )
        return;

    std::cout << node->value << " ";

    preOrderPrint(node->left);
    preOrderPrint(node->right);
}


void insertIgnoreSame1(Node *node, Node *insert)
{
    if( node->value == insert->value )
        return; // Tree already has the value 
    else if( node->value < insert->value ) // 当前 Node 小于 insert， 需要放在右边
    {
        if( node->right ==nullptr )
            node->right = insert;
        else 
            insertIgnoreSame1(node->right, insert);

        return;
    }
    else 
    {
        if( node->left ==nullptr )
            node->left = insert;
        else 
            insertIgnoreSame1(node->left, insert);

        return;
    }
}

void insertIgnoreSame2(Node *node, Node *insert)
{
    Node *current = node;
    while( current != nullptr )
    {
        if( current->value < insert->value )
        {
            if( current->right == nullptr )            
            {
                current->right = insert;
                return;
            }
            
            current = current->right;
        }
        else if ( current->value > insert->value )
        {
            if( current->left == nullptr )            
            {
                current->left = insert;
                return;
            }
            
            current = current->left;
        } 
        else // equal, ignore
        {
           
        }
    }
}


int main(int argc, char const *argv[])
{
    Node n33(33);
    Node n17(17);
    Node n50(50);
    Node n13(13);
    Node n18(18);
    Node n34(34);
    Node n58(58);
    Node n16(16);
    Node n25(25);
    Node n51(51);
    Node n66(66);
    Node n19(19);
    Node n27(27);

    n33.left = &n17;
    n33.right = &n50;

    n17.left = &n13;
    n17.right = &n18;

    n50.left = &n34;
    n50.right = &n58;

    n13.right = &n16;

    n18.right = &n25;

    n58.left = &n51;
    n58.right = &n66;

    n25.left = &n19;
    n25.right = &n27;

    // preOrderPrint(&n33);

    // Node *result =  search(&n33, 19);
    // if( result != nullptr )
    // {
    //     std::cout << (*(result)).value << std::endl;
    // }

    return 0;
}
