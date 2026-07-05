# get_next_line

`get_next_line` is a 42 C project that implements a reusable function for reading one line at a time from a file descriptor.

It looks simple from the outside, but the project is really about managing buffers, memory, EOF behavior, and repeated calls without losing unread data.

## Goal

Implement:

```c
char *get_next_line(int fd);
```

Each call returns the next available line from `fd`, including the newline when present, until EOF.

## What it handles

- Reading from files and standard input
- Preserving leftover data between calls
- Returning lines of different sizes
- Handling EOF cleanly
- Avoiding leaks across repeated calls
- Supporting multiple file descriptors in the bonus version

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

Compile with your own test file:

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

## Technical highlights

- Uses static storage to preserve unread buffer state
- Builds dynamic strings safely as data arrives
- Separates core logic from helper functions
- Exposes a small API that can be reused in later projects

## Skills demonstrated

- File descriptor I/O
- Buffer management
- Dynamic allocation
- Edge-case handling
- Writing reusable C utilities
