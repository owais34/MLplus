# Shared object creation
g++ -fPIC -c -Wall LinearRegressor.cpp
g++ -shared -o libMLplus.so.1.0 LinearRegressor.o
# (NOT WORKING) g++ -shared -Wl,-soname,libMLplus.so.1 -o libMLplus.so.1.0.1 LinearRegressor.o

# Executable compile command
g++ linearRegEx.cpp -I ../src/ -L ../src/ -lMLplus

# Operating system run time linking
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/my_library/
export LD_LIBRARY_PATH