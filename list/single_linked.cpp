#include <iostream>

template <class T> class Node {
  private:
    Node<T>* next;
    T key;
  public:
    Node(T newKey, Node<T>* newNext=nullptr){
      key  = newKey;
      next = newNext;
    };

    T& getKey(void){return key;}
    Node<T>* getNext(void){return next;}
};

template <class T> class List {
  private:
   Node<T> * head;
  public:
   List(T elem){
     head = new Node<T>(elem);
   };

   void insert(T elem){
     Node<T>* oldHead = head;
     head = new Node<T> (elem, oldHead);
   };

   Node<T>* getHead(void){return head;}
};

int main(){
  List<int>* myList = new List<int>(1);
  for(int i=2; i<6; ++i){
    myList->insert(i);
  }

  Node<int>* x = myList->getHead();
  while( x != nullptr ){
    std::cout << x-> getKey() << std::endl;
    x = x->getNext();
  }
  return 0;
}
