//
//  Memoized_Solution.cpp
//  knap_sack
//
//  Created by Fred Christensen on 1/18/14.
//

#include "Memoized_Solution.h"

double Memoized_Solution::solve(int item, int currentBagSize, double currentBagValue)
{
    // Base Cases
  if (item >= this->itemSizes.size() || item >= this->itemValues.size()) return currentBagValue;
  if (currentBagSize < 0) return currentBagValue;
  
//  std::cout << "item: " << item << " currentBagSize: " << currentBagSize << " seen " << this->seen.size() << " X " << this->seen[item].size() << " bagValues " << this->bagValues.size() << " X " << this->bagValues[item].size() << std::endl;
  
  // Check If Seen
  if (this->seen[item][currentBagSize])
  {
    return this->bagValues[item][currentBagSize];
  }
  
  
    // A few variables for clarity
  int mySize = this->itemSizes[item];
  int newBag = currentBagSize - mySize;
  
  double myValue = this->itemValues[item]
  , withMe
  , withoutMe
  ;
  
    // recursive cases adding the current item
  if (newBag < 0)
  {
    withMe = currentBagValue;
  } else {
    withMe = this->solve((item + 1), (currentBagSize - mySize), (currentBagValue + myValue));
  }
  
    // recursive case without the current item
  withoutMe = this->solve((item + 1), currentBagSize, currentBagValue);

    // Save Solution into Cache and Seen
  double result = std::max(withMe, withoutMe);
  
  this->seen[item][currentBagSize] = true;
  this->bagValues[item][currentBagSize] = result;
  
    // return the bigger currentBagValue
  return result;
}