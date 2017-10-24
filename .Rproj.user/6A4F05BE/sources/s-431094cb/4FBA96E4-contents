#include "RcppArmadillo.h"
using namespace Rcpp;

// Linear Regression Class Declaration
class LinearRegression {

private:

  arma::colvec coef;
  bool fitted;

public:

  LinearRegression(bool fitted = false);
  void fit (const arma::mat & x, const arma::colvec & y);
  arma::colvec predict (const arma::mat & x);
  arma::colvec getCoef ();

};

// Class constructor
// only initializes the fitted member with false
LinearRegression::LinearRegression(bool fitted) {
  this->fitted = fitted;
};

// Fit the linear regression model
// modifies the coef member.
void LinearRegression::fit (const arma::mat & x, const arma::colvec & y) {
  this->coef = arma::solve(x, y);
  this->fitted = true;
};

// Make predictions with the model
arma::colvec LinearRegression::predict(const arma::mat & x) {
  return x*getCoef();
};

// Get coefficients of the model
arma::colvec LinearRegression::getCoef () {
  if(this->fitted){
    return this->coef;
  } else {
    Rcpp::stop("Fit LinearRegression before getCoef.");
  }
};


// Boilerplate code to use R6 classes to manage objects.
// This seems better then using RcppModules.

// [[Rcpp::export]]
SEXP cpp_LinearRegression_create() {
  LinearRegression *obj = new LinearRegression();
  XPtr<LinearRegression> ptr(obj, true);
  return ptr;
}

// [[Rcpp::export]]
void cpp_LinearRegression_fit(SEXP ptr, const arma::mat & x, const arma::mat & y) {
  Rcpp::XPtr<LinearRegression> obj(ptr);
  obj->fit(x, y);
}

// [[Rcpp::export]]
arma::colvec cpp_LinearRegression_predict(SEXP ptr, const arma::mat & x) {
  Rcpp::XPtr<LinearRegression> obj(ptr);
  return obj->predict(x);
}

// [[Rcpp::export]]
arma::colvec cpp_LinearRegression_getCoef(SEXP ptr) {
  Rcpp::XPtr<LinearRegression> obj(ptr);
  return obj->getCoef();
}


