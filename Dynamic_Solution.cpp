//
//  Dynamic_Solution.cpp
//  knap_sack
//
//  Created by Fred Christensen on 1/21/14.
//  Copyright (c) 2014 Fred Christensen. All rights reserved.

#include "Dynamic_Solution.h"

double Dynamic_Solution::solve(int item, int currentBagSize, double currentBagValue) {
  for(int i = 1; i <= this->numberOfItems; ++i) {       // from 1 because at 0 objects we are done
    for (int j = 1; j <= this->originalBagSize; ++j) {  // from 1 because at 0 objects we are done
      if (this->itemSizes[i] <= j) { // If your item will fit in the bag
                                     // Take the greater of your item in the bag and your item not in the bag
        this->bagValues[i][j] = std::max(this->bagValues[i-1][j], this->bagValues[i-1][j - this->itemSizes[i]] + this->itemValues[i]);
      } else {
        // Your item doesn't fit anyways just keep the same size
        this->bagValues[i][j] = this->bagValues[i-1][j];
      }
    }
  }

  this->getUsedItems();
  return this->bagValues[this->numberOfItems][this->originalBagSize];
}