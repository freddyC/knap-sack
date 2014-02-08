//
//  Memoized_Solution.h
//  knap_sack
//
//  Created by Fred Christensen on 1/18/14.
//  Copyright (c) 2014 Fred Christensen. All rights reserved.
//

#ifndef MEMOIZED_SOLUTION_H
#define MEMOIZED_SOLUTION_H

#include "Abstract_Solution.h"

class Memoized_Solution : public Abstract_Solution {
public:
  Memoized_Solution() : Abstract_Solution() {}
  
  virtual double solve(int item, int currentBagSize, double currentBagValue);


};


#endif /* defined(__knap_sack__Memoized_Solution__) */
