#ifndef BST_HPP_INCLUDED
#define BST_HPP_INCLUDED


// Wcislo Sebastian gr.2I1
// Projekt 3 PROI
// System klas do obslugi drzew BST
// Plik z definicjami funkcji klas szablonowych


#include<cstdlib>
#include<iostream>
#include"Bst.h"
using namespace std;




    template<class Typ>
    bool BST<Typ>::insert(BSTNode<Typ> * n)                                   		// Wstawia element do struktury BST
    {
      BSTNode<Typ> * y, * x = root;

      y = n->left = n->right = NULL;

      while(x)
	{
	  if(n->key == x->key)
	    {
	      delete n;
	      return false;
	    }
	  
	  y = x;
	  x = (n->key < x->key) ? x->left : x->right;
	}

      n->p = y;

      if(!y)
      {
	root = n;
      }
	else
	
	{
	  if(n->key < y->key)
	    y->left  = n;
	  else
	    y->right = n;
	}
	
	count++;
	return true; 
    }


   
   
   template<class Typ>
    BSTNode<Typ> * BST<Typ>::search(Typ key)						// Wyszukuje element wg wartości klucza
    {
      BSTNode<Typ> * x = root;

      while((x) && (x->key != key))
      {
	x = (key < x->key) ? x->left : x->right;
      }
      return x;  
    }



   
   template<class Typ>
    Typ BST<Typ>::minKey(BSTNode<Typ> * x)						// Zwraca masymalną wartość klucza
    {
      while(x->left)
      {
	x = x->left;
      }
      return x->key;  
    }

    
    
    template<class Typ>
    Typ BST<Typ>::maxKey(BSTNode<Typ> * x)						// Zwraca minimalną wartość klucza
    {
      while(x->right) 
      {
	x = x->right;
      }
      
      return x->key;  

    }


   
   template<class Typ>
    BSTNode<Typ> * BST<Typ>::minNode(BSTNode<Typ> * x)					// Zwraca węzeł z maksymalnym kluczem
    {
      while(x->left)
      {
	x = x->left;
      }
      
      return x;
    }

    
    
    template<class Typ>									// Zwraca węzeł z minimalnym kluczem
    BSTNode<Typ> * BST<Typ>::maxNode(BSTNode<Typ> * x)
    {
      while(x->right) 
      {
	x = x->right;
      }
      
      return x;
    }

    
    
   
   template<class Typ>
    BSTNode<Typ> * BST<Typ>::pred(BSTNode<Typ> * x)					 // Zwraca węzeł poprzednika
    {
      if(x->left) return maxNode(x->left);

      BSTNode<Typ> * y;

      do
      {
	y = x;
	x = x->p;
      } while(x && (x->right != y));

      return x;  
    }

    
    
    
    template<class Typ>
    BSTNode<Typ> * BST<Typ>::succ(BSTNode<Typ> * x)					// Zwraca węzeł następnika
    {
      if(x->right) return minNode(x->right);

      BSTNode<Typ> * y;

      do
      {
	y = x;
	x = x->p;
      } while(x && (x->left != y));

      return x;
    }

    
    
    
    
    template<class Typ>
    BSTNode<Typ> * BST<Typ>::remove(BSTNode<Typ> * x)					// Usuwa element x ze struktury BST. Zwraca usunięty węzeł
    {
      BSTNode<Typ> * y = x->p, * z;

      if((x->left) && (x->right))
      {
	z = (rand() % 2) ? remove(pred(x)) : remove(succ(x));
	z->left = x->left;   if(z->left)  z->left->p  = z;
	z->right = x->right; if(z->right) z->right->p = z;
	count++;
      }
      else z = (x->left) ? x->left : x->right;

      if(z) 
	z->p = y;
      
      if(!y)
	root = z;
      else if(y->left == x) y->left = z; else y->right = z;
      
      count--;
      return x;
    }


   
   
   
    template<class Typ>			
    void BST<Typ>::preorder(BSTNode<Typ> * x)						// Przechodzi przez BST metodą preorder
    {
      if(x)
      {
	cout << x->key << "\n";  // tutaj przetwarzamy bieżący węzeł
	preorder(x->left);
	preorder(x->right);
      }  
    }

    
    
    
    template<class Typ>
    void BST<Typ>::inorder(BSTNode<Typ>* x)						// Przechodzi przez BST metodą inorder
    {
      if(x)
      {
	inorder(x->left);
	cout << x->key << "\n";  							// tutaj przetwarzamy bieżący węzeł
	inorder(x->right);
      }
    }

  
  
  
    template<class Typ>
    void BST<Typ>::postorder(BSTNode<Typ> * x)						// Przechodzi przez BST metodą postorder
    {
      if(x)
      {
	postorder(x->left);
	postorder(x->right);

      cout << x->key << "\n";  								// tutaj przetwarzamy bieżący węzeł
      }  
    }

    
    
    
    template<class Typ>
    void BST<Typ>::walk(BSTNode<Typ> * x)						// Przechodzi przez drzewo wypisując zawartość węzłów
    {
      cout << x->key << " : Left-> ";
      if(x->left) cout << x->left->key;
      else        cout << "NIL";
      cout << ", Right-> ";
      if(x->right) cout << x->right->key;
      else         cout << "NIL";
      cout << "\n";
      if(x->left)  walk(x->left);
      if(x->right) walk(x->right);
    }


    
    
    
    template<class Typ>
    void BST<Typ>::coutBSTcount()							// Wyswietla aktualna liczbe wezlow w drzewie BST
    {
      cout << "\nLiczba wezlow drzewa BST : " << count << "\n" << "\n";  
    }

    // **********************************
    // *** Funkcje obsługi opcji menu ***
    // **********************************


    
    
    
    template<class Typ>
    void add(BST<Typ> * T)							// Dodaje nowe węzły do drzewa BST
    {
      cout << "Dodawanie nowych wezlow do drzewa BST\n"
	      "-------------------------------------\n\n";
      T->coutBSTcount();
      cout << "Podaj liczbe wezlow do utworzenia, a nastepnie wprowadz odpowiednia\n"
	      "liczbe kluczy nowych wezlow.\n\n";

      int i,n;

      BSTNode<Typ> * x;
      
      cin >> n;
      for(i = 0; i < n; i++)
      {
	x = new BSTNode<Typ>;
	cin >> x->key;

      T->insert(x);      
      }
      
      cout <<"\n";
      T->walk(T->root);
      T->coutBSTcount();      
    }

    
    
    
    template<class Typ>			
    void del(BST<Typ> * T)							// Usuwa węzeł o zadanym kluczu
    {
      cout << "Usuwanie wezla drzewa BST o zadanym kluczu\n"
	      "------------------------------------------\n\n";
      T->coutBSTcount();
      
      BSTNode<Typ> * x;
      Typ key;
      
      cout << "Podaj klucz usuwanego wezla : "; cin >> key;

      x = T->search(key);
      
      if(x)
      {
	delete T->remove(x);
	cout << "\n";
	if(T->root) T->walk(T->root);
	T->coutBSTcount();    
      }
      else cout << "\nBrak wezla o takim kluczu\n";
    }

    
    
    
    
    template<class Typ>
    void check(BST<Typ> * T)								// Sprawdza, czy drzewo zawiera węzeł o zadanym kluczu
    {
      cout << "Sprawdzenie obecnosci wezla o danym kluczu w drzewie BST\n"
	      "--------------------------------------------------------\n\n"
	      "Podaj klucz wezla : ";

      Typ key;
      
      cin >> key;
      
      cout << "\n";
      

    if(T->search(key)) cout << "Wezel znaleziony.\n";
      else               cout << "W drzewie BST brak wezla o podanym kluczu\n";
    }

    
    
    
    
    template<class Typ>	
    void minmax(BST<Typ> * T)								// Znajduje minimalny i maksymalny klucz
    {
      cout << "Znajdowanie minimalnego i maksymalnego klucza w drzewie BST\n"
	      "-----------------------------------------------------------\n\n"
	      "Klucz minimalny  : " << T->minKey(T->root) << "\n" <<
	      "Klucz maksymalny : " << T->maxKey(T->root) << "\n";
    }

    
    
    
    template<class Typ>
    void pred(BST<Typ> * T)								// Znajduje poprzednik węzła o zadanym kluczu
    {
      cout << "Znajdowanie poprzednika w drzewie BST\n"
	      "-------------------------------------\n\n"
	      "Podaj klucz wezla : ";
      Typ key;
      BSTNode<Typ> * x;
      
      cin >> key;
      cout << "\n";
      
      x = T->search(key);
      
      if(x)
      {
	x = T->pred(x);
	
	if(x) 
	  cout << "Poprzednikiem [" << key << "] jest " << x->key << "\n";
	
	else 
	  cout << "Wezel [" << key << "] nie posiada poprzednika\n";   
	
      }
      else 
	cout << "Wezel o podanym kluczu nie istnieje w drzewie BST\n";
    }

    
    
    
    template<class Typ>
    void succ(BST<Typ> * T)								// Znajduje następnik węzła o zadanym kluczu
    {
      cout << "Znajdowanie nastepnika w drzewie BST\n"
	      "------------------------------------\n\n"
	      "Podaj klucz wezla : ";
      Typ key;
      BSTNode<Typ> * x;
      
      cin >> key;
      cout << "\n";
      
      x = T->search(key);
      
      if(x)

     {
	x = T->succ(x);
	if(x) 
	  cout << "Nastepnikiem [" << key << "] jest " << x->key << "\n";
	
	else  
	  cout << "Wezel [" << key << "] nie posiada nastepnika\n";   
      }
      else cout << "Wezel o podanym kluczu nie istnieje w drzewie BST\n";     
    }

   
   
   
   template<class Typ>
    void preorder(BST<Typ> * T)								// Przejscie po drzewie w kolejnosci preorder
    {
      cout << "Przechodzenie drzewa BST algorytmem preorder\n"
	      "--------------------------------------------\n\n";
      T->preorder(T->root);    
    }

    
    
    
    template<class Typ>
    void inorder(BST<Typ> * T)							// Przejscie po drzewie w kolejnosci inorder
    {
      cout << "Przechodzenie drzewa BST algorytmem inorder\n"
	      "-------------------------------------------\n\n";
      T->inorder(T->root);
    }


    template<class Typ>								// Przejscie po drzewie w kolejnosci postorder
    void postorder(BST<Typ> * T)
    {
	cout << "Przechodzenie drzewa BST algorytmem postorder\n"
	    "---------------------------------------------\n\n";
	T->postorder(T->root);     
    }	



#endif // BST_HPP_INCLUDED