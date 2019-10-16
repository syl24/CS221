/**
 * @file queue.cpp
 * Implementation of the Queue class.
 *
 */

/**
 * Adds the parameter object to the back of the Queue.
 *
 * @param newItem object to be added to the Queue.
 */
template <class T>
void Queue<T>::enqueue(T const& newItem)
{
/*     while (!outStack.isEmpty()){
        inStack.add(outStack.peek());
        outStack.remove();
    }

    inStack.add(newItem);


    while(!inStack.isEmpty()){
        outStack.add(inStack.peek());
        inStack.remove();
    } */
	inStack.push(newItem);
}

/**
 * Removes the object at the front of the Queue, and returns it to the
 * caller.
 *
 * @return The item that used to be at the front of the Queue.
 */
template <class T>
T Queue<T>::dequeue()
{
/*      while (!outStack.isEmpty()){
        inStack.add(outStack.peek());
        outStack.remove();
    }

    T temp = inStack.peek();
    inStack.remove();

    while(!inStack.isEmpty()){
        outStack.add(inStack.peek());
        inStack.remove();
    }
    return temp;
 */
 
	if (outStack.isEmpty()){

		while (!inStack.isEmpty()){
			outStack.push(inStack.pop());

		}
		/* 		T temp = outStack.peek();
			
			outStack.remove();
			return temp; */
	}
	return outStack.pop();
 
 }

/**
 * Adds an element to the ordering structure.
 *
 * @see OrderingStructure::add()
 */
template <class T>
void Queue<T>::add(const T& theItem)
{
    enqueue(theItem);
}

/**
 * Removes an element from the ordering structure.
 *
 * @see OrderingStructure::remove()
 */
template <class T>
T Queue<T>::remove()
{
    return dequeue();
}

/**
 * Finds the object at the front of the Queue, and returns it to the
 * caller. Unlike pop(), this operation does not alter the queue.
 *
 * @return The item at the front of the queue.
 */
template <class T>
T Queue<T>::peek()
{

    while(!inStack.isEmpty()){
        outStack.add(inStack.peek());
        inStack.remove();
    }

    return outStack.peek();

}

/**
 * Determines if the Queue is empty.
 *
 * @return bool which is true if the Queue is empty, false otherwise.
 */
template <class T>
bool Queue<T>::isEmpty() const
{
    return ((inStack.isEmpty()) && (outStack.isEmpty()));
}
