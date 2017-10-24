#' LinearRegression
#' @export
#' @rdname LinearRegression
#'
#' @examples
#'
#' library(linearmodels)
#'
#' x <- matrix(runif(100), ncol = 2)
#' y <- matrix(2*x[,1] + 3*x[, 2] + rnorm(50), ncol = 1)
#'
#' linear_regression <- LinearRegression$new()
#' linear_regression$fit(x, y)
#' linear_regression$getCoef()
#' linear_regression$predict(x)


LinearRegression <- R6::R6Class(
  "LinearR egression",

  public = list(

    initialize = function(){
      private$ptr <- cpp_LinearRegression_create()
    },

    fit = function (x, y) {
      cpp_LinearRegression_fit(private$ptr, x, y)
    },

    predict = function (x) {
      cpp_LinearRegression_predict(private$ptr, x)
    },

    getCoef = function () {
      cpp_LinearRegression_getCoef(private$ptr)
    }

  ),

  private = list(
    ptr = NULL
  )
)
