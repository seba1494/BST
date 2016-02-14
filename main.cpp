// Wcislo Sebastian gr.2I1
// Projekt 3 PROI
// System klas do obslugi drzew BST
// Program glowny

using namespace std;
#include<iostream>
#include <cstdlib>
#include "Bst.h"



int main()
{
  BST<char> * T = new BST<char>;
  int choice;
  
  do
  {
    cout<<" \n";
    cout << "Test funkcji obslugi drzew poszukiwan binarnych\n"
            "========================================================\n\n"
            "Wybierz opcje\n"
            "--------------------------------------------------------\n"
            " 0) Koniec\n"
            " 1)  Dodaj wezly\n"
            " 2)  Usun wezel\n"
            " 3)  Sprawdz czy istnieje taki wezel\n"
            " 4)  Znajdz wezel o minimalnym i maksymalnym kluczu\n"
            " 5)  Poprzednik\n"
	    " 6)  Nastepnik\n"
            " 7)  Preorder\n"
            " 8)  Inorder\n"
            " 9)  Postorder\n"
            "--------------------------------------------------------\n"
            "Twoj wybor : ";
    cin >> choice;
    
    switch(choice)
    {
      case 1 : add(T);       break;
      case 2 : del(T);       break;
      case 3 : check(T);     break;
      case 4 : minmax(T);    break;
      case 5 : pred(T);      break;
      case 6 : succ(T);      break;
      case 7 : preorder(T);  break;
      case 8 : inorder(T);   break;
      case 9 : postorder(T); break;
    }
    if((choice >= 1) && (choice <= 9))
    {
      cout << endl;
      
    }
  } while(choice);
  
  delete T;
  return 0;
}