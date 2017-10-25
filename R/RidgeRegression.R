#' RidgeRegression
#' @export
#' @rdname RidgeRegression
#'
#' @examples
#'
#' library(linearmodels)
#'
#' x <- matrix(runif(100), ncol = 2)
#' y <- matrix(2*x[,1] + 3*x[, 2] + rnorm(50), ncol = 1)
#'
#' ridge_regression <- RidgeRegression$new(lambda = 0.1)
#' ridge_regression$fit(x, y)
#' ridge_regression$predict(x)

RidgeRegression <- R6::R6Class(
  "RidgeRegression",

  public = list(

    initialize = function(lambda = 0.5) {
      private$ptr_ <- cpp_RidgeRegression_create(lambda)
      private$lambda <- lambda
    },

    fit = function(x, y) {
      cpp_RidgeRegression_fit(self$ptr, x, y)
      private$coef <- cpp_RidgeRegression_getCoef(self$ptr)
      private$fitted <- cpp_RidgeRegression_getFitted(self$ptr)
    },

    predict = function(x) {
      cpp_RidgeRegression_predict(self$ptr, x)
    }

  ),

  active = list(
    ptr = function(){

      if(is_null_externalptr(private$ptr_)) {
        private$ptr_ <- cpp_RidgeRegression_create()

        if(private$fitted) {
          cpp_RidgeRegression_setCoef(private$ptr_, private$coef)
          cpp_RidgeRegression_setFitted(private$ptr_, private$fitted)
          cpp_RidgeRegression_setLambda(private$ptr_, private$lambda)
        }

      }

      private$ptr_
    }
  ),

  private = list(

    lambda = NULL,
    ptr_ = NULL,
    fitted = FALSE,
    coef = NULL

  )
)
