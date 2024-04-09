The ToyBot is written using CMake as it's build system. The target to build is toybot from the top level
[CMakeLists.txt](CMakeLists.txt). Example commands to build cloxpp
for Mac OS, Linux, and Windows are given below.


## Building The Code

### Building on Linux and Mac OS

If you want to build the cloxpp on linux the easiest way is to
navigate to the cloxpp directory and execute the command
```
cmake -DCMAKE_BUILD_TYPE=Release -S . -B cmake-build-release
```
followed by the command
```
cmake --build cmake-build-release --target toybot
```
The cloxpp executable is then found at ``cmake-build-release/src/toybot``


**Alternatively, it's possible to build cloxpp from outside the source directory**
by using the same cmake commands as above, but in addition also specifying the paths
to the build directory
```
cmake -DCMAKE_BUILD_TYPE=Release -S /path/to/cloxpp/source/directory -B /path/to/build/directory
```
followed by the command
```
cmake --build /path/to/build/directory --target toybot
```


### Building on Windows
On windows the program can be built using the command
```
cmake -S /path/to/source/directory/ -B /path/to/build/directory
```
followed by
```
cmake --build /path/to/build-dir --config Release --target toybot
```


## Usage
The VM can be run as an interpreter in a shell by the command
```
./toybot
```
Alternatively a lox script can be executed by the command:
```
./toybot < input
```

## Tests

There are test files with expected outputs in subdirectories of the ``test`` directory.

### Pytest Test Runner
A python test runner (requires ``pytest``) which tests the binary is included the ``test`` directory.
If the ``toybot`` executable is built in ``cmake-build-release`` the tests can be executed by
navigating to the ``test`` directory and launching the command
```
pytest
```

### Catch2 C++ unit tests
The unit tests in C++ are implemented using [Catch2](https://github.com/catchorg/Catch2). They can be executed
by building and running the ``unit_tests`` target.
