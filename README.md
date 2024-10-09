# threepp custom project

This is a simple example of how to use consume [threepp](https://github.com/markaren/threepp) using CMake's FetchContent.

Includes Imgui as a bundled dependency.


### Using vcpkg (manifest mode)

This project includes `vcpkg.json`, but does not use it. 

You may add dependencies on your own and
call all CMake with `-DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake`

##### vcpkg under mingw
Under MinGW you'll need to specify the vcpkg triplet:
```shell
-DVCPKG_TARGET_TRIPLET=x64-mingw-[static|dynamic]  # choose either `static` or `dynamic`.
-DVCPKG_HOST_TRIPLET=x64-mingw-[static|dynamic]    # <-- needed only if MSVC cannot be found. 
```
