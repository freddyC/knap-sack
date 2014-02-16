/*
  A divide and conquor aproach to the knap sack problem.

  This will probably be worse speed wise than the Dynamic Programing knap sack or the caching knap sack solutions
    BUT it will be much much better on the amount of memory it requires.

*/


#include "Liniar_Space_Solution.h"

double Liniar_Space_Solution::solve(int item, int currentBagSize, double currentBagValue) {
  this->itemsUsed.resize(this->numberOfItems +1, false);

  this->knapDC(item, this->numberOfItems, currentBagSize);

  double result = 0;
  for (int i = 0; i <= this->itemsUsed.size(); ++i) {
    if (this->itemsUsed[i]) {
      result += this->itemValues[i];
    }
  }
  return result;
}

// sets the values in kUse
void Liniar_Space_Solution::knapDC(int lowIndex, int highIndex, int capacity) {
   // single object, use it if it fits (value always > 0)
  if(lowIndex == highIndex) {
    this->itemsUsed[lowIndex] = (this->itemSizes[lowIndex] <= capacity);
    return;
  } else {
    int midIndex = (lowIndex + highIndex) / 2;
    // linear space, scans from low to mid, returns last column 0 to capacity
    std::vector<double> left (capacity);
    left = this->solveHalf (lowIndex, midIndex, capacity, true);
    // linear space, scans from high down to midIndex+1, returns last column
    std::vector<double> right (capacity);
    right = this->solveHalf(highIndex, midIndex +1, capacity, false);
    // find the crossing point, loop over 0<=i<=capacity
    int bestSize = argMax(left, right, capacity);
    // solve the two smaller problems
    knapDC(lowIndex, midIndex, bestSize);
    knapDC(midIndex +1, highIndex, capacity - bestSize);
  }
}

std::vector<double> Liniar_Space_Solution::solveHalf (int start, int end, int capacity, bool ascending) {
  std::vector<double> prevK (capacity +1, 0.0);
  std::vector<double> k (capacity +1, 0.0);
  for (int i = start; (ascending) ? i <= end : i >= end; (ascending) ? ++i : --i) {
    for (int j = 0; j <= capacity; ++j) {
      if (this->itemSizes[i] <= j) {
        k[j] = std::max(prevK[j], prevK[j - this->itemSizes[i]] + this->itemValues[i]);
      } else {
        k[j] = prevK[j];
      }
    }
    prevK = k;
  }
  return k;
}

int Liniar_Space_Solution::argMax (const std::vector<double> &left, const std::vector<double> &right, int capacity) {
  int maxIndex = 0;
  double temp = 0;
  for (int i = 0; i < left.size(); ++i) {
    if (temp < left[i]) {
      temp = left[i];
      maxIndex = i;
    }
  }

  if (left[maxIndex] > right[capacity - maxIndex]) {
    return maxIndex;
  } else {
    return capacity - maxIndex;
  }
}