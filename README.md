# get_next_line

42 project implementing a line-by-line file descriptor reader in C.

## Goal

`get_next_line` returns the next line from a file descriptor on each call, preserving unread data between calls until EOF.

## What it demonstrates

- Static buffer management
- File descriptor reading with `read`
- Dynamic allocation and cleanup
- Handling multiple file descriptors in the bonus version
- Careful edge-case work around EOF, empty files, and newline boundaries

## Files

```text
get_next_line/
  get_next_line.c
  get_next_line.h
  get_next_line_utils.c
  get_next_line_bonus.c
  get_next_line_bonus.h
  get_next_line_utils_bonus.c
```

## Usage

Include the header and compile the implementation with your program:

```bash
cc -Wall -Wextra -Werror main.c \
  get_next_line/get_next_line.c \
  get_next_line/get_next_line_utils.c
```

Bonus version:

```bash
cc -Wall -Wextra -Werror main.c \
  get_next_line/get_next_line_bonus.c \
  get_next_line/get_next_line_utils_bonus.c
```
