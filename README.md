# get_next_line

## Description
Reading a line from a file descriptor can be a tedious task. This project aims to streamline the process by implementing a function designed to read a line from a specified file descriptor. In addition to enhancing your programming toolkit, the project introduces you to a fascinating concept in C programming: static variables.

## Usage
To integrate the `get_next_line` function into your project, follow these steps:

1. Include the `get_next_line.h` header file in your source code:
    ```c
    #include "get_next_line.h"
    ```

2. During compilation, include the source files and the required flag:
    ```shell
    get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
    ```

## Testing

Customize test files by adding your own or modifying existing ones. To test the function, run the following command.

Test with the default buffer size:
    ```
    make run
    ```

Test with custom buffer size:
    ```
    make BUFFER_SIZE=size
    ```

To remove the executable run:
    ```
    make clean
    ```
