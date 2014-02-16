//
//  Dynamic_Solution.h
//  knap_sack
//
//  Created by Fred Christensen on 1/21/14.
//  Copyright (c) 2014 Fred Christensen. All rights reserved.
//

#ifndef DYNAMIC_SOLUTION_H
#define DYNAMIC_SOLUTION_H

#include "Abstract_Solution.h"

class Dynamic_Solution : public Abstract_Solution {
public:

  Dynamic_Solution() : Abstract_Solution() {}
  virtual double solve(int item, int currentBagSize, double currentBagValue);

};

#endif
/* defined(__knap_sack__Dynamic_Solution__) */
