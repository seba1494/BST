#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
// Wcislo Sebastian gr.2I1
// Projekt 3 PROI
// System klas do obslugi drzew BST
// Definicje Klas

using namespace std;


  template<typename Typ>
  class  BSTNode
  {
    public:
      BSTNode<Typ> * p, * left, * right;
      Typ key;
    
  };
// Definicja klasy obsługującej drzewo BST

  template<class Typ>
  class BST
  {
    public:
      BSTNode<Typ> * root;  // korzeń drzewa
      int count;       // liczba węzłów
  
    
    
    BSTNode<Typ> * maxNode(BSTNode<Typ> * x);
    BSTNode<Typ> * minNode(BSTNode<Typ> * x);
    BSTNode<Typ> * pred(BSTNode<Typ> * x);
    BSTNode<Typ> * succ(BSTNode<Typ> * x);
    BSTNode<Typ> * remove(BSTNode<Typ> * x);
    BSTNode<Typ> * search(Typ key);
    
    Typ       maxKey(BSTNode<Typ> * x);
    Typ       minKey(BSTNode<Typ> * x);
    
    bool      insert(BSTNode<Typ> * n);
    void      preorder(BSTNode<Typ> * x);
    void      inorder(BSTNode<Typ> * x);
    void      postorder(BSTNode<Typ> * x);
    void      walk(BSTNode<Typ> * x);
    void      coutBSTcount();
  
    
  };


#include "Bst.hpp"


#endif // BST_H_INCLUDED