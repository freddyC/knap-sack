//
//  main.cpp
//  knap_sack
//
//  Created by Fred Christensen on 1/18/14.
//  Copyright (c) 2014 Fred Christensen. All rights reserved.
//

#include <iostream>
#include "Recursive_Solution.h"
#include "Memoized_Solution.h"
#include "Dynamic_Solution.h"

void test_recursive ();
void test_memoized ();
void test_cached ();
void test_memoized_robust (bool isWide);
void test_cached_robust (bool isWide);

const int BAG_SIZE           = 1000     // Maximum value size of bag
        , MIN_NUM_ITEMS      = 6        // Minimum Number of Items to draw from
        , MAX_NUM_ITEMS      = 25       // Maximum Number of Items to draw from
        , MIN_ITEM_SIZE      = 1        // Minimum Value for an item
        , MAX_ITEM_SIZE      = 1000     // Maximum Value for an item
        , TIMES_TO_RUN       = 30       // How many times a single test is re-run (then averaged)
        ;

  // These bools are not needed for the simple tests but the robust tests do need them.
const bool DOUBLE_GROWTH     = false    // Does the number of items double its self from test to test
         , RESPONSIVE_VALUES = false    // Does the value of items increase with number of items to draw from
         , IS_WIDE           = false    // Is the gap between min item value and max item value wider?
         ;

int main(int argc, const char * argv[])
{
  test_recursive  ();
  test_memoized ();
  test_cached ();
  test_memoized_robust (IS_WIDE);
  test_cached_robust (IS_WIDE);


  std::cout << "\n\nAll Done Here\n\n";
}

void test_recursive () {
  Recursive_Solution recursive;

  recursive.setNumberOfItems(MIN_NUM_ITEMS);
  recursive.setItemMinSize(MIN_ITEM_SIZE);
  recursive.setItemMaxSize(MAX_ITEM_SIZE);
  recursive.setOriginalBagSize(BAG_SIZE);
  recursive.setDoubleGrowth(DOUBLE_GROWTH);
  recursive.setResponsiveValues(RESPONSIVE_VALUES);

  std::cout << "RECURSIVE test STARTED\n";
  std::vector<double> recursive_results = recursive.runForSizes(MIN_NUM_ITEMS, MAX_NUM_ITEMS, TIMES_TO_RUN);
  std::cout << "RECURSIVE test DONE\n\n";
}

void test_memoized () {
  Memoized_Solution memoized;

  memoized.setNumberOfItems(MIN_NUM_ITEMS);
  memoized.setItemMinSize(MIN_ITEM_SIZE);
  memoized.setItemMaxSize(MAX_ITEM_SIZE);
  memoized.setOriginalBagSize(BAG_SIZE);
  memoized.setDoubleGrowth(DOUBLE_GROWTH);
  memoized.setResponsiveValues(RESPONSIVE_VALUES);

  std::cout << "MEMOIZED test STARTED\n";
  std::vector<double> memoized_results = memoized.runForSizes(MIN_NUM_ITEMS, MAX_NUM_ITEMS, TIMES_TO_RUN);
  std::cout << "MEMOIZED test DONE\n\n";
}

void test_cached () {
  Dynamic_Solution dynamic;

  dynamic.setNumberOfItems(MIN_NUM_ITEMS);
  dynamic.setItemMinSize(MIN_ITEM_SIZE);
  dynamic.setItemMaxSize(MAX_ITEM_SIZE);
  dynamic.setOriginalBagSize(BAG_SIZE);
  dynamic.setDoubleGrowth(DOUBLE_GROWTH);
  dynamic.setResponsiveValues(RESPONSIVE_VALUES);

  std::cout << "DYNAMIC test STARTED\n\n";
  std::vector<double> dynamic_results = dynamic.runForSizes(MIN_NUM_ITEMS, MAX_NUM_ITEMS, TIMES_TO_RUN);
  std::cout << "DYNAMIC test DONE\n\n";
}


void test_memoized_robust (bool isWide) {
  Memoized_Solution memoized;

  memoized.setNumberOfItems(MIN_NUM_ITEMS);
  memoized.setItemMinSize(MIN_ITEM_SIZE);
  memoized.setItemMaxSize(MAX_ITEM_SIZE);
  memoized.setOriginalBagSize(BAG_SIZE);
  memoized.setDoubleGrowth(DOUBLE_GROWTH);
  memoized.setResponsiveValues(RESPONSIVE_VALUES);
  memoized.setIsWide(isWide);

  std::string wide = (isWide) ? "wide" : "not wide";

  std::cout << "MEMOIZED robust test that is " << wide << " STARTED\n";
  memoized.runForSizes(MIN_NUM_ITEMS, MAX_NUM_ITEMS, TIMES_TO_RUN);
  std::cout << "MEMOIZED robust test that is " << wide << " DONE\n\n";
}


void test_cached_robust (bool isWide) {
  Dynamic_Solution dynamic;

  dynamic.setNumberOfItems(MIN_NUM_ITEMS);
  dynamic.setItemMinSize(MIN_ITEM_SIZE);
  dynamic.setItemMaxSize(MAX_ITEM_SIZE);
  dynamic.setOriginalBagSize(BAG_SIZE);
  dynamic.setDoubleGrowth(DOUBLE_GROWTH);
  dynamic.setResponsiveValues(RESPONSIVE_VALUES);
  dynamic.setIsWide(isWide);

  std::string wide = (isWide) ? "wide" : "not wide";

  std::cout << "CACHED test that is " << wide << " STARTED\n";
  dynamic.runForSizes(MIN_NUM_ITEMS, MAX_NUM_ITEMS, TIMES_TO_RUN);
  std::cout << "CACHED test that is " << wide << " DONE\n\n";
}




/*
  WEEK ONE:
  1) 
    Run First Problems from with 6 to 13 items

    Bag starts at size  =  1000
    item size           =  1 - 1000

    Problem Statment:
      For randomized data generate a graph that measures the average cpu time of the recur sive solution as a function 
      of n. Pick a fixed S as 1000 and assign the sizes of the objects from 1 to 1000 using a uniform random 
      distribution. Start at n=6 and go as large as you can within reasonable running times, increasing the 
      problem size by 1 each time. Produce a semi-log graph where n is the size of the problem (number of objects) 
      along the x axis and y is the average run time (log scale). If your code is running correctly your graph should 
      illustrate a near-straight line. Compute the slope of the line and explain the value you obtained.

  2)
    Run Second Problem with 64 to 150 items (increasing by 2 each time)
 
    Bag

      Here you will compare the run-time performance of the dynamic programming solution with the caching solution 
      under different random data distributions and much larger problem sizes. Given n is the problem size and m is 
      the capacity of the knapsack for each experiment set m= 10*n. In each experiment, generate the sizes of the n 
      objects need from a uniform random distribution between min-size and m/10. You will run the experiments under 
      two different distributions (a) wide where min-size is 1, and narrow where min-size is m/20. Start at size 64 
      and go as large as you can within reasonable running times, increasing the problem size by a factor of 2 each 
      time. Produce a log-log graph where x is the log of the size of the problem and y is the log of the average 
      running time. The graph should have two lines, one for wide and one for narrow.
*/

/*
  WEEK TWO:

*/