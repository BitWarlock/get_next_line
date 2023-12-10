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
You can customize the test files by adding your own or modifying existing ones. To test the function, include `main.c`. Then, run the following command (replace "size" with your desired buffer size; if you don't want to specify a buffer size, the default is 69):
```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=size get_next_line.c get_next_line_utils.c main.c -o gnl_test && ./gnl_test
```
