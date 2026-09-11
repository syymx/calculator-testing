# Calculator Testing

本项目为《软件测试与质量保障》课程实践项目。

被测项目为 C++ Calculator 表达式计算器，使用 **GoogleTest** 编写自动化测试，并通过 **CMake + Ninja + GCC** 完成项目构建，使用 **CTest** 统一执行测试。

## 1. 开发与测试环境

| 工具 | 版本 | 用途 |
|---|---|---|
| Windows | Windows 10/11 | 开发平台 |
| GCC / G++ | 16.2.0 | C++ 编译器 |
| Git | 2.55.0 | 版本控制 |
| CMake | 4.4.3 | 项目构建配置 |
| Ninja | 1.13.2 | 构建工具 |
| GoogleTest | MSYS2 UCRT64 版本 | C++ 自动化测试框架 |
| CTest | 随 CMake 安装 | 自动化测试执行 |

C++ 标准：**C++17**

推荐使用 **VS Code + MSYS2 UCRT64** 进行开发。

## 2. 环境配置

安装 MSYS2 后，打开 **MSYS2 UCRT64** 终端，安装项目所需环境：

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-cmake
pacman -S mingw-w64-ucrt-x86_64-ninja
pacman -S mingw-w64-ucrt-x86_64-gtest
```

将以下目录添加到 Windows `PATH`：

```text
C:\msys64\ucrt64\bin
```

重新打开 VS Code 后，可通过以下命令检查环境：

```powershell
g++ --version
git --version
cmake --version
ninja --version
```

## 3. 项目结构

```text
calculator-testing/
├── app/
│   └── main.cpp              # 示例程序
├── src/
│   └── calculator.hpp        # 被测 Calculator 源代码
├── tests/
│   ├── test_smoke.cpp        # 基础冒烟测试
│   └── ...                   # 其他自动化测试
├── docs/                     # 测试相关文档
├── CMakeLists.txt            # CMake 构建配置
├── README.md
└── .gitignore
```

## 4. 构建项目

首次构建时，在项目根目录执行：

```powershell
cmake -S . -B build -G Ninja
cmake --build build
```

其中所有构建文件均生成在 `build/` 目录中。

## 5. 运行自动化测试

执行：

```powershell
ctest --test-dir build --output-on-failure
```

测试全部通过时将显示：

```text
100% tests passed, 0 tests failed
```

修改已有测试代码后，只需重新执行：

```powershell
cmake --build build
ctest --test-dir build --output-on-failure
```

## 6. 测试框架

项目使用 **GoogleTest** 编写 C++ 自动化测试，例如：

```cpp
#include <gtest/gtest.h>
#include "calculator.hpp"

TEST(CalculatorBasicTest, BasicAddition)
{
    EXPECT_EQ(calculator::eval("1 + 2"), 3);
}
```

GoogleTest 负责测试用例与断言，CTest 负责统一发现和执行测试。
