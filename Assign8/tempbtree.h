#ifndef H_BTREE
#define H_BTREE

#include "node.h"

template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};


//constructor
template <class T>
BinaryTree <T>::BinaryTree()
{
   root = 0;
}



//PUBLIC FUNCTIONS

//public getSize
//returns the size of tree
template <class T>
unsigned BinaryTree <T>::getSize() const
{
   return _getSize(root);
}



//public getHeight
//returns height of the tree
template <class T>
unsigned BinaryTree <T>::getHeight() const
{
   return _getHeight(root);
}



//public Insert
//Inserts node into the tree calling the private Insert function
template <class T>
void BinaryTree <T>::Insert(const T& val)
{
   _Insert(root, val);
}



//public Inorder
//performs inorder traversal of tree by calling the private Inorder function
template <class T>
void BinaryTree <T>::Inorder(void (*print) (const T&))
{
   _Inorder(root, print);
}



//PRIVATE FUNCTIONS

//private getSize
//returns the current size of the tree
template <class T>
unsigned BinaryTree <T>::_getSize(Node<T>* node) const
{
   if (node == NULL)//empty
      return 0;
   else
      return(_getSize(node->left) + 1 + _getSize(node->right));//adding both node sides to get size of tree
}



//private getHeight
//returns current height of the tree
template <class T>
unsigned BinaryTree <T>::_getHeight(Node<T>* node) const
{
   if(node == 0 )//empty
   {
      return 0;
   }
   else
   {
      //collecting heights of boths sides of tree
      unsigned leftSide = _getHeight(node->left);
      unsigned rightSide = _getHeight(node->right);

      if(leftSide > rightSide)
      {
          return 1 + leftSide;
      }
      else
      {
          return 1 + rightSide;
      }
   }
}



//private Insert
//Inserting nodes into tree
template <class T>
void BinaryTree <T>::_Insert(Node<T>*& node, const T& val)
{
   //create new node if one doesn't exist
   if(node == 0)
   {
      Node<T>* newNode;
      newNode = new Node<T> (val);
      node = newNode;
   }
   else
   {
      unsigned leftSide = _getHeight(node->left);
      unsigned rightSide = _getHeight(node->right);

      //inserting node in position based on the positional heights
      if(leftSide <= rightSide)
      {
          _Insert(node->left, val);
      }
      else
      {
          _Insert(node->right, val);
      }
   }
}



//private Inorder
//placing nodes in inorder traversal order
template <class T>
void BinaryTree <T>::_Inorder(Node<T>* node, void (*print) (const T&))
{
   if(node != NULL)
   {
      _Inorder(node->left, print);
      print(node->data);
      _Inorder(node->right, print);
   }
}

#endif // End of H_BTREE
