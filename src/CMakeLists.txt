# Define the files we need to compile.
# Anything not in this list will not be compiled into MLplus.
set(SOURCES
    LinearRegressor.cpp
)

set(HEADERS
    LinearRegressor.hpp
)

# Add directory name to sources.
set(DIR_SRCS)

foreach(file ${SOURCES})
  set(DIR_SRCS ${DIR_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
endforeach()

# Append sources (with directory name) to list of all MLplus sources (used at
# the parent scope).
# set(MLPLUS_SRCS ${MLPLUS_SRCS} ${DIR_SRCS} PARENT_SCOPE) #### Investigate further later!
set(MLPLUS_SRCS ${MLPLUS_SRCS} ${DIR_SRCS})

add_library(MLplus SHARED ${MLPLUS_SRCS})

set(MLPLUS_VERSION_MAJOR 0)
set(MLPLUS_VERSION_MINOR 1)
set(MLPLUS_VERSION_PATCH 0)
set(MLPLUS_VERSION_STRING ${MLPLUS_VERSION_MAJOR}.${MLPLUS_VERSION_MINOR}.${MLPLUS_VERSION_PATCH})
set_target_properties(MLplus
    PROPERTIES 
        VERSION ${MLPLUS_VERSION_STRING} 
        SOVERSION ${MLPLUS_VERSION_MAJOR}
)

# Refer mlpack/src/mlpack/CMakeLists.txt line#70
install(DIRECTORY ${CMAKE_BINARY_DIR}/include/MLplus DESTINATION /usr/include/MLplus/
    FILES_MATCHING PATTERN "*.h"
)

install(TARGETS MLplus
    LIBRARY DESTINATION /usr/lib/MLplus/
)

message(STATUS "cmake_current_source_dir is ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "cmake_binary_dir is ${CMAKE_BINARY_DIR}")