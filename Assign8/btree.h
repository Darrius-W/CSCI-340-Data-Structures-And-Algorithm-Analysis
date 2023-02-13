#ifndef H_BTREE
#define H_BTREE

#include "node.h"

template <typename T> class BinaryTree{

typedef enum { left_side, right_side } SIDE;
    SIDE rnd ( ) { return rand ( ) % 2 ? right_side : left_side; }


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

/*
*Private version*
height() const
arguments: a pointer to a Node of class T, called ptr (holds the root)
returns: the height of the tree
purpose: finds the height of the tree,
    if there are no Nodes, returns a height of 0
*/
template <class T>
unsigned BinaryTree <T>::_getHeight( Node<T>* ptr) const {
    if(ptr == NULL) //if null, height = 0
        return -1;

    return 1 + max(_getHeight(ptr->left), _getHeight(ptr->right)); //finds tree height
}

/*
*Private version*
insert()
returns: nothing
arguments: A pointer to a reference Node of class T, called ptr (holds the root)
    A constant reference to a class T, called element (element to be inserted)
purpose: Adds an item to the tree,
    If there is no Node, creates a new one, sets necessary pointers to NULL and sets Node data to the element.
    Decides where to make the new Node based on rnd() method call
*/
template <class T>
void BinaryTree <T>::_Insert( Node<T>*& ptr, const T& element) {
   /*if(ptr == NULL){
      Node<T>* newnode;
      newnode = new Node<T> (element);
      ptr = newnode;
   }
   else if(element < ptr->data)
      _Insert(ptr->left, element);
   else
      _Insert(ptr->right, element);*/

    if(ptr == NULL) {
        ptr = new Node<T>();
        ptr->right = NULL;
        ptr->left = NULL;
        ptr->data = element;
    }
    else if( rnd() == right_side ) //if rnd == right_side, make new node on right
        _Insert(ptr->right, element);
    else //else left
        _Insert(ptr->left, element);

}


/*
*Private version*
inorder()
returns: nothing
arguments: a pointer to a Node of class T, called ptr (holds root).
    A pointer function that takes a class T argument
Purpose: Goes through the tree using in order method, using recursion
*/
template <class T>
void BinaryTree <T>::_Inorder( Node<T>* ptr, void (*func) (const T& ) ) {
    if(ptr != NULL) {
        _Inorder(ptr->left,func );
        func( ptr->data );
        _Inorder(ptr->right, func);
    }
}

#endif

