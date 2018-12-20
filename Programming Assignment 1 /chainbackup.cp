#include "chain.h"
#include "chain_given.cpp"

// PA1 functions



/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){ 
    /*your code here*/
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
    
    Node * n = new Node(ndata);

    if(tail_ == nullptr){
        head_ = new Node();
        tail_ = new Node();
        head_->next = n;
        tail_->prev = n;
        n->next = tail_;
        n->prev = head_;
        length_ ++;
    }

    if(tail_->prev == head_){
       head_->next = n;
       tail_->prev = n;
       n->prev = head_;
       n->next = tail_;
       length_ ++;
   }

   if (tail_->prev != head_) {
       tail_->prev->next = n;
       n->prev = tail_->prev;
       tail_->prev = n;
       n->next = tail_;
       length_ ++;
   }
   

}

// }

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

    Node * start = walk(head_, startPos);
    Node * tempb4_start = walk(head_, startPos - 1);

    Node * end = walk(start, len);
    Node * tempb4_end = walk(start, len - 1);

    Node * deststart = walk(end, dist);
    Node * tempb4_dest = walk(end, dist - 1);


    if (empty() || len == 0 || dist == 0||  startPos + len > size() || dist >= size()){
        return;
    }

    start->prev = tempb4_dest;
    tempb4_dest->next = start;

    tempb4_end->next = deststart;
    deststart->prev = tempb4_end;

    tempb4_start->next = end;
    end->prev = tempb4_start;

    start = end = deststart = tempb4_start = tempb4_end  = tempb4_dest = nullptr;


}

/**
 * Rolls the current Chain by k nodes: removes the last
 * k nodes from the Chain and attaches them, in order, at
 * the start of the chain (maintaining the sentinel at the front).
 */
void Chain::roll(int k){
    /*your code here*/

    // moveBack(1, size() - k, k);

    // Node * start = walk(head_, (this->length_ - k ));
    // Node * end = walk(start, (this->length_));

    // Node * b4Start = start->prev;
    // tail_->prev = b4Start;
    // b4Start->next = tail_;

    // Node * afHead = head_->next;
    // head_->next = start;
    // start->prev = head_;

    // end->next = afHead;
    // afHead->prev = end;


}

/**
 * Modifies the current chain by reversing the subchain
 * between pos1 and pos2, inclusive. The positions are
 * 1-based. You may assume that pos1 and pos2 are valid
 * locations in the Chain, and that pos2 >= pos1.
 */
void Chain::reverseSub(int pos1, int pos2){
    /*your code here */

    if (pos1 == pos2){
        return;
    }

    if (pos1 != pos2){
    while (pos1 != pos2){
        moveBack(pos1, pos2 - pos1, 1);
        pos1+= 1; 
        }
    }

    // Node * s = walk(head_, ((int) pos1 + 1));
    // Node * e = walk(head_, ((int) pos2 + 1));

    // // while (pos1 != pos2){

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
    /*your code here*/

    length_ = 0;
    height_ = 0;
    width_ = 0;
    
    Node * current = head_;

    while (current != nullptr) {
        Node * nxt = current;
        current = current->next;
        delete nxt;
        nxt = nullptr;
    }

    current = head_ = tail_ = nullptr;
    
    
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */

void Chain::copy(Chain const& other) {
    /*your code here*/

    length_ = other.length_;
    height_ = other.height_;
    width_ = other.width_;
    tail_ = new Node();
    head_ = new Node();

    Node * temp = other.head_;
    Node * tEnd = other.tail_;
    Node * current = head_;
    
    if(temp->next == tEnd){
        head_->next = tail_;
        tail_->prev = head_;
    }

    temp = temp->next;
    
    while (temp != nullptr) {
        current->next = new Node(temp->data);
        current->next->prev = current;
        current = current->next;
        
        temp = temp->next;

        if (temp == tEnd) {
            tail_->prev = current;
            current->next = tail_;
        }
    }

}