import System.Environment

-- Just a main function for no reason
main :: IO ()
main = do
    args <- getArgs
    putStrLn $ show args

-- All individual values in a list, sorted
uq :: (Ord a) => [a] -> [a]
uq []       = []
uq (x:xs)   = uq lt ++ [x] ++ uq gt
    where   lt  = [x' | x' <- xs, x' < x]
            gt  = [x' | x' <- xs, x' > x]

-- All the operations you could perform
enumOps :: [Int] -> Int -> [Int]
enumOps xs n    = uq $ xs ++ sums ++ diffs ++ prods ++ quots
    where   sums    =  [n + x | x <- xs]
            diffs   =  [n - x | x <- xs, n > x]
                    ++ [x - n | x <- xs, x > n]
            prods   =  [n * x | x <- xs]
            quots   =  [n `div` x | x <- xs, n `mod` x == 0]
                    ++ [x `div` n | x <- xs, x `mod` n == 0]
