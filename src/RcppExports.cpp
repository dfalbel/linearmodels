// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// cpp_LinearRegression_create
SEXP cpp_LinearRegression_create();
RcppExport SEXP _linearmodels_cpp_LinearRegression_create() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_LinearRegression_create());
    return rcpp_result_gen;
END_RCPP
}
// cpp_LinearRegression_fit
void cpp_LinearRegression_fit(SEXP ptr, const arma::mat& x, const arma::mat& y);
RcppExport SEXP _linearmodels_cpp_LinearRegression_fit(SEXP ptrSEXP, SEXP xSEXP, SEXP ySEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ptr(ptrSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type y(ySEXP);
    cpp_LinearRegression_fit(ptr, x, y);
    return R_NilValue;
END_RCPP
}
// cpp_LinearRegression_predict
arma::colvec cpp_LinearRegression_predict(SEXP ptr, const arma::mat& x);
RcppExport SEXP _linearmodels_cpp_LinearRegression_predict(SEXP ptrSEXP, SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ptr(ptrSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_LinearRegression_predict(ptr, x));
    return rcpp_result_gen;
END_RCPP
}
// cpp_LinearRegression_getCoef
arma::colvec cpp_LinearRegression_getCoef(SEXP ptr);
RcppExport SEXP _linearmodels_cpp_LinearRegression_getCoef(SEXP ptrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ptr(ptrSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_LinearRegression_getCoef(ptr));
    return rcpp_result_gen;
END_RCPP
}
// cpp_LinearRegression_setCoef
void cpp_LinearRegression_setCoef(SEXP ptr, const arma::colvec& coef);
RcppExport SEXP _linearmodels_cpp_LinearRegression_setCoef(SEXP ptrSEXP, SEXP coefSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ptr(ptrSEXP);
    Rcpp::traits::input_parameter< const arma::colvec& >::type coef(coefSEXP);
    cpp_LinearRegression_setCoef(ptr, coef);
    return R_NilValue;
END_RCPP
}
// cpp_LinearRegression_getFitted
bool cpp_LinearRegression_getFitted(SEXP ptr);
RcppExport SEXP _linearmodels_cpp_LinearRegression_getFitted(SEXP ptrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ptr(ptrSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_LinearRegression_getFitted(ptr));
    return rcpp_result_gen;
END_RCPP
}
// cpp_LinearRegression_setFitted
void cpp_LinearRegression_setFitted(SEXP ptr, const bool& x);
RcppExport SEXP _linearmodels_cpp_LinearRegression_setFitted(SEXP ptrSEXP, SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ptr(ptrSEXP);
    Rcpp::traits::input_parameter< const bool& >::type x(xSEXP);
    cpp_LinearRegression_setFitted(ptr, x);
    return R_NilValue;
END_RCPP
}
// isnull_pointer
bool isnull_pointer(SEXP ptr);
RcppExport SEXP _linearmodels_isnull_pointer(SEXP ptrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ptr(ptrSEXP);
    rcpp_result_gen = Rcpp::wrap(isnull_pointer(ptr));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_linearmodels_cpp_LinearRegression_create", (DL_FUNC) &_linearmodels_cpp_LinearRegression_create, 0},
    {"_linearmodels_cpp_LinearRegression_fit", (DL_FUNC) &_linearmodels_cpp_LinearRegression_fit, 3},
    {"_linearmodels_cpp_LinearRegression_predict", (DL_FUNC) &_linearmodels_cpp_LinearRegression_predict, 2},
    {"_linearmodels_cpp_LinearRegression_getCoef", (DL_FUNC) &_linearmodels_cpp_LinearRegression_getCoef, 1},
    {"_linearmodels_cpp_LinearRegression_setCoef", (DL_FUNC) &_linearmodels_cpp_LinearRegression_setCoef, 2},
    {"_linearmodels_cpp_LinearRegression_getFitted", (DL_FUNC) &_linearmodels_cpp_LinearRegression_getFitted, 1},
    {"_linearmodels_cpp_LinearRegression_setFitted", (DL_FUNC) &_linearmodels_cpp_LinearRegression_setFitted, 2},
    {"_linearmodels_isnull_pointer", (DL_FUNC) &_linearmodels_isnull_pointer, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_linearmodels(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
