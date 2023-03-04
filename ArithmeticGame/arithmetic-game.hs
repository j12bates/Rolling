-- Vedis Arithmetic Game Analysis Thingy
-- You're given a set of numbers with repetition. Use arithmetic with
-- bracketing to come up with a particular target number. We use 21, but
-- occasionally we come across a set for which there is no solution.

-- Here is a thingy which can compute all possible results given a set
-- with repetition. By enumerating all possible sets, I can find all the
-- sets for which there is a solution. In addition, I could do some
-- analysis to figure out what numbers work best as a target result, in
-- the sense that they have a solution for the most sets.

-- Also, one fun thing is to figure out what sets of numbers cannot be
-- solved when the target is zero. There are only 10 (of 715) possible
-- sets of 4 values 0-9 where a target of zero cannot be reached.

-- Maybe later I could also have it just store the solutions with the
-- results. That way maybe I could just memorize them all and be so much
-- better at wenning the game than hem. There's no way he'd be able to
-- program something this advanced.

import Data.List
import Data.Map (toList, fromListWith)

-- ====== MAIN PROGRAM ======

-- The program takes in a set of integers in the form of a list, and
-- outputs the list of all possible results by rearrangement,
-- bracketing, and arithmetic operations. Order does not matter.

-- This works essentially by means of two functions. One of them is the
-- primary function, called `setOpResults`, which will take in the
-- actual input and give the proper output. The second is a helper
-- function called `opResults` which enumerates all possible operations
-- on the first pair of a list, and returns sets (with the pair replaced
-- with the result) to the main function. This continues until the set
-- is a mere pair, at which point the helper function will return final
-- results, which the main function compiles into a sorted list.

-- setOpResults
-- results of all possible operations on a set
-- helper function operates on the first pair, so this enumerates all possible first pairs
-- takes in new sets created by helper function
setOpResults :: [Int] -> [Int]
setOpResults xs = uq (concat (map opResults (uniqueFirstPairs (permutations xs))))

-- opResults
-- [HELPER FUNCTION]
-- performs all possible operations on the first pair of integers in a list
-- turns over new sets for further computation
-- returns answers if no numbers remain
opResults :: [Int] -> [Int]

-- trivial ones
opResults []        = []
opResults [x]       = [x]

-- all possible operations on a pair
opResults [x, y]    = uq ((x + y)
                        : (x - y)
                        : (y - x)       -- not commutative, we're only changing pair composition, not order
                        : (x * y)
                        : safeDiv x y
                        : safeDiv y x   -- same here
                        -- here you might add additional operations you like
                        : [])

-- do all possible operations on the first pair; now we have a new set to evaluate
opResults (x:y:xs)  = uq (concat (map setOpResults [n:xs | n <- opResults [x, y]] ))


-- ====== OTHER FUNCTIONS ======

-- uq
-- get rid of duplicate items in a list, and also quicksort
uq :: Ord a => [a] -> [a]
uq []       = []
uq (x:xs)   = uq lt ++ [x] ++ uq gt
                where   lt = [n | n <- xs, n < x]
                        gt = [n | n <- xs, n > x]

-- freq
-- get frequency of all list elements
freq :: (Ord a) => [a] -> [(a, Int)]
freq xs = toList (fromListWith (+) [(x, 1) | x <- xs])

-- freq'
-- sort list elements by frequency
freq' :: (Ord a) => [a] -> [(Int, a)]
freq' xs    = uq [(n, x) | (x, n) <- freq xs]

-- nope
-- if a list does not have a particular value
nope :: Eq a => a -> [a] -> Bool
nope _ []       = True
nope n (x:xs)   = if x == n then False else nope n xs

-- safeDiv
-- return x / y if result is whole, otherwise duplicate, no divide by zero error
safeDiv :: Int -> Int -> Int
safeDiv x y | y == 0            = x + y
            | x `mod` y /= 0    = x + y
            | otherwise         = x `div` y

-- firstPairsMatch
-- do the first pairs of two lists differ
firstPairsDiffer :: Eq a => [a] -> [a] -> Bool
firstPairsDiffer xs ys   = (take 2 xs) /= (take 2 ys) && (reverse (take 2 xs)) /= (take 2 ys)

-- allFirstPairs
-- gets rid of lists which have the same first pair as earlier ones
uniqueFirstPairs :: Eq a => [[a]] -> [[a]]
uniqueFirstPairs []         = []
uniqueFirstPairs (xs:xss)   = xs:(uniqueFirstPairs (filter (firstPairsDiffer xs) xss))

-- allSets
-- generate all possible sets with repetition of length and max value (1--6)
allSets :: Int -> Int -> [[Int]]
allSets n 1 = [[a] | a <- [0..n]]
allSets n 2 = [[a, b] | a <- [0..n], b <- [a..n]]
allSets n 3 = [[a, b, c] | a <- [0..n], b <- [a..n], c <- [b..n]]
allSets n 4 = [[a, b, c, d] | a <- [0..n], b <- [a..n], c <- [b..n], d <- [c..n]]
allSets n 5 = [[a, b, c, d, e] | a <- [0..n], b <- [a..n], c <- [b..n], d <- [c..n], e <- [d..n]]
allSets n 6 = [[a, b, c, d, e, f] | a <- [0..n], b <- [a..n], c <- [b..n], d <- [c..n], e <- [d..n], f <- [e..n]]

-- examples (4 values 0-9):

-- calculate the total number of possible sets:
--      length (allSets 9 4)

-- calculate the frequency of each result:
--      freq (concat (map setOpResults (allSets 9 4)))

-- same thing, but sort by frequency
--      freq' (concat (map setOpResults (allSets 9 4)))

-- find the sets for which 21 can be computed:
--      [set | set <- (allSets 9 4), not (nope 21 (setOpResults set))]

-- find the sets for which 0 cannot be computed:
--      [set | set <- (allSets 9 4), nope 0 (setOpResults set)]
