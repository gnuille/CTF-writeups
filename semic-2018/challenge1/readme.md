## Challenge 1
This challenge is an easy one.
In semic we like a lot number 7, obviusly we want to know the time
we consume for calculating if a number divides by 7 or not.

Our technique is the following;

Supose we have the number "34349":
  * Operation 1: Separe the 9 (3434,9) and we double it (18), then we have 3434-18=3416
  * Operation 2: We repeat the process separating the 6 (341, 6) we double it and substract 341-12=329
  * Operation 3: Another time 9\*2=18 so 32-18=14
  * Operation 4: We check if 14 is multiple of 7

So in this case as 14 is multiple of 7, 35459 is divided by 7.

But, we like the 7 a loot so when we find one we mark it and loose time doing it.

That happens us with the number: 1754753
  * Operation 1: 175475-6 = 175469 (We loose a second for the operation another for marking the 7)
  * Operation 2: 17546-18 = 17528 (We loose a second for the operation, another for marking the 7)
  * Operation 3: 1752-16 = 1736 (We loose a second for the operation, another for marking the 7)
  * Operation 4: 173-12 = 161 (We just loose a second for the operation)
  * Operation 5: 16-2=14 (We loose a second with the opertion)
  * Operation 6: We check if 14 is multiple of 7.

In this case it took **9 seconds** for the operation.

If the number is not divisible you also have to tell the time it took for the calculation.


Givien a range of numbers your program have to **calculate how many seconds it takes to make the calculation**
The file begins with a number **T**, number of cases, followed by **T** lines, each one contains an **N** integer.
Your program have to generate an output for each line with the following format "**Case #N: X**" where N is the case number and X the result.

**Limits**
  * 1 less or equal than N, N less or equal than 10.000.000

Example of input:
```
2
34249
1754753
```
Example of output:
```
Case #1: 4
Case #2: 9
```
