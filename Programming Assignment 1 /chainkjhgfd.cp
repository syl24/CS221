#include "chain.h"
#include "chain_given.cpp"

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){
    clear();
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block & ndata){
    /*your code here*/

    Node * data = new Node(ndata);

   if (head_ == NULL) {
     head_ = new Node();
     tail_ = new Node();
     data->next = tail_;
     data->prev = head_;
     head_->next = data;
     tail_->prev = data;
     length_ = length_ + 1;
   } else if (head_->next == NULL) {
       head_->next = data;
       tail_->prev = data;
       data->prev = head_;
       data->next = tail_;
       length_ = length_ + 1;
     } else {
       tail_->prev->next = data;
       data->prev = tail_->prev;
       data->next = tail_;
       tail_->prev = data;
       length_ = length_ + 1;
     }

}

/**
 * Modifies the Chain by moving a contiguous subset of len Nodes
 * dist nodes toward the end of the chain beginning from startPos
 * (maintaining the sentinel at the end). Their order is
 * not changed in the move. You may assume that the startPos and
 * len parameters are kind: startPos + len -1 <= length. If there
 * are not enough nodes to shift by dist, just shift as many as
 * possible.
 */
void Chain::moveBack(int startPos, int len, int dist){
    /*your code here*/
    if (empty()) {
      return;
    } else if ((dist >= size()) || (len == 0) || (dist == 0)) {
      return;
    }
    if (startPos + len > size()) {
      len = size() - startPos;
    }
      Node * curr = walk(head_, startPos);
      Node * prev = walk(head_, startPos - 1);

      Node * ptr_len = walk(curr, len);
      Node * ptr_prev_len = walk(prev, len);

      Node * end_ptr = walk(ptr_len, dist);
      Node * end_ptr_prev = walk(ptr_prev_len, dist);

      curr->prev = end_ptr_prev;
      prev->next = ptr_len;
      ptr_len->prev = prev;
      end_ptr_prev->next = curr;
      ptr_prev_len->next = end_ptr;
      end_ptr->prev = ptr_prev_len;

      // 
      // end_ptr_prev->next = curr;
      // prev->next = ptr_len;
      // ptr_len->prev = prev;
      // curr->next = end_ptr;
      // end_ptr->prev = ptr_prev_len;
      // ptr_prev_len->next = end_ptr;
      // curr->prev = end_ptr_prev;
}
/**
 * Rolls the current Chain by k nodes: removes the last
 * k nodes from the Chain and attaches them, in order, at
 * the start of the chain (maintaining the sentinel at the front).
 */
void Chain::roll(int k){
    /*your code here*/
}

/**
 * Modifies the current chain by reversing the subchain
 * between pos1 and pos2, inclusive. The positions are
 * 1-based. You may assume that pos1 and pos2 are valid
 * locations in the Chain, and that pos2 >= pos1.
 */
void Chain::reverseSub(int pos1, int pos2){
    /*your code here */
}

/*
* Modifies both the current and input chains by removing
* nodes from other, and interleaving them between the Nodes
* from the current Chain. The nodes from the other Chain
* should occupy the even locations in the result. length
* of the resulting chain should be the sums of the lengths
* of current and the other. The other chain should have only
* two sentinels and no data nodes at the end of the operation.
* the weave fails and the original
* chains should be unchanged if block sizes are different.
* in that case, the result of the function should be:
* cout << "Block sizes differ." << endl;
*/
void Chain::weave(Chain & other) { // leaves other empty.
    /*your code here */
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */

void Chain::clear() {

  length_ = 0;
  width_ = 0;
  height_ = 0;

  Node * sub = head_;

  while (sub != NULL) {
    Node * new_ = sub;
    sub = sub->next;
    delete new_;
    new_ = NULL;
  }
    head_ = NULL;
    tail_ = NULL;
    sub = NULL;
  }

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */

void Chain::copy(Chain const& other) {
  height_ = other.height_;
  width_ = other.width_;
  length_ = other.length_;
  head_ = new Node();
  tail_ = new Node();

  Node * new_next_ptr = other.head_;
  Node * curr = head_;
  Node * new_prev_ptr = other.tail_;

  if (new_next_ptr->next == new_prev_ptr) {
    head_->next = tail_;
    tail_->prev = head_;
  } else {
    new_next_ptr  = new_next_ptr->next;
    while (new_next_ptr != NULL) {
      curr->next = new Node(new_next_ptr->data);
      curr->next->prev = curr;
      curr = curr->next;

      new_next_ptr = new_next_ptr->next;

      if (new_next_ptr == new_prev_ptr) {
        tail_->prev = curr;
        curr->next = new_prev_ptr;
      }
    }
  }

}
