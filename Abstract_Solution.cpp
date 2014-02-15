//
//  Solve_Abasract.cpp
//  knap_sack
//
//  Created by Fred Christensen on 1/18/14.
//


#include "Abstract_Solution.h"


  // ---------- Finds averages for this problem with the given item counts ------------
std::vector<double> Abstract_Solution::runForSizes (int minItemCount, int maxItemCount, int timesRun) {
  std::vector<double> results;
  // +1 to keep the result on the index of the number of items
  results.resize(maxItemCount + 1, -1);
  for (int i = minItemCount; i <= maxItemCount; (this->doubleGrowth) ? i *= 2 : ++i) {
    setNumberOfItems(i);
    results[i] = this->solveAverage(timesRun);
    std::cout << i << " items took " << results[i] << std::endl;
  }
  return results;
}

double Abstract_Solution::checkResults (void) {
  this->numberOfItems = 5;
  this->originalBagSize = 100;

  static const int sizes[]     = {0,   25,   50,   30,   20,  25  };
  static const double values[] = {0.0, 11.3, 25.3, 22.4, 5.2, 13.4};

  std::vector<int> sizes_vec  (sizes, sizes + sizeof(sizes) / sizeof(sizes[0]) );
  std::vector<double> values_vec (values, values + sizeof(values) / sizeof(values[0]) );

  this->itemSizes =  sizes_vec;
  this->itemValues = values_vec;

  seen.clear();
  seen.resize( this->numberOfItems + 1, std::vector<bool>( this->originalBagSize + 1, false ) );

  bagValues.clear();
  bagValues.resize( this->numberOfItems + 1, std::vector<double>( this->originalBagSize + 1, 0 ) );
  return this->solve(1, 100, 0);
}



std::vector<bool> Abstract_Solution::getUsedItems () {
  std::vector<bool> itemsUsed(this->numberOfItems +1, false);
  double curSize = this->originalBagSize;

  for (int curItem = numberOfItems; curItem > 0; --curItem) {
    if (this->bagValues[curItem][curSize] != this->bagValues[curItem -1][curSize]) {
      itemsUsed[curItem -1] = true;
      curSize -= this->itemSizes[curItem];
    }
  }

  return itemsUsed;
}



  // ---------- Average Solve Time ------------
double Abstract_Solution::solveAverage (int timesRun) {
  std::vector<double> container;
  container.resize(timesRun);

  std::generate (container.begin(), container.end(), [&] () {
    return this->solveTime();
  });

  return this->average(container);
}

  // ---------- Solve Time ------------
double Abstract_Solution::solveTime () {
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
void Abstract_Solution::resetItems () {
  if (this->responsiveValues) {
    this->originalBagSize = this->numberOfItems * 10;
    this->itemMaxSize = this->originalBagSize / 10;
    if (this->isWide) {
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
int Abstract_Solution::getRandomInt (int small, int big) {
  std::random_device rd;
  std::uniform_int_distribution<int> dist(small, big);
  return dist(rd);
};

  // ------- Returns Vector Of Random Ints (index 0 == 0 and 1 == the first item) -----------
std::vector<int> Abstract_Solution::getVectorOfInts (int size, int min, int max) {
  std::vector<int> vec(size, getRandomDouble(min, max));
  vec.insert(vec.begin(), 0);
  return vec;
}

  // ------- Returns Random Double -----------
double Abstract_Solution::getRandomDouble (double small, double big) {
  std::random_device rd;
  std::uniform_real_distribution<double> gen(small, big);
  return gen(rd);
};

  // ------- Returns a Vector of random Doubles (index 0 == 0 and 1 == the first item) -----------
std::vector<double> Abstract_Solution::getVectorOfDoubles (int size, int min, int max) {
  std::vector<double> vec;
  vec.resize(size, getRandomDouble((double)min, (double)max));
  vec.insert(vec.begin(), 0.0);
  return vec;
}

  // ------- Average Vector Value -----------
template <typename InputIterator>
double Abstract_Solution::average (InputIterator container) {
  double total = (double)std::accumulate(container.begin(),container.end(),0);
  return total/((double)container.size());
}
