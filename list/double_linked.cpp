#include <iostream>

template <class T> class Node {
  private:
    Node<T> * next;
    Node<T> * prev;
    T key;
  public:
    Node(T newKey,Node<T> * newNext=nullptr,Node<T> * newPrev=nullptr){
      key = newKey;
      next=newNext;
      prev=newPrev;
    };

    void setPrev(Node<T> * newPrev){
      prev = newPrev;
    }

    T& getKey(void){return key;}
    Node<T> * getNext(void){return next;}
    Node<T> * getPrev(void){return prev;}
};

template <class T> class LinkedList {
  private:
   Node<T> * head;
  public:
   LinkedList(T elem){
     head = new Node<T>(elem);
   };

   void insert(T elem){
     Node<T> * oldHead = head;
     head = new Node<T> (elem, oldHead);
     oldHead->setPrev(head);
   };

   Node<T>* getHead(void){return head;}
};

int main(){
  LinkedList<int> * myList = new LinkedList<int>(1);
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
