
test_that("Algorithm Correctness Simple", {
  cost <- matrix(1, 2,2)
  diag(cost) <- 0
  soln <- RcppHungarian::HungarianSolver(cost)
  
  expect_equal(soln$cost,0)
  expect_equal(soln$assignments, matrix(c(0,0,1,1), 2,2, byrow = TRUE))
})


test_that("Algorithm Correctness Difficult", {
  cost <- rbind(c(1, 2, 0), 
                c(2, 0, 1), 
                c(1, 4, 19))
  soln <- HungarianSolver(cost)
  
  expect_equal(soln$cost,1)
  expect_equal(soln$assignments, rbind(c(0, 2), 
                                       c(1, 1), 
                                       c(2, 0)))
})


test_that("Algorithm Correctness Degenerate", {
  cost <- matrix(1, 2,2)
  soln <- HungarianSolver(cost)
  
  expect_equal(soln$cost,0)
  expect_equal(soln$assignments, matrix(c(0,0,1,1), 2,2, byrow = TRUE))
})