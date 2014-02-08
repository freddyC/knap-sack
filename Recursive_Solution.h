/*

 This is the implementation of the recursive solution.
 
 Solution_Abstract is the base class, 
 it gives us the ability to generate input on the fly and the containers for the size and value arrays.

*/
#ifndef RECURSIVE_SOLUTION_H
#define RECURSIVE_SOLUTION_H
#include "Abstract_Solution.h"


class Recursive_Solution : public Abstract_Solution {
  public:
    Recursive_Solution() : Abstract_Solution() {}
    virtual double solve(int item, int currentBagSize, double currentBagValue);
};

#endif