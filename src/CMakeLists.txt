set(MLPLUS_SRCS) #MLPLUS_SRCS is in this file's scope that the files in subdirectories (methods and utils) add the sources using 'PARENT_SCOPE'

set(DIRS
    methods
    utils
)

foreach(dir ${DIRS})
    add_subdirectory(${dir}) #At this the subdirectories add the above mentioned sources
endforeach()

message(STATUS "<Script message> MLplus sources are ${MLPLUS_SRCS}")
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

# Collect all header files in the library.
# file(GLOB_RECURSE INCLUDE_H_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
file(GLOB_RECURSE INCLUDE_HPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
set(INCLUDE_FILES ${INCLUDE_HPP_FILES})

# Move all of these header files to <builddir>/include/mlpack/ after the library
# is built.  First we have to create that directory though.
add_custom_target(MLplus_headers)
add_custom_command(TARGET MLplus_headers POST_BUILD
  COMMAND ${CMAKE_COMMAND} ARGS -E
    make_directory ${CMAKE_BINARY_DIR}/include/MLplus/
)

# Then copy each of the header files over to that directory.
foreach(incl_file ${INCLUDE_FILES})
  add_custom_command(TARGET MLplus_headers POST_BUILD
    COMMAND ${CMAKE_COMMAND} ARGS -E
      copy ${CMAKE_CURRENT_SOURCE_DIR}/${incl_file}
           ${CMAKE_BINARY_DIR}/include/MLplus/${incl_file}
      BYPRODUCTS ${CMAKE_BINARY_DIR}/include/MLplus/${incl_file})
endforeach()

install(DIRECTORY ${CMAKE_BINARY_DIR}/include/MLplus 
    DESTINATION /usr/local/include
)

install(TARGETS MLplus
    LIBRARY DESTINATION /usr/local/lib/
)

add_dependencies(MLplus MLplus_headers)
