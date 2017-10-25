#include "RcppArmadillo.h"
using namespace Rcpp;

// RidgeRegression Class Declaration!
class RidgeRegression {

private:

  arma::colvec coef;
  double lambda;
  bool fitted;

public:

  RidgeRegression(double lambda, bool fitted = false);
  void fit (const arma::mat & x, const arma::colvec & y);
  arma::colvec predict (const arma::mat & x);

  arma::colvec getCoef ();
  void setCoef (const arma::colvec & x);

  bool getFitted ();
  void setFitted (const bool & x);

  void setLambda (const double & x);

};

// Constructor
RidgeRegression::RidgeRegression(double lambda, bool fitted) {
  this->lambda = lambda;
  this->fitted = fitted;
};

// Fitting function
void RidgeRegression::fit(const arma::mat & x, const arma::colvec & y) {
  arma::mat identity = arma::eye(x.n_cols, x.n_cols);
  arma::mat term1 = arma::inv(x.t() * x + this->lambda*identity);
  this->coef = term1*x.t()*y;
};

// Prediction using the model
arma::colvec RidgeRegression::predict (const arma::mat & x) {
  return x*this->coef;
};

arma::colvec RidgeRegression::getCoef () {
  return this->coef;
};

void RidgeRegression::setCoef (const arma::colvec & x) {
  this->coef = x;
};

bool RidgeRegression::getFitted(){
  return this->fitted;
};

void RidgeRegression::setFitted(const bool & x){
  this->fitted = x;
};

void RidgeRegression::setLambda (const double & x) {
  this->lambda = x;
};

// Boilerplate code to use R6 classes to manage objects.
// This seems better then using RcppModules.

// [[Rcpp::export]]
SEXP cpp_RidgeRegression_create(double lambda) {
  RidgeRegression *obj = new RidgeRegression(lambda);
  XPtr<RidgeRegression> ptr(obj, true);
  return ptr;
};

// [[Rcpp::export]]
void cpp_RidgeRegression_fit(SEXP ptr, const arma::mat & x, const arma::mat & y) {
  Rcpp::XPtr<RidgeRegression> obj(ptr);
  obj->fit(x, y);
};

// [[Rcpp::export]]
arma::colvec cpp_RidgeRegression_predict(SEXP ptr, const arma::mat & x) {
  Rcpp::XPtr<RidgeRegression> obj(ptr);
  return obj->predict(x);
};

// [[Rcpp::export]]
arma::colvec cpp_RidgeRegression_getCoef(SEXP ptr) {
  Rcpp::XPtr<RidgeRegression> obj(ptr);
  return obj->getCoef();
}

// [[Rcpp::export]]
void cpp_RidgeRegression_setCoef(SEXP ptr, const arma::colvec & coef) {
  Rcpp::XPtr<RidgeRegression> obj(ptr);
  obj->setCoef(coef);
}

// [[Rcpp::export]]
bool cpp_RidgeRegression_getFitted (SEXP ptr) {
  Rcpp::XPtr<RidgeRegression> obj(ptr);
  return obj->getFitted();
}

// [[Rcpp::export]]
void cpp_RidgeRegression_setFitted (SEXP ptr, const bool & x) {
  Rcpp::XPtr<RidgeRegression> obj(ptr);
  obj->setFitted(x);
}

// [[Rcpp::export]]
void cpp_RidgeRegression_setLambda (SEXP ptr, const double & x) {
  Rcpp::XPtr<RidgeRegression> obj(ptr);
  obj->setLambda(x);
}

