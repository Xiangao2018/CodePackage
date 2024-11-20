#include <iostream>

using namespace std;


struct Node
{
    Node(int value): value(value), left(nullptr), right(nullptr) {}
    int value;
    Node *left;
    Node *right;
};


// 删除的节点：
// 1. 该节点是叶子节点 ===> 直接 parent 删除即可
// 2. 该节点有一个子节点(左节点或右节点) ===> 直接加该节点挂在 Parent 节点下
// 3. 该节点有两个节点（左节点和右节点） ==> 找左节点最大的 或者 右节点最小的
void deleteNode(Node *root, int data)
{
    // 先找到这个节点以及父节点
    Node *node = root;
    while( node != nullptr)
    {         
         if ( node->value < data ) {
            node = node->right;            
        }  else  {
            node = node->left;
        }
    }

    // 找 Node 节点
    if( node == nullptr ) return;

    if( node->left != nullptr && node->right != nullptr ) // 两个节点
    {
        // 找左边最大的
        Node *leftMaxNode = node->left;
        Node *pLeftMaxNode = node;
        while ( leftMaxNode->right != nullptr)
        {
            leftMaxNode = leftMaxNode->right;
            pLeftMaxNode = leftMaxNode;
        }

        // 现在要将左边最大的跟 Node 替换
        // 1. 先将 leftMaxNode 从  pLeftMaxNode 移除
        if( pLeftMaxNode->left == leftMaxNode ) {
            pLeftMaxNode->left = nullptr;
        } else if( pLeftMaxNode->right == leftMaxNode ) {
            pLeftMaxNode->right = nullptr;
        }   

    } 
    else if( node->left != nullptr ) //  只有一个左节点
    {
        if( )
    }




}


int main(int argc, char const *argv[])
{
    
    return 0;
}
