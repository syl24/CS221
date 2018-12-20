#define CATCH_CONFIG_MAIN
#include <iostream>
#include "cs221util/catch.hpp"
#include "stack.h"
#include "queue.h"
//using namespace cs221util;
using namespace std;

TEST_CASE("stack::basic functions","[weight=1][part=stack]"){
    //cout << "Testing Stack..." << endl;
    Stack<int> intStack;
    vector<int> result;
    vector<int> expected;
    for (int i = 10; i > 0; i--) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intStack.push(i);
    }
    //cout << intStack.peek() << endl;
    while (!intStack.isEmpty()) {
        result.push_back(intStack.pop());
        //cout << intStack.pop() << " ";
    }
    REQUIRE( result == expected);
}
TEST_CASE("stack::my stack tests","[weight=1][part=stack]"){
	Stack<int> intStack;
	vector<int> result;
    vector<int> expected;
	
	//test right number elements
	for(int i =0; i< 20; i++){
		intStack.add(i);
	}
	cout << intStack.size() << endl;
	
	for(int i=0; i<20; i++)
		intStack.remove();
	cout << intStack.size() << endl;
	
	Stack<vector<int>> vecStack;
	vector<int> a{1,2};
	vector<int> b{3,4};
		
	vecStack.add(a);
	vecStack.add(b);
	
	cout << vecStack.size() << endl;
	cout << to_string(vecStack.peek()[0]) << endl;
	// vecStack.remove();
	// cout << vecStack.peek() << endl;
	
	Stack<string> strStack;
	string s = "apple";
	string q = "muffin";
	
	strStack.add(s);
	strStack.add(q);
	//cout << strStack.size() << endl;
	cout << strStack.peek() << endl;
	strStack.remove();
	cout << strStack.peek() << endl;
	
}


TEST_CASE("queue::basic functions","[weight=1][part=queue]"){
    //cout << "Testing Queue..." << endl;
    Queue<int> intQueue;
    vector<int> result;
    vector<int> expected;
    for (int i = 1; i <= 10; i++) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intQueue.enqueue(i);
    }
    //cout << intStack.peek() << endl;
    while (!intQueue.isEmpty()) {
        result.push_back(intQueue.dequeue());
        //cout << intStack.pop() << " ";
    }
    REQUIRE( result == expected);
}

