set(MLPLUS_SRCS_METHODS) #MLPLUS_SRCS_METHODS is in this file's scope that the files in subdirectories of methods add the sources using 'PARENT_SCOPE'

set(DIRS
    linear_regression
    logistic_regression
    naive_bayes
)

foreach(dir ${DIRS})
    add_subdirectory(${dir})
endforeach()

#Here the MLPLUS_SRCS in the parent scope is appended with the value of MLPLUS_SRCS_METHODS which in turn was set by the subdirectories in this very way
set(MLPLUS_SRCS ${MLPLUS_SRCS} ${MLPLUS_SRCS_METHODS} PARENT_SCOPE) #### Investigate further later!
