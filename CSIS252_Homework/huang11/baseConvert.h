//File: baseConvert.h
//Author: Pengfei Huang
//Date: 04/29/2018

// Description
// This file contains the specification for a baseConvert class

#ifndef _BASECONVERT_H_
#define _BASECONVERT_H_
#include "stackType.h"
#include "queueType.h"
class baseConvert{
  
public:
  // method - Dec2Bin
  // description - take an argument of a positive decimal value (int) and return an int of the binary value equivalent
  // preconditions - the decimal must be a int
  // postconditions - a binary will be returend base on the decimal  
  // method input - decimal (int) - the decimal value to convert
  // method output - binary (int) - result of the conversion of decimal to binary
  static int Dec2Bin(int decimal);
  
  // method - Bin2Dec
  // description - take an argument of a positive binary value (int) and return an int of the decimal value equivalent.
  // preconditions - the binary must be a int
  // postconditions - a decimal will be returend base on the decimal  
  // method input -  binary (int) - the binary value to convert
  // method output - decimal (int) - result of the conversion of binary to decimal
  static int Bin2Dec(int binary);
};

#endif