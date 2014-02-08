//
//  Solve_Abasract.cpp
//  knap_sack
//
//  Created by Fred Christensen on 1/18/14.
//  Copyright (c) 2014 Fred Christensen. All rights reserved.
//


#include "Abstract_Solution.h"


  // ---------- Finds averages for this problem with the given item counts ------------
std::vector<double> Abstract_Solution::runForSizes (int minItemCount, int maxItemCount, int timesRun)
{
  std::vector<double> results;
  // +1 to keep the result on the index of the number of items
  results.resize(maxItemCount + 1, -1);
  for (int i = minItemCount; i <= maxItemCount; (this->doubleGrowth) ? i *= 2 : ++i)
  {
    setNumberOfItems(i);
    results[i] = this->solveAverage(timesRun);
    std::cout << i << " items: " << results[i] << std::endl;
  }
  return results;
}

  // ---------- Average Solve Time ------------
double Abstract_Solution::solveAverage (int timesRun)
{
  std::vector<double> container;
  container.resize(timesRun);

  std::generate (container.begin(), container.end(), [&] () {
    return this->solveTime();
  });

  return this->average(container);
}

  // ---------- Solve Time ------------
double Abstract_Solution::solveTime ()
{
  // check the setters were called
  if (this->numberOfItems == 0 || this->itemMaxSize == 0 || this->originalBagSize == 0) return 0;

  this->resetItems();
  auto start = std::chrono::system_clock::now();
  solve(1, this->originalBagSize, 0); // Initial item is 1 and inital bagSize is 0
  auto stop = std::chrono::system_clock::now();
  return (double)std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
}

  // ----------- Creates New Item Vectors and clears seen and bagValues vectors ---------------
  // ----------- seen and bagValues vectors have index [0][0] == 0 and [1][1] == the first item ---------------
void Abstract_Solution::resetItems ()
{
  if (this->responsiveValues)
  {
    this->originalBagSize = this->numberOfItems * 10;
    this->itemMaxSize = this->originalBagSize / 10;
    if (this->isWide)
    {
      this->itemMinSize = 1;
    } else {
      this->itemMinSize = this->originalBagSize/20;
    }
  }
  
  itemSizes = this->getVectorOfInts(this->numberOfItems, this->itemMinSize, this->itemMaxSize);
  itemValues = this->getVectorOfDoubles(this->numberOfItems, 10, 150);
  
  // clearn out and resize book keeping variables
  seen.clear();
  seen.resize( this->numberOfItems + 1, std::vector<bool>( this->originalBagSize + 1, false ) );

  bagValues.clear();
  bagValues.resize( this->numberOfItems + 1, std::vector<double>( this->originalBagSize + 1, 0 ) );
}

  // ------- Returns A Random Int -----------
int Abstract_Solution::getRandomInt (int small, int big)
{
  std::random_device rd;
  std::uniform_int_distribution<int> dist(small, big);
  return dist(rd);
};

  // ------- Returns Vector Of Random Ints (index 0 == 0 and 1 == the first item) -----------
std::vector<int> Abstract_Solution::getVectorOfInts (int size, int min, int max)
{
  std::vector<int> vec(size, getRandomDouble(min, max));
  vec.insert(vec.begin(), 0);
  return vec;
}

  // ------- Returns Random Double -----------
double Abstract_Solution::getRandomDouble (int small, int big)
{
  std::random_device rd;
    // left and right are in reference to the decimal place
  std::uniform_int_distribution<int> left(small, big - 1);
  std::uniform_int_distribution<int> right(0, 99);
  int whole = left(rd);
  int decimal = right(rd);
  double number = (double)whole + ((double)decimal / 100);
  return number;
};

  // ------- Returns a Vector of random Doubles (index 0 == 0 and 1 == the first item) -----------
std::vector<double> Abstract_Solution::getVectorOfDoubles (int size, int min, int max)
{
  std::vector<double> vec;
  vec.resize(size, getRandomDouble(min, max));
  vec.insert(vec.begin(), 0.0);
  return vec;
}

  // ------- Average Vector Value -----------
template <typename InputIterator>
double Abstract_Solution::average (InputIterator container)
{
  double total = (double)std::accumulate(container.begin(),container.end(),0);
  return total/((double)container.size());
}
