//
//  main.cpp
//  knap_sack
//
//  Created by Fred Christensen on 1/18/14.
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
void test_algorithms_find_same_solution ();

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
  // test_recursive  ();
  // test_memoized ();
  // test_cached ();
  // test_memoized_robust (IS_WIDE);
  // test_cached_robust (IS_WIDE);
  test_algorithms_find_same_solution();


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

void test_algorithms_find_same_solution () {
  Recursive_Solution recursive;
  Memoized_Solution memoized;
  Dynamic_Solution dynamic;
  // Liniar_Space_Solution liniar;

  double recursiveRes = recursive.checkResults();
  std::cout << "recursive results = " << recursiveRes << std::endl;
  double memoizedRes = memoized.checkResults();
  std::cout << "memoized results = " << memoizedRes << std::endl;
  double dynamicRes = dynamic.checkResults();
  std::cout << "dynamic results = " << dynamicRes << std::endl;
  // double liniarRes = liniar.checkResults();
  // std::cout << "liniar results = " << liniarRes << std::endl;
}

