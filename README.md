# Knap Sack Problem CS 5050


## WEEK ONE:
#### FIRST 

##### Problem Statment:

For randomized data generate a graph that measures the average cpu time of the recur sive solution as a function of n. Pick a fixed S as 1000 and assign the sizes of the objects from 1 to 1000 using a uniform random distribution. Start at n=6 and go as large as you can within reasonable running times, increasing the problem size by 1 each time. Produce a semi-log graph where n is the size of the problem (number of objects) along the x axis and y is the average run time (log scale). If your code is running correctly your graph should illustrate a near-straight line. Compute the slope of the line and explain the value you obtained.

_Run First Problems from with 6 to 13 items_

_Bag starts at size  =  1000_
_item size           =  1 - 1000_


#### SECOND

##### Problem Statment:

Here you will compare the run-time performance of the dynamic programming solution with the caching solution under different random data distributions and much larger problem sizes. Given n is the problem size and m is the capacity of the knapsack for each experiment set m= 10*n. In each experiment, generate the sizes of the n objects need from a uniform random distribution between min-size and m/10. You will run the experiments under two different distributions (a) wide where min-size is 1, and narrow where min-size is m/20. Start at size 64 and go as large as you can within reasonable running times, increasing the problem size by a factor of 2 each time. Produce a log-log graph where x is the log of the size of the problem and y is the log of the average running time. The graph should have two lines, one for wide and one for narrow.

_Run Second Problem with 64 to 150 items (increasing by 2 each time)_

## WEEK TWO:


 * Implement the trace-back routine that takes the 2D cache array and returns an assignment of true or false to each object in the problem description, where true means the object is selected.


 * Implement the linear space knapsack algorithm to solve the same problem statement as Assignment 1.  Initially, the linear-space algorithm should divide the problem in to equal halves (so k is n/2).


 * For a set of small problem verify that the three algorithms (linear, standard DP and caching) produce the same answer.


 * Once you have verified that the code is running correctly perform the following empirical studies:

   * For randomized data generate a graph that measures the average cpu time of the linear-space solution as a function of the problem size. Given n is the problem size and m is the capacity of the knapsack for each experiment set m= 10*n. In each experiment, generate the sizes of the n objects need from a uniform random distribution between 1 and m/10 (the distribution does not matter since we are using DP). Start at size 64 and go as large as you can within reasonable running times, increasing the problem size by a factor of 2 each time. Produce a log-log graph where x is the log of the size of the problem and y is the log of the average running time. This first graph will have one line corresponding to the k=n/2 algorithm.

   * Now we will perform an experiment to measure how the cpu time is affected by the method used to split the problem into two sub- problems. Let k be the size of the first sub-problem and n-k be the size of the second. Repeat the experiment above but vary the split value k from the set: n/4, n/8, n/16, n/32 and 1. Produce a graph as above with 6 lines one for each experimental condition. You will find that under some experimental conditions, the run time increases significantly. In these cases limit the problem size n.

 * For each of the six data sets estimate the slope of the line by fitting a linear function to the point sequence log n, log t. Report these in a table.


 * Your graphs should be clearly captioned with the axis labeled. I recommend using gnuplot or some other professional quality graphing software. Whatever you use, you must have the correct log-log graph.


 * Write a brief (4-6 sentence) technical explanation of the behavior of the algorithms derived from the graphs.
