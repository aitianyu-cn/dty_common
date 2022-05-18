# 天宇开发库 - 开发文档 - 宏定义

### [返回上一层](../DEVELOP_DOC_ZH.md)

&nbsp;

## `native/dty-core.hxx`

|                   宏                   | 类型 |          参数/值           | 说明                                                       |
| :------------------------------------: | :--: | :------------------------: | ---------------------------------------------------------- |
|        `__DTY_CORE_MSG_CONVERT`        | 函数 |          消息名称          | 绑定多语言头文件，用于提供`key`->`i18n text`的转换         |
|             `__DTY_ERR_64`             |  值  |             1              | 指示当前系统需要 64bit 环境                                |
|              `__DTY_WIN`               |  值  |             1              | 指示当前系统为：微软 Windows                               |
|              `__DTY_APF`               |  值  |             1              | 指示当前系统为：Apple MacOS                                |
|              `__DTY_AIS`               |  值  |             1              | 指示当前系统为 Apple 平台 Iphone 模拟器                    |
|              `__DTY_AIP`               |  值  |             1              | 指示当前系统为 Apple IOS                                   |
|              `__DTY_AMC`               |  值  |             1              | 指示当前系统为 Apple MacOS                                 |
|              `__DTY_LNX`               |  值  |             1              | 指示当前系统为：Linux 系列                                 |
|                                        |      |                            |                                                            |
|         `__SIGNED_CHAR_MIN__`          |  值  |            -128            | 字符类型有符号数最小值                                     |
|         `__SIGNED_CHAR_MAX__`          |  值  |            127             | 字符类型有符号数最大值                                     |
|        `__UNSIGNED_CHAR_MIN__`         |  值  |             0              | 字符类型无符号数最小值                                     |
|        `__UNSIGNED_CHAR_MAX__`         |  值  |            0xFF            | 字符类型无符号数最大值                                     |
|         `__SIGNED_INT8_MIN__`          |  值  |            -128            | 8 位整数类型有符号数最小值                                 |
|         `__SIGNED_INT8_MAX__`          |  值  |            127             | 8 位整数类型有符号数最大值                                 |
|        `__UNSIGNED_INT8_MIN__`         |  值  |             0              | 8 位整数类型无符号数最小值                                 |
|        `__UNSIGNED_INT8_MAX__`         |  值  |            0xFF            | 8 位整数类型无符号数最大值                                 |
|         `__SIGNED_INT16_MIN__`         |  值  |           -32768           | 16 位整数类型有符号数最小值                                |
|         `__SIGNED_INT16_MAX__`         |  值  |           32767            | 16 位整数类型无符号数最小值                                |
|        `__UNSIGNED_INT16_MIN__`        |  值  |             0              | 16 位整数类型无符号数最小值                                |
|        `__UNSIGNED_INT16_MAX__`        |  值  |           0xFFFF           | 16 位整数类型无符号数最大值                                |
|         `__SIGNED_INT32_MIN__`         |  值  |        -2147483648         | 32 位整数类型有符号数最小值                                |
|         `__SIGNED_INT32_MAX__`         |  值  |         2147483647         | 32 位整数类型无符号数最小值                                |
|        `__UNSIGNED_INT32_MIN__`        |  值  |             0              | 32 位整数类型无符号数最小值                                |
|        `__UNSIGNED_INT32_MAX__`        |  值  |         0xFFFFFFFF         | 32 位整数类型无符号数最大值                                |
|         `__SIGNED_INT64_MIN__`         |  值  |    -9223372036854775808    | 64 位整数类型有符号数最小值                                |
|         `__SIGNED_INT64_MAX__`         |  值  |    9223372036854775807     | 64 位整数类型有符号数最大值                                |
|        `__UNSIGNED_INT64_MIN__`        |  值  |             0              | 64 位整数类型无符号数最小值                                |
|        `__UNSIGNED_INT64_MAX__`        |  值  |     0xFFFFFFFFFFFFFFFF     | 64 位整数类型无符号数最大值                                |
|     `__CHAR_TYPE_BINARY_LENGTH__`      |  值  |             8              | 字符类型二进制位数                                         |
|     `__BYTE_TYPE_BINARY_LENGTH__`      |  值  |             8              | 字节类型二进制位数                                         |
|     `__SHORT_TYPE_BINARY_LENGTH__`     |  值  |             16             | 短整数类型二进制位数                                       |
|      `__INT_TYPE_BINARY_LENGTH__`      |  值  |             32             | 整数类型二进制位数                                         |
|     `__LONG_TYPE_BINARY_LENGTH__`      |  值  |             64             | 长整数类型二进制位数                                       |
|     `__FLOAT_TYPE_BINARY_LENGTH__`     |  值  |             32             | 实数类型二进制位数                                         |
|    `__DOUBLE_TYPE_BINARY_LENGTH__`     |  值  |             64             | 双精度实数类型二进制位数                                   |
|    `__BOOLEAN_TYPE_BINARY_LENGTH__`    |  值  |             8              | 布尔值类型二进制位数                                       |
|                                        |      |                            |                                                            |
|            `__PREDEFINE__`             |  -   |             -              | 标识未定义实体的方法、结构体、类等元素                     |
|            `__PREREALIZ__`             |  -   |             -              | 标识`__PREDEFINE__`定义的方法、结构体、类等元素的实现      |
|             `__DEFAULT__`              |  -   |             -              | 标识可重载函数和拓展类型、数据的默认实现                   |
|           `__CONSTRUCTOR__`            |  -   |             -              | 标识类的构造函数（包含模拟 OO）                            |
|            `__DESTRUCTOR__`            |  -   |             -              | 标识类的析构函数（包含模拟 OO）                            |
|           `__COPYSTRUCTOR__`           |  -   |             -              | 标识类的复制构造函数（包含模拟 OO）                        |
|             `__VARIABLE__`             |  -   |             -              | 标识以值类型保存、传递的属性、变量和参数                   |
|              `__ARRAY__`               |  -   |            `[]`            | 标识当前值类型保存为数组                                   |
|             `__POINTER__`              |  -   |            `*`             | 标识以指针类型保存、传递的属性、变量和参数                 |
|             `__DPOINTER__`             |  -   |            `**`            | 标识以二级指针类型保存、传递的属性、变量和参数             |
|            `__PTR_TO_VAR__`            |  -   |            `*`             | 标识指针类型到值类型的转换                                 |
|            `__VAR_TO_PTR__`            |  -   |            `&`             | 标识值类型到指针类型的转换                                 |
|              `__INPUT__`               |  -   |             -              | 标识方法与函数的参数类型为输入                             |
|              `__OTPUT__`               |  -   |             -              | 标识方法与函数的参数类型为输出                             |
|              `__INOUT__`               |  -   |             -              | 标识方法与函数的参数类型既可以进行输入也可作为返回         |
|              `__INSTE__`               |  -   |             -              | 标识方法的传入参数为当前操作的实例（用于 C 语言的模拟 OO） |
|              `__CMODE__`               |  -   |        `extern "C"`        | 标识所修饰的元素以 C 语言的方式进行编译                    |
|           `__DTY_DEV_MODE__`           |  -   |             -              | 指示当前项目是否进入开发模式                               |
|         `__DTY_UNSAFE_MODE__`          |  值  | Tianyu Library Unsafe Mode | 指示当前项目内的部分组件使用不安全的内存模式               |
|      `__DTY_DEEP_LEARNING_MODE__`      |  -   |             -              | 指示当前项目内的部分组件使用学习模式                       |
| `__DTY_SMART_POINTER_COPY_WEAK_MODE__` |  -   |             -              | 指示当前项目内的智能指针使用浅拷贝模式进行复制构造         |
|               `__PUB__`                |  -   |         `public:`          | 指示修饰的函数与属性外部可访问                             |
|               `__PRI__`                |  -   |         `private:`         | 指示修饰的函数与属性外部不可访问                           |
|               `__PRO__`                |  -   |        `protected:`        | 指示修饰的函数与属性子类可访问                             |
|           `__construction__`           |  -   |             -              | 构造函数返回值替换宏定义                                   |
|           `__cp_construct__`           |  -   |             -              | 复制构造函数返回值替换宏定义                               |
|           `__destruction__`            |  -   |             -              | 析构函数返回值替换宏定义                                   |
|          `__pure_virtual_fun`          |  -   |           `= 0`            | 纯虚函数后缀                                               |
|           `__pure_const_fn`            |  -   |        `const = 0`         | 纯虚常函数后缀                                             |
|           `__override_func`            |  -   |         `override`         | 函数重载                                                   |
|           `__override_cfun`            |  -   |      `const override`      | 常函数重载                                                 |
|            `__REFERENCE__`             |  -   |            `&`             | 标识以引用类型保存、传递的属性、变量和参数                 |
|             `__PTRREFER__`             |  -   |            `*&`            | 标识以指针引用类型保存、传递的属性、变量和参数             |
|            `__PTR_TO_REF__`            |  -   |            `*`             | 标识指针类型到引用类型的转换                               |
|            `__REF_TO_PTR__`            |  -   |            `&`             | 标识引用类型到指针类型的转换                               |
|            `__REF_TO_VAR__`            |  -   |             -              | 标识引用类型到值类型的转换                                 |
|            `__VAR_TO_REF__`            |  -   |             -              | 标识值类型到引用类型的转换                                 |
|               `abstract`               |  -   |             -              | 抽象类定义前缀                                             |
|              `_interface`              |  -   |      `abstract class`      | 接口类型                                                   |
|           `_internal_export`           |  -   |             -              | 内部导出接口                                               |
|                `_enum`                 |  -   |        `enum class`        | 枚举类型定义                                               |
|                                        |      |                            |                                                            |
|            `__DTEST_CORE__`            |  -   |             -              | 表示启用测试框架                                           |
|              `TEST_MAIN`               | 函数 |          测试名称          | 测试框架入口 main 函数                                     |
|                                        |      |                            |                                                            |

&nbsp;

<!--
| 宏  | 类型 | 参数/值 | 说明 |
| :-: | :--: | :-----: | ---- |
| ``  |  -   |   ``    |      |
| ``  |  -   |    -    |      |
| ``  |  值  |         |      |
| ``  | 函数 |         |      | -->
