# NServer
# Installation
First make sure those packages are installed

```bash
  sudo apt install cmake git gh wget curl tar gdb --yes
```
## WSL2
1. Clone & enter repo

2. run **install.sh** - it will install other required packages

3. build CMake
```bash
  cmake -DCMAKE_BUILD_TYPE=Debug -G 'CodeBlocks - Unix Makefiles' -S . -B cmake-build-debug
```
4. compile target
```bash
  # available top-level targets are: NServer, docs, test_login
  cmake --build cmake-build-debug --target NServer -- -j 9
```
5. executables can be found in **cmake-build-debug/src** and utests in **cmake-build-debug/test**

## CLion (WSL2)
1. Open -> Project from version control
2. ***Set toolchain to WSL** (Settings -> Build, Execution, Deployment -> Toolchains)
3. RPM on **CMakeLists.txt** found in root directory, Reload CMake Project
4. Configurations should get automatically detected
