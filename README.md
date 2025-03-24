# Aqua Project

This project is a multithreaded Growtopia Private Server application developed using modern C++
Not finished! Check [Credits!](https://github.com/watan104/AquaServices/blob/master/Aqua/CREDITS.md)

## Features

- **Modern C++ Usage**: Written using C++17 and above standards.

- **Multithreading Support**: The application is capable of running concurrently with multiple threads.

- **Network Communication**: Low-level network communication is facilitated using the `ENet` library.

- **Formatting**: User-friendly and readable output formatting using the `fmt` library.

- **NetworkPool**: Provides a pool structure for managing network connections, ensuring efficient resource usage.


## Requirements


- A C++17 or newer compiler

- CMake (or any other preferred modern build tool)

- [fmt](https://github.com/fmtlib/fmt) Library

- [ENet](https://github.com/lsalzman/enet) Library


## Installation

- Install the `fmt` and `ENet` libraries on your system. (Refer to the respective library documentation for details.)
  ```
  vcpkg install fmt:x64-windows
  vcpkg install enet:x64-windows
  vcpkg integrate install
  ```
