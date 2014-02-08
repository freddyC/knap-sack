//
//  Dynamic_Solution.cpp
//  knap_sack
//
//  Created by Fred Christensen on 1/21/14.
//  Copyright (c) 2014 Fred Christensen. All rights reserved.
//

#include "Dynamic_Solution.h"

/*
 Used the following sudo code from http://en.wikipedia.org/wiki/Knapsack_problem#Dynamic_programming
 // Input:
    // Values (stored in array v)
    // Weights (stored in array w)
    // Number of distinct items (n)
    // Knapsack capacity (W)
  for j from 0 to W do
    m[0, j] := 0
  end for
 
  for i from 1 to n do
    for j from 0 to W do
      if w[i] <= j then
        m[i, j] := max(m[i-1, j], m[i-1, j-w[i]] + v[i])
      else
        m[i, j] := m[i-1, j]
      end if
    end for
  end for
*/

double Dynamic_Solution::solve(int item, int currentBagSize, double currentBagValue)
{
  for(int i = 1; i < this->numberOfItems; ++i) {// from 1 because at 0 objects we are done
    for (int j = 0; j <= this->originalBagSize; ++j) {
      if (this->itemSizes[i] <= j) {
        this->bagValues[i][j] = std::max(this->bagValues[i-1][j], this->bagValues[i-1][j - this->itemSizes[i]] + this->itemValues[i]);
        // std::cout << this->bagValues[i][j] << ",\t";
      } else {
        this->bagValues[i][j] = this->bagValues[i-1][j];
        // std::cout << this->bagValues[i][j] << ",\t";
      }
    }
    // std::cout << "\n";
  }

  std::for_each(this->bagValues.begin(), this->bagValues.end(), [] (std::vector<double> vec) {
    std::cout << std::endl;
    std::for_each(vec.begin(), vec.end(), [] (double val) {
      std::cout << val << ",\t";
    });
  });
  return this->bagValues[this->numberOfItems - 1][this->originalBagSize];
}