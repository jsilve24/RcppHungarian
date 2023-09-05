# RcppHungarian

<!-- badges: start -->
[![License](http://img.shields.io/badge/license-GPL%20%28%3E=%202%29-brightgreen.svg?style=flat)](http://www.gnu.org/licenses/gpl-2.0.html) 
[![CRAN](http://www.r-pkg.org/badges/version/RcppHungarian)](https://cran.r-project.org/package=RcppHungarian) 
<!-- badges: end -->

Header Library and R Functions to Solve Minimum Cost Bipartite Matching Problem using Huhn-Munkres algorithm (Hungarian algorithm; https://en.wikipedia.org/wiki/Hungarian_algorithm; Kuhn (1955) doi:10.1002/nav.3800020109).This is a repackaging of code written by Cong Ma in the GitHub repo https://github.com/mcximing/hungarian-algorithm-cpp.

## Installation

You can install the released version of RcppHungarian from [CRAN](https://CRAN.R-project.org) with:

``` r
install.packages("RcppHungarian")
```

Or the GitHub Version with:
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

