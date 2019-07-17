#include <Rcpp.h>
#include "RcppHungarian.h"
#include <iostream>

using namespace Rcpp;

//' Hungarian Algorithm Solver
//' 
//' Solves weighted bipartite matching problems (e.g., optimal matching of people to cars
//' or optimal matching of students to colleges, etc...)
//' 
//' @param costMatrix matrix giving cost of each possible pairing - can be rectangular
//' @return List with cost and parings, pairings are given as an Nx2 matrix 
//' giving edges that are matched (1-indexed rather than 0-indexed as it will be returned to R)
//' @export
//' @details this is a copy/wrapper for the code developed by Cong Ma and made available
//' as a github repository (mcximing/hungarian-algorithm-cpp). Code was 
//' changed to a header only file for use in other Rcpp packages. 
//' @examples
//' cost <- rbind(c(1, 2, 0), 
//'               c(2, 0, 1), 
//'               c(1, 4, 19))
//' soln <- HungarianSolver(cost)
//' soln                
// [[Rcpp::export]]
List HungarianSolver(NumericMatrix costMatrix) {
  int nr = costMatrix.nrow();
  int nc = costMatrix.ncol();
  
  vector<double> c(nc);
  vector<vector<double>> cm(nr, c);
  for (int i=0; i < nr; i++){
    for (int j=0; j < nc; j++){
      c[j] = costMatrix(i,j);
    }
    cm[i] = c;
  }
  
  HungarianAlgorithm HungAlgo;
  vector<int> assignment;
  double cost = HungAlgo.Solve(cm, assignment);
  IntegerMatrix assign(nr, 2);
  for (int i=0; i < nr; i++){
    assign(i,0) = i+1;
    assign(i,1) = assignment[i]+1;
  }
  List out(2);
  out[0] = cost;
  out[1] = assign;
  out.names() = CharacterVector::create("cost", "pairs");
  return out;
}


