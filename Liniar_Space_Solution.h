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
    Liniar_Space_Solution ()
      : Abstract_Solution()
      , itemsUsed()
    {}
    virtual double solve(int item, int currentBagSize, double currentBagValue);
  private:
    void knapDC(int lowIndex, int highIndex, int capacity);
    std::vector<double> solveHalf (int start, int end, int capacity, bool ascending);
    int argMax (const std::vector<double> &left, const std::vector<double> &right, int capacity);
    std::vector<int> itemsUsed;
};

#endif