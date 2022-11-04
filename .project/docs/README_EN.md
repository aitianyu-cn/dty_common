# Tianyu Development Library - Help Document (English)

&nbsp;

## SUMMARY

&nbsp;&nbsp;**Tianyu Development Library** (shortened to TDL later) based on the native C++ development without using any other third-party external dependency library. Dedicated to building highly available and reusable development components using a pure C++ environment. All **TDL** class components, reference high-level languages (C#, Java, JavaScript, etc.) to provide interfaces, and achieve high-level language simulation and encapsulation.

&nbsp;

## INSTALL & USE

### &nbsp;Environment Dependency

- Dependency&nbsp;:&nbsp; Node.Js
- Compiler&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp; MSVC(Microsoft Visual C++)、GNU、Clang
- Tools&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp; cmake，make（Visual Studio）

&nbsp;

### &nbsp;How to Build

1. **Get the Source Code**  
   You can get the source code by the following ways:

   ```
   · Pull Repo from Git   : git clone https://github.com/aitianyu-cn/tianyu-native.git
   · Download Zip-Package : https://github.com/aitianyu-cn/tianyu-native/archive/refs/heads/rel.zip
   ```

2. **Initializing**  
   Used to initialize basic dependencies, such as _Multi-Languages_.

   ```
    · cd ${tianyu-native}/tools
    · npm install           // install node.js dependencies (skipped if installed)
    · npm run build-i18n    // init multiple language resource
   ```

   - For more information of the tool, take references from `${tianyu-native}/tools/README.md`

     ` `

3. **Make Project**

   ```
    · cd cd ${tianyu-native}/tools
    · npm install           // install node.js dependencies (skipped if installed)
    · npm run build         // build tests and libraries
              build-test    // build tests only
              build-native  // build libraries only
    · mkdir build           // create a individual folder to keep the project clear
    · cd build
    · cmake ..
   ```

   - For more information of the tool, take references from `${tianyu-native}/tools/README.md`

     ` `

4. **Compile**  
   After compiling, the generated files will be stored in the `${PROJECT_ROOT}/target` folder.

   > bin : Save all generated unit test executables.
   >
   > lib &nbsp;: Save all generated static link libraries ( `dty.common.native.test.*` library files are for testing purposes, not included in the official code).

   ```
    > make
        · make

    > Visual Studio
        · Option 1: devenv.exe "Tianyu Development library.sln" // Needs to Install 'Visual Studio'

        · Option 2: msbuild "Tianyu Development library.sln"    // Needs to Install 'Microsoft Build Engine'
   ```

&nbsp;

### &nbsp;How to Use

1. **Include Header Files**

   - Option 1 : Directly includes all header files under `${PROJECT_ROOT}/native`.

   - Option 2 : Copy all headers from `${PROJECT_ROOT}/native` to a new directory and access them through the new directory (note: copying does not affect the directory level of the files).

2. **Link**  
   After the project is built, all the static library files will be saved in the `${PROJECT_ROOT}/target/lib` folder. When generating the executable, add dependencies and links according to the library classification provided in the < Description > section of this document, depending on the header files used.

   &nbsp;

## DESCRIPTION

### &nbsp;TDL - Core Library

> Header Files: `${PROJECT_ROOT}/native/dty-core.hxx`, `${PROJECT_ROOT}/native/prime/core/*`  
> Source Files:
>
> - Dev Files : `${PROJECT_ROOT}/native/dty-core.cpp`, `${PROJECT_ROOT}/native/prime/core/src/*`
> - Test Files: `${PROJECT_ROOT}/native/dty-test-core.cpp`, `${PROJECT_ROOT}/test/prime/core/*`
>
> - Unit Tests: `${PROJECT_ROOT}/test/dty-core/*`  
>   &nbsp;
>
> Dependencies: `${PROJECT_ROOT}/native/res/i18n/language.h`
>
> Target Files:
>
> - Windows &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: `dty-core.lib`
> - MacOS & Linux &nbsp;&nbsp;&nbsp;: `libdty-core.a`  
>   &nbsp;
>
> Note: The core library contains the basic definitions, types and implementations necessary for development, while providing a lightweight test environment (all the unit testing part of the development of the project is carried out using the core library test tools, independent of external test environment). Dependencies are static multilingual support.  
> &nbsp;

&nbsp;
