#ifndef H_BINARYSEARCHTREE
#define H_BINARYSEARCHTREE

#include "btree.h"
#include "bst.h"
#include "node.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};


//Public
//Insert function
template <class T>
void BinarySearchTree <T>::Insert(const T& x)
{
   _Insert(this->root, x);
}

//Private
//Insert function
template <class T>
void BinarySearchTree <T>::_Insert(Node<T>*& node, const T& x)
{   
   if(node == NULL)//if empty
   {
      Node<T>* newnode;
      newnode = new Node<T> (x);
      node = newnode;
   }

   else if(x < node->data)
      _Insert(node->left, x);

   else
      _Insert(node->right, x);
}

//Public
//Search Function
template <class T>
bool BinarySearchTree <T>::Search(const T& x) const
{
   if(_Search(this->root, x))//check if for leaf
      return true;
   else
      return false;
}

//Private
//Search Function
template <class T>
bool BinarySearchTree <T>::_Search(Node<T>*node, const T&x) const
{
   if(node == NULL || node->data == x)//leaf found
      return true;
   else
      return false;
}

//Public
//Remove function
template <class T>
bool BinarySearchTree <T>::Remove(const T& x)
{
   Node<T>* node = this->root;
    
   while(_Search(node, x)) {//searching for leaf
      if(x <= node->data)//search left 
         node = node->left;

      else if(x > node->data)//search right
         node = node->right;

      else if(x == node->data)
         break;
    }
    
    if(_Search(node, x))
        return true;
    else 
        return false;
}

//Private
//Remove function
template <class T>
void BinarySearchTree <T>::_Remove(Node<T>*&node, const T&x)
{
    if(node == NULL)//empty
        return;

    if(x < node->data)
        _Remove(node->left, x);
 
    else if(x > node->data)
        _Remove(node->right, x);
 
    else{
        if (node->left == NULL && node->right == NULL)//singular child or none
            free(node);

        else if(node->left == NULL)
            free(node);

        else if(node->right == NULL)
            free(node);


        Node<T>* temp = node->right;
        
        while(temp && temp->left != NULL)
            temp = temp->left; 
 
        node->data = temp->data;
 
        free(temp);
    }
}

//Private
//Leaf function
template <class T>
bool BinarySearchTree <T>::_Leaf(Node<T> *node) const
{
    if(node == 0)
       return true;
    
    if(node->left != NULL)
       return false;
    if(node->right != NULL)
       return false;

    return _Leaf(node->left) && _Leaf(node->right);   
}


#endif
