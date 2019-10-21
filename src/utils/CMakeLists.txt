set(MLPLUS_SRCS_UTILS) #MLPLUS_SRCS_UTILS is in this file's scope that the files in subdirectories of utils add the sources using 'PARENT_SCOPE'

set(DIRS
	dataframe
)

foreach(dir ${DIRS})
    add_subdirectory(${dir})
endforeach()

#Here the MLPLUS_SRCS in the parent scope is appended with the value of MLPLUS_SRCS_UTILS which in turn was set by the subdirectories in this very way
set(MLPLUS_SRCS ${MLPLUS_SRCS} ${MLPLUS_SRCS_UTILS} PARENT_SCOPE) #### Investigate further later!
