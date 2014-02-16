//
//  Recursive_Solve.cpp
//  knap_sack
//
//  Created by Fred Christensen on 1/18/14.
//  Copyright (c) 2014 Fred Christensen. All rights reserved.
//

#include "Recursive_Solution.h"

double Recursive_Solution::solve(int item, int currentBagSize, double currentBagValue) {
    // Base Cases
  if (item >= this->numberOfItems || item >= this->numberOfItems) return currentBagValue;
  if (currentBagSize <= 0) return currentBagValue;
  
    // A few variables for clarity
  int mySize = this->itemSizes[item];
  int newBag = currentBagSize - mySize;

  double myValue = this->itemValues[item]
       , withMe
       , withoutMe
       ;

    // recursive cases adding the current item
  if (newBag < 0) {
    withMe = currentBagValue;
  } else {
    withMe = this->solve((item + 1), (currentBagSize - mySize), (currentBagValue + myValue));
  }
 
    // recursive case without the current item
  withoutMe = this->solve((item + 1), currentBagSize, currentBagValue);
  
    // return the bigger currentBagValue
  return ( (withMe > withoutMe) ? withMe : withoutMe );
}