# 天宇开发库 - 开发文档 - 命名空间

### [返回主页](../../DEVELOP_DOC_ZH.md)

### [返回上一层](../Namespace.md)

&nbsp;

# 命名空间：::dty

## 命名空间 [collection](./namespace_dty_collection.md)

## 命名空间 [except](./namespace_dty_except.md)

## 命名空间 [i18n](./namespace_dty_i18n.md)

## 命名空间 [test](./namespace_dty_test.md)

&nbsp;

## 方法

|                名称                 |    类型    | 文件                  |                公共 API                 |
| :---------------------------------: | :--------: | :-------------------- | :-------------------------------------: |
|              `strlen`               | `function` | `native/dty-core.hxx` |              [fn_strlen]()              |
|              `strcmp`               | `function` | `native/dty-core.hxx` |              [fn_strcmp]()              |
|              `GetType`              | `function` | `native/dty-core.hxx` |             [fn_GetType]()              |
|            `ValueAlign`             | `function` | `native/dty-core.hxx` |            [fn_ValueAlign]()            |
|          `ValueAlignByPow`          | `function` | `native/dty-core.hxx` |         [fn_ValueAlignByPow]()          |
| `_dty_native_cpp_default_to_string` | `function` | `native/dty-core.hxx` | [fn_dty_native_cpp_default_to_string]() |
|                                     |            |                       |                                         |

&nbsp;

## 数据类型

|        名称        |     类型      | 文件                              |       公共 API       |
| :----------------: | :-----------: | :-------------------------------- | :------------------: |
|    `IToString`     |  `interface`  | `native/dty-core.hxx`             |    [IToString]()     |
|    `PlatformID`    |    `enum`     | `native/dty-core.hxx`             |    [PlatformID]()    |
|   `TianyuObject`   |   `class_A`   | `native/dty-core.hxx`             |   [TianyuObject]()   |
|       `Type`       |   `class_T`   | `native/dty-core.hxx`             |       [Type]()       |
|                    |               |                                   |                      |
|   `KeyValuePair`   |   `class_T`   | `native/prime/core/internal.h`    |   [KeyValuePair]()   |
| `IObjectConverter` |  `interface`  | `native/prime/core/internal.h`    | [IObjectConverter]() |
| `IStringConverter` |  `interface`  | `native/prime/core/internal.h`    | [IStringConverter]() |
|                    |               |                                   |                      |
|       `Byte`       |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|     `Boolean`      |    `class`    | `native/prime/core/basetype.hpp`  |     [Boolean]()      |
|       `Char`       |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|      `Double`      |    `class`    | `native/prime/core/basetype.hpp`  |      [Double]()      |
|      `Float`       |    `class`    | `native/prime/core/basetype.hpp`  |      [Float]()       |
|      `Int16`       |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|      `Int32`       |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|      `Int64`       |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|       `Long`       |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|      `SByte`       |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|      `Short`       |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|      `UChar`       |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|      `UInt16`      |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|      `UShort`      |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|      `UInt32`      |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|      `UInt64`      |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|      `ULong`       |    `class`    | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|   `TIntegerBase`   |   `class_T`   | `native/prime/core/basetype.hpp`  |   [TIntegerBase]()   |
|                    |               |                                   |                      |
|    `EventArgs`     |    `class`    | `native/prime/core/event.hpp`     |    [EventArgs]()     |
| `EventHandlerItem` |  `struct_T`   | `native/prime/core/event.hpp`     | [EventHandlerItem]() |
|   `EventHandler`   |   `class_T`   | `native/prime/core/event.hpp`     |   [EventHandler]()   |
|                    |               |                                   |                      |
|   `FormatHelper`   |    `class`    | `native/prime/core/formatter.hpp` |   [FormatHelper]()   |
|    `IFormatter`    |  `interface`  | `native/prime/core/formatter.hpp` |    [IFormatter]()    |
|   `ParseHelper`    |    `class`    | `native/prime/core/formatter.hpp` |   [ParseHelper]()    |
|                    |               |                                   |                      |
|     `byte_ptr`     |    `class`    | `native/prime/core/pointer.hpp`   |   [SmartPointer]()   |
|    `double_ptr`    |    `class`    | `native/prime/core/pointer.hpp`   |   [SmartPointer]()   |
|     `bool_ptr`     |    `class`    | `native/prime/core/pointer.hpp`   |   [SmartPointer]()   |
|    `float_ptr`     |    `class`    | `native/prime/core/pointer.hpp`   |   [SmartPointer]()   |
|     `long_ptr`     |    `class`    | `native/prime/core/pointer.hpp`   |   [SmartPointer]()   |
|     `int_ptr`      |    `class`    | `native/prime/core/pointer.hpp`   |   [SmartPointer]()   |
|    `short_ptr`     |    `class`    | `native/prime/core/pointer.hpp`   |   [SmartPointer]()   |
|    `string_sp`     |    `class`    | `native/prime/core/pointer.hpp`   |   [SmartPointer]()   |
|   `SmartPointer`   |   `class_T`   | `native/prime/core/pointer.hpp`   |   [SmartPointer]()   |
|                    |               |                                   |                      |
|     `Property`     |   `class_T`   | `native/prime/core/property.hpp`  |     [Property]()     |
|    `LProperty`     |   `class_T`   | `native/prime/core/property.hpp`  |    [LProperty]()     |
|    `IProperty`     | `interface_T` | `native/prime/core/property.hpp`  |    [IProperty]()     |
| `IPropertyGetter`  | `interface_T` | `native/prime/core/property.hpp`  | [IPropertyGetter]()  |
| `IPropertySetter`  | `interface_T` | `native/prime/core/property.hpp`  | [IPropertySetter]()  |
|                    |               |                                   |                      |

&nbsp;
