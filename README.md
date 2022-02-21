# gotobed-le

## Dependencies
- [Detours](https://github.com/microsoft/Detours)
- [JContainers](https://github.com/ryobg/JContainers)
- [spdlog](https://github.com/gabime/spdlog)
- [SKSE](https://skse.silverlock.org/)

## Building
Prerequisites:
- Visual Studio 2019

Open x86 Native Tools Command Prompt for VS 2019.

Clone repository:
```
git clone https://github.com/andrelo1/gotobed-le
```
Clone submodules:
```
cd gotobed-le
git submodule update --init
```
Extract `common` and `skse` folders from SKSE `src` directory to gotobed-le directory.

Build Detours:
```
cd Detours/src
nmake
```
Build spdlog:
```
cd ../../spdlog
cmake -B build -S . -A Win32
cmake --build build --config Release
```
Build `common_vc9` and `skse` from SKSE as static libraries.

Open `gotobed.sln` in Visual Studio and build solution, some SKSE files won't compile and require manual editing.
