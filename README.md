# RcppHungarian

<!-- badges: start -->
[![Travis build status](https://travis-ci.org/jsilve24/RcppHungarian.svg?branch=master)](https://travis-ci.org/jsilve24/RcppHungarian)
[![Codecov test coverage](https://codecov.io/gh/jsilve24/RcppHungarian/branch/master/graph/badge.svg)](https://codecov.io/gh/jsilve24/RcppHungarian?branch=master)
<!-- badges: end -->

RcppHungarian provides both C++ Headers and R wrappers for the 
Hungarian Algorithm (aka Huhn-Munkres algorithm) for solving minimum cost bipartite matching problems.
Borrows heavily from code written by Cong Ma in the GitHub repo mcximing/hungarian-algorithm-cpp.

## Installation

CRAN install coming soon. For the moment:

``` r
devtools::install_github("jsilve24/RcppHungarian")
```

## Example

A simple example, of the function usage below. 
Please see the Vignette for more detailed overview and examples. 

``` r
library(RcppHungarian)
cost.of.matchings <- rbind(c(0,1,2,3),
                           c(4,2,1,0), 
                           c(9, 1, 0, 5))
HungarianSolver(cost.of.matchings)

#> $cost
#> [1] 0
#> 
#> $pairs
#>      [,1] [,2]
#> [1,]    1    1
#> [2,]    2    4
#> [3,]    3    3
```

