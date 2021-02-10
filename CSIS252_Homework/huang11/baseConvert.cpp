//File: baseConvert.cpp
//Author: Pengfei Huang
//Date: 04/29/2018


#include "baseConvert.h"
#include "stackType.h"
#include "queueType.h"
#include <iostream>

using namespace std;

int baseConvert::Dec2Bin(int d){
  stackType<int> s;
  int tmpBinary=0;
  while(d>0 && !s.isFullStack()){
    s.push(d%2);
    d=d/2;
  }
  while (!s.isEmptyStack()){
    tmpBinary = tmpBinary*10+s.top();
    s.pop();
  }
  return tmpBinary;
}

int baseConvert::Bin2Dec(int b){
  queueType<int> q;
  int decimal =0;
  int position =1;
  while (b>0 && !q.isFullQueue()){
    q.addQueue(b%10);
    b=b/10;
  }
  while(!q.isEmptyQueue()){
    decimal = decimal + q.front()*position;
    q.deleteQueue();
    position = position*2;
  }
  return decimal;
}