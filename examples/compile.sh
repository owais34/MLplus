# Shared object creation
# g++ -fPIC -c -Wall LinearRegressor.cpp
# g++ -shared -o libMLplus.so.1.0 LinearRegressor.o
# (NOT WORKING) g++ -shared -Wl,-soname,libMLplus.so.1 -o libMLplus.so.1.0.1 LinearRegressor.o

# Executable compile command
# -I for include file additional locations, can see default locations in output of $ gcc -xc++ -E -v -
# -L for libMLplus.so to be searched in addition of default locations
# lMLplus to state that linker needs to search libMLplus.so
# Can check what the linker is doing by $ ld -lMLplus --verbose
g++ linearRegEx.cpp -I ../src/ -lMLplus -o executable

# Operating system run time linking
# directories listed in the LD_LIBRARY_PATH environment variable
# directories listed in the executable's rpath;
# directories on the system search path, which (on Linux at least) consists of the entries in /etc/ld.so.conf plus /lib and /usr/lib.
# $ ldd executable shows the list of shared libraries used by the binary and their resolved path
# LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../build/src/
# export LD_LIBRARY_PATH