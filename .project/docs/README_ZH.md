# 天宇开发库 - 帮助文档 （中文版）

&nbsp;

## 简介

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**天宇开发库**基于原生的 C++进行开发，不使用其他第三方外部依赖库。致力于使用纯净的 C++环境，构建高可用性、高复用性的开发组件。所有天宇开发库中的类组件，参考高级语言（C#、Java、JavaScript 等）提供接口，并实现高级语言模拟和封装。  
&nbsp;

## 安装与使用

### &nbsp;依赖环境

- 依赖环境：.Net 6.0
- 编&nbsp;&nbsp;译&nbsp;&nbsp;器：MSVC(Microsoft Visual C++)、GNU、Clang
- 工&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;具：cmake，make（Visual Studio）

&nbsp;

### &nbsp;如何构建

1. 获取源代码  
   可以通过如下方式获取：

   ```
   · 从Github拉取：git clone https://github.com/aitianyu-cn/tianyu-native.git
   · 下载 zip 包 ：https://github.com/aitianyu-cn/tianyu-native/archive/refs/heads/rel.zip
   ```

2. 初始化天宇库环境  
   用于初始化基本的依赖，如多语言。

   ```
    · cd ${tianyu-native}
    · ./init.sh             // PowerShell 或 Linux Shell 或 Mac Shell
      init.bat              // Windows Command

    · 获取帮助：[init.sh | init.bat] help
   ```

3. 生成项目

   ```
    · mkdir build                    // 由于cmake没有清理生成项目的功能，建议构建单独的文件夹保证生成文件和原始项目分离
    · cd build
    · cmake .. [参数][-D DTEST=true]

        参数：
            -D DTEST=true：指定生成天宇测试模块，可以进行代码测试
   ```

4. 编译项目  
   执行编译之后，生成的文件将会保存在 `${项目根目录}/target` 文件夹中。

   > bin 文件夹：保存所有生成的单元测试可执行文件
   >
   > lib 文件夹：保存所有生成的静态链接库（`dty.common.native.test.*` 的库文件为测试用，正式代码中不包含）

   ```
    > make
        · make

    > Visual Studio
        · 方式1：devenv.exe "Tianyu Development library.sln" // 需要安装 Visual Studio

        · 方式2：msbuild "Tianyu Development library.sln"    // 需要安装 Microsoft Build Engine
   ```

&nbsp;

### &nbsp;如何使用

1. 引用头文件

   - 方式 1：直接引用 `${项目根目录}/native` 目录之下的所有头文件。
   -
   - 方式 2：拷贝所有 `${项目根目录}/native` 目录下的头文件至新的目录中，通过新的目录进行访问（需要注意的是：拷贝不能影响文件的目录层级）

   &nbsp;

2. 链接  
   完成项目构建之后，所有静态库文件都将保存在 `${项目根目录}/target/lib` 文件夹中。生成可执行文件时，根据使用的头文件，按照本文档 <描述> 部分提供的库分类添加依赖并链接。

   &nbsp;

## 描述

### &nbsp;天宇开发库 - 核心库

> 头文件：`${项目根目录}/native/dty-core.hxx`, `${项目根目录}/native/prime/core/*`  
> 源文件：
>
> - 开发源：`${项目根目录}/native/dty-core.cpp`, `${项目根目录}/native/prime/core/src/*`
> - 测试源：`${项目根目录}/native/dty-test-core.cpp`, `${项目根目录}/test/prime/core/*`
>
> - 单元测试：`${项目根目录}/test/dty-core/*`  
>   &nbsp;
>
> 依&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;赖：`${项目根目录}/native/res/i18n/language.h`
>
> 目标文件：Windows：`dty-core.lib`，Linux 和 MacOS： `libdty-core.a`  
>  &nbsp;
>
> 说明：核心库包含开发必须的基本定义、类型和实现，同时提供轻量级的测试环境（本项目所有开发的单元测试部分使用核心库的测试工具进行，不依赖外部测试环境）。依赖项为静态多语言支持。  
> &nbsp;

<!--
&nbsp;

### &nbsp;天宇开发库 - 基础库

> 头文件：${项目根目录}/native/prime/core/\*
> 源文件：
>
> - 开发源：${项目根目录}/native/prime/core/src/\*
>
> - 单元测试：${项目根目录}/test/prime/core/\*
>
> 依赖&nbsp;&nbsp;&nbsp;&nbsp;：${项目根目录}/native/dty-core.hxx
>
> 说明：
> &nbsp; -->

&nbsp;
