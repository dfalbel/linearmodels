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
#' linear_regression$predict(x)


LinearRegression <- R6::R6Class(
  "LinearRegression",

  public = list(

    initialize = function(){
      private$ptr_ <- cpp_LinearRegression_create()
    },

    fit = function (x, y) {
      cpp_LinearRegression_fit(self$ptr, x, y)
      private$coef <- cpp_LinearRegression_getCoef(self$ptr)
      private$fitted <- cpp_LinearRegression_getFitted(self$ptr)
    },

    predict = function (x) {
      cpp_LinearRegression_predict(self$ptr, x)
    }

  ),

  active = list(
    ptr = function(){

      if(is_null_externalptr(private$ptr_)) {
        private$ptr_ <- cpp_LinearRegression_create()

        if(private$fitted) {
          cpp_LinearRegression_setCoef(private$ptr_, private$coef)
          cpp_LinearRegression_setFitted(private$ptr_, private$fitted)
        }

      }

      private$ptr_
    }
  ),

  private = list(
    ptr_ = NULL,
    coef = NULL,
    fitted = FALSE
  )
)

is_null_externalptr <- function(x) {
  identical(x, new("externalptr"))
}
