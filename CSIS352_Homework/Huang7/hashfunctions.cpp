#include <iostream>
#include "constants.h"
#include "symbol.h"
// using modulo arithmetic
using namespace std;
// Function: hash1
// Description: take a Symbol class and using modulo arithmetic return a int 
// Input:  Symbol class
// Output: int
// Preconditions: a Symbol class was given
int hash1(const Symbol& value){
    
    int sum=0;
    int length = value.getSymbol().length();
    for(int i =0; i< length; i++){
        sum +=(int)value.getSymbol()[i];
   
    }
   
    return sum%TABLE_SIZE;
}
// Function: hash2
// Description: take a int and using modulo arithmetic return a int 
// Input:  Symbol class
// Output: int
// Preconditions: an int was given
int hash2(const int& value){
    return value % TABLE_SIZE;
}
