/*

 This is the abstract class for solving the knapsack problem
 
 It provides the book keeping for analysis on the specific algorithm
 
 Before running the algorithm (via runForSizes) at least the following setters must be set

    setNumberOfItems
    setItemMaxSize
    setOriginalBagSize

 The call structure is:

runForSizes
    solveAverage
        solveTime
            resetItems
                getVectorOfInts
                    getRandomInt
                getVectorOfDoubles
                    getRandomDouble
                solve
        averages

 Each algorithm can create it's own class that inherits this class and overwrite the solve function.
*/

#ifndef ABSTRACT_SOLUTION_H
#define ABSTRACT_SOLUTION_H
#include <random>
#include <numeric>
#include <algorithm>
#include <vector>
#include <math.h>
#include <utility>
#include <random>
#include <iostream>
#include <chrono>


class Abstract_Solution {
public:
  
  // constructors
  Abstract_Solution ()
    : numberOfItems(0)
    , itemMinSize(0)
    , itemMaxSize(0)
    , originalBagSize(0)
    , doubleGrowth(false)
    , responsiveValues(false)
    , isWide(false)
  {}

  // Function that actually runs the algorithm tests
  std::vector<double> runForSizes (int minItemCount, int maxItemCount, int timesRun);
  double check_results (void);

  // setters
  void setNumberOfItems    (int numberOfItems)     { this->numberOfItems    = numberOfItems;     }
  void setItemMinSize      (int itemMinSize)       { this->itemMinSize      = itemMinSize;       }
  void setItemMaxSize      (int itemMaxSize)       { this->itemMaxSize      = itemMaxSize;       }
  void setOriginalBagSize  (int originalBagSize)   { this->originalBagSize  = originalBagSize;   }
  void setDoubleGrowth     (bool doubleGrowth)     { this->doubleGrowth     = doubleGrowth;      }
  void setResponsiveValues (bool responsiveValues) { this->responsiveValues = responsiveValues;  }
  void setIsWide           (bool isWide)           { this->isWide           = isWide;            }

protected:
  // worker functions
  double solveAverage (int timesRun);
  double solveTime ();

  // actual algoritnm to be overwriten by child class
  virtual double solve (int item, int currentBagSize, double currentBagValue) = 0;

  // helper tag along functions
  int getRandomInt (int small, int big);
  std::vector<int> getVectorOfInts (int size, int min, int max);
  double getRandomDouble (double small, double big);
  std::vector<double> getVectorOfDoubles (int size, int min, int max);
  template <typename InputIterator>
    double average (InputIterator);
  void resetItems ();

  // Needed Values
  int numberOfItems;
  int itemMinSize;
  int itemMaxSize;
  int originalBagSize;
  bool doubleGrowth; // rate of growth for number of objects (if set true items will double.)
  bool responsiveValues;
  bool isWide;
  std::vector<int> itemSizes;
  std::vector<double> itemValues;
  std::vector<std::vector<bool>> seen;
  std::vector<std::vector<double>> bagValues;
};


#endif