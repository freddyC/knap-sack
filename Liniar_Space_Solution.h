/*

 This is the implementation of the liniar space solution to the knap sack problem.
 
 Solution_Abstract is the base class, 
 it gives us the ability to generate input on the fly and the containers for the size and value arrays.

*/
#ifndef LINIAR_SPACE_SOLUTION_H
#define LINIAR_SPACE_SOLUTION_H
#include "Abstract_Solution.h"


class Liniar_Space_Solution : public Abstract_Solution {
  public:
    Liniar_Space_Solution () : Abstract_Solution() {}
    virtual double solve(int item, int currentBagSize, double currentBagValue);
};

#endif