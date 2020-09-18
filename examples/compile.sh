# Shared object creation
# g++ -fPIC -c -Wall LinearRegressor.cpp
# g++ -shared -o libMLplus.so.1.0 LinearRegressor.o
# (NOT WORKING) g++ -shared -Wl,-soname,libMLplus.so.1 -o libMLplus.so.1.0.1 LinearRegressor.o

# Executable compile command
# -I for include file additional locations, can see default locations in output of $ gcc -xc++ -E -v -
# -L for libMLplus.so to be searched in addition of default locations
# lMLplus to state that linker needs to search libMLplus.so
# Can check what the linker is doing by $ ld -lMLplus --verbose
g++ linearRegEx.cpp -I ../src/ -lMLplus -larmadillo -o executable

# LD_LIBRARY_PATH
# Operating system run time linking
# directories listed in the LD_LIBRARY_PATH environment variable
# directories listed in the executable's rpath;
# directories on the system search path, which (on Linux at least) consists of the
# entries in /etc/ld.so.conf plus /lib and /usr/lib.
# $ ldd executable shows the list of shared libraries used by the binary and their resolved path
# LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../build/src/
# export LD_LIBRARY_PATH
# It is used by your program to search directories containing shared libraries after it has been
# successfully compiled and linked
# Note: when linking libraries, ld by itself does not look for libraries in either LIBRARY_PATH or LD_LIBRARY_PATH.
# It's only when gcc invokes ld that LIBRARY_PATH becomes used

# CPATH; C_INCLUDE_PATH; CPLUS_INCLUDE_PATH
# Each variable's value is a list of directories separated by a special character, much like PATH,
# in which to look for header files.
# The special character, PATH_SEPARATOR, is target-dependent and determined at GCC build time.
# For Microsoft Windows-based targets it is a semicolon, and for almost all other targets it is a colon.
# CPATH specifies a list of directories to be searched as if specified with -I,
# but after any paths given with -I options on the command line.
# This environment variable is used regardless of which language is being preprocessed.
# The remaining environment variables apply only when preprocessing the particular language indicated.
# In all these variables, an empty element instructs the compiler to search its current working directory.
# Empty elements can appear at the beginning or end of a path.
# For instance, if the value of CPATH is :/special/include, that has the same effect as ‘-I. -I/special/include’. 

# LIBRARY_PATH
# It is used by gcc before compilation to search directories containing static and
# shared libraries that need to be linked to your program.
# The value of LIBRARY_PATH is a colon-separated list of directories, much like PATH.
# Linking using GCC also uses these directories when searching for ordinary
# libraries for the -l option (but directories specified with -L come first). 
