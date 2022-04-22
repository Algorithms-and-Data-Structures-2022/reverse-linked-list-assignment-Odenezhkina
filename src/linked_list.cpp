#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ <=  1){
      return;
    }
    Node* prev  = nullptr;
    Node* curr = front_;
    while (curr->next != nullptr) {
      Node* node = curr -> next;
      curr -> next = prev;
      prev = curr;
      curr = node;
    }
    Node* bk = back_;
    curr -> next = prev;
    back_ = front_;
    front_ = bk;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_, nullptr);
    Node* node = front_;
    front_ = back_;
    back_ = node;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if(curr != nullptr){
      reverse_recursive_helper(curr->next, curr);
      curr->next = prev;
    }
    return;
  }

}  // namespace assignment
