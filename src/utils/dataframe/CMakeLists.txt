# Define the files we need to compile.
# Anything not in this list will not be compiled into MLplus.
set(SOURCES
	dataframe.hpp
    dataframe.cpp
)

# Add directory name to sources.
set(DIR_SRCS)

foreach(file ${SOURCES})
  set(DIR_SRCS ${DIR_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
endforeach()

# Append sources (with directory name) to list of all MLplus sources (used at
# the parent scope).
set(MLPLUS_SRCS_UTILS ${MLPLUS_SRCS_UTILS} ${DIR_SRCS} PARENT_SCOPE) #### Investigate further later!
# set(MLPLUS_SRCS ${MLPLUS_SRCS} ${DIR_SRCS})
