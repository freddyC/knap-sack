knap-sack
=========

# WEEK ONE:
### FIRST 

#### Problem Statment:

For randomized data generate a graph that measures the average cpu time of the recur sive solution as a function of n. Pick a fixed S as 1000 and assign the sizes of the objects from 1 to 1000 using a uniform random distribution. Start at n=6 and go as large as you can within reasonable running times, increasing the problem size by 1 each time. Produce a semi-log graph where n is the size of the problem (number of objects) along the x axis and y is the average run time (log scale). If your code is running correctly your graph should illustrate a near-straight line. Compute the slope of the line and explain the value you obtained.

_Run First Problems from with 6 to 13 items_

_Bag starts at size  =  1000_
_item size           =  1 - 1000_


### SECOND

#### Problem Statment:

Here you will compare the run-time performance of the dynamic programming solution with the caching solution under different random data distributions and much larger problem sizes. Given n is the problem size and m is the capacity of the knapsack for each experiment set m= 10*n. In each experiment, generate the sizes of the n objects need from a uniform random distribution between min-size and m/10. You will run the experiments under two different distributions (a) wide where min-size is 1, and narrow where min-size is m/20. Start at size 64 and go as large as you can within reasonable running times, increasing the problem size by a factor of 2 each time. Produce a log-log graph where x is the log of the size of the problem and y is the log of the average running time. The graph should have two lines, one for wide and one for narrow.

_Run Second Problem with 64 to 150 items (increasing by 2 each time)_
