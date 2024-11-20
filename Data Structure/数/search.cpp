#include <iostream>
#include <string>
#include <queue>

using namespace std;

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

Node *search(Node *from, int value)
{
    std::cout << "current value is " << from->value << std::endl;
    if( from->value == value)
    {
        std::cout <<"Equal, return" << std::endl;
        return( from );
    }

    if( from->value < value )
    {
        std::cout << "right " <<  std::endl;
        return( search(from->right, value ));
    }

    std::cout << "left " <<  std::endl;
    return( search(from->left, value) );
}

Node *search2(Node *root, int value)
{
    Node *current = root;
    while( current != nullptr )
    {
        if( current->value == value ) 
            return current;
        else if( current->value < value) 
            current = current->right;
        else if( current->value > value) 
            current = current->left;
    }

    return( nullptr );
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


    Node *result = search2(&n33, 19);
    if( result != nullptr )
    {
        std::cout << (*(result)).value << std::endl;
    }

    

    return 0;
}
