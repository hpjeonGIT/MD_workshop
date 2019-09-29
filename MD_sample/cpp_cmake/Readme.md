# sample code using -std=c++14
# cmake and ctest
# steps
- `mkdir build`
- `cd build`
- `cmake ..`
  - Or `cmake .. -DCMAKE_PREFIX_INSTALL=/home/$username/TEMP`
- `build -j 3`
- `ctest` # run ctest
  - `ctest -L basic` # basic ctest only
  - `ctest -L class` # class ctest only 
- md.exe is found at src
- make install will copy md.exe into $CMAKE_PREFIX_INSTALL/bin folder
