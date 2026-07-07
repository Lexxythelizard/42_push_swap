README.md

*This project has been created as part of the 42 curriculum by lenivorb.*

# ft\_printf

## Description

`ft_printf` is a customized reimplementation of the `<stdio.h>` (standard input output) library `printf function` created as part of the 42 curriculum.

The goal of this project is to understand what's going on under the hood of the original `printf` \

I deci

## Instructions

Include this library

```C
#include "[path to dir]/ft_printf.h"
```

to use it in Your programms 

```bash
cc [your flags] [your files] -L [path to library] -l ftprintf -o [your Program name]
```

or once You added it to your libft:

```bash
cc [your flags] [your files] -L [path to library] -l ft -o [your Program name]
```

## Resources

*The following resources were useful while working on this project:*

### Documentation

**man pages**
- man printf
- man \<stdio.h\>
- man \<unistd.h\>

**makefile**
- GNU make

**common webpages**
- Geeks for Geeks : https://www.geeksforgeeks.org/c/c-programming-language/
- stackoverflow : https://stackoverflow.com/questions
- wikiboks : https://en.wikibooks.org/wiki/C\_Programming/
	- espacially: 
	  https://en.wikibooks.org/wiki/C\_Programming/POSIX\_Reference/stdio.h
- ... 

### Tools

- cc for compilation
- make for build automation
- ar for creating the static library
- valgrind for memory checking
- custom test files for comparing original and ft_ behavior
- gdb for debugging
- codes testers:
	- tripouli tester:

### AI usage

AI was not used at all :)

---

## Structs

### overview

- `t_flags`

### define

**t_flags**

just important for the bonuses to count the flags for later process

```C
typedef struct s_flags
{
    int     hash;
    int     wsp;
    int     plus;
}           t_flags;


```

---

## how to use

### available specifiers:

following specifiers are implemented:

**mandatory**

- `%c`		put a `character`
- `%s`		put a `string`
- `%d`		put a `decimal`
- `%i`		put an `integer`
- `%u`		put an `unsigned integer`
- `%x`		put a `integer` in `hexadecimal` (lowercase)
- `%X`		put a `integer` in `hexadecimal` (uppercase)
- `%p`		put a `pointer` adress (hexadecimal in lowercase)

**additional**

- `%ld`		put a `long`
- `%lu`		put an `unsignedlong`
- `%zd`		put a `ssize_t`
- `%zu`		put a `size_t`
- `%lx`		put a `long` in `hexadecimal` (lowercase)
- `%lX`		put a `long` in `hexadecimal` (uppercase)
- `%zx`		put a `ssize_t` in `hexadecimal` (lowercase)
- `%zX`		put a `ssize_t` in `hexadecimal` (uppercase)

### available flags:

following flagss are implemented:

**mandatory**

- `+`		put a `+` before a positive signed int/long/ssize\_t \
			overwrites whitespace
- ` `		put a ` ` (white space) before a positive signed int/long/ssize\_t
- `#`		put a `0x` / `0X` before a hexadecimal number \
			overwrites whitespace

numbers of flags could be arbitary :)

---

## available with `ft_printf.h`

**the only function available with `ft_printf.h`**


### Function - overview

- `ft_printf`


### Function - detail

**ft_printf**
- Params:	`const char`	`*passed_line`
- Return:	`void`			`...`			array of arguments
- Return:	`int`			`wrt`			written characters
- NOTE:		Not all specifiers from the original have been implemented here... \
			Not all flags from the original have been implemented here... \
			mimics the undefined behavior of the original in most cases \
			once an error occures the function stops wirting and returns -1


## not available core functions: under the hood

**these functions are not available with `ft_printf.h`**


### Function - overview

- utils
  - `lxy_put_unsigned_int_base()`
  - `lxy_put_unsigned_long_base()`
  - `lxy_put_size_t_base()`
  - `lxy_strlen()`

- specifiers
  - `is_specifier()`
  - `is_specifier_single()`
  - `is_specifier_prefix()`
  - `get_specifier_lenght()`

- scan
  - `is_flag()`
  - `is_percent()`
  - `is_equal()`

- flags
  - `*init_flags()`
  - `clean_flags()`

- process
  - `process_specifier()`
  - `process_flagg()`

- call put function
  - `call_put_func()`

- get functions
  - `(*get_char_func()`
  - `(*get_string_func()`
  - `(*get_long_func()`
  - `(*get_ssize_t_func()`
  - `(*get_int_func()`
  - `(*get_ud_func()`
  - `(*get_lu_func()`
  - `(*get_size_t_func()`

- put functions
  - `lxy_put_char()`
  - `lxy_put_str()`
  - `lxy_put_percent_sign()`
  - `lxy_put_trigger_hashflag()`
  - `lxy_put_trigger_hashflag_upper()`
  - `lxy_put_white_space()`
  - `lxy_put_decimal()`
  - `lxy_put_signed_int()`
  - `lxy_put_undecimal()`
  - `lxy_put_signed_long()`
  - `lxy_put_ssize_t()`
  - `lxy_put_unsigned_int()`
  - `lxy_put_unsigned_long()`
  - `lxy_put_size_t()`
  - `lxy_put_hexa_lowercase()`
  - `lxy_put_hexa_uppercase()`
  - `lxy_put_long_hexa_lowercase()`
  - `lxy_put_long_hexa_uppercase()`
  - `lxy_put_long_long_hexa_lowercase()`
  - `lxy_put_long_long_hexa_uppercase()`
  - `lxy_put_pointer()`


### Function - dependencies

*not all, but the most important dependecies to understand this library*

**orchestering function**

```text
Program flow
└── ft_printf()                         ft_printf.c
    ├── init_flags()					core_flags.c
    ├── is_percent()					core_scan.c
    ├── lxy_putchar()					core_put_chars.c
    ├── process_specifier()				core_process.c
    ├── va_start()						<lib>
    ├── va_end()						<lib>
    └── return (0)                      main.c
```

**process functions**

```text
process
├── process_specifier()				core_process.c
│   ├── process_flagg()				core_process.c
│   ├── call_put_func()				core_call_func.c
│   ├── get_specifier_length()		core_specifier.c
│   └── clean_flags()           	core_flags.c
│
│
└── process_flaggr()				core_process.c
    ├── is_specifier()				core_specifier.c
    ├── is_flagg()					core_flagss.c
    └── lxy_put_char()				core_put_chars.c

```

**put functions**

```text
Exec functions
├── lxy_put_str()						core_put_chars.c
│   └── lxy_put_char()             		core_put_chars.c
│       └── write()                		<lib>
│
├── lxy_put_unsigned_int()				core_put_unsigned_nbrs.c
│   └── lxy_put_unsigned_int_base()		core_utils_put_nbr_to_base.c
│       └── write()                		<lib>
│
├── lxy_put_unsigned_long()				core_put_unsigned_nbrs.c
│   └── lxy_put_unsigned_long_base()	core_utils_put_nbr_to_base.c
│       └── write()                		<lib>
│
├── lxy_put_size_t()					core_put_unsigned_nbrs.c
│   └── lxy_put_size_t_base()			core_utils_put_nbr_to_base.c
│       └── write()                		<lib>
│
├── lxy_put_signed_int()				core_put_signed_nbr.c
│   └── lxy_put_unsigned_int_base()		core_utils_put_nbr_to_base.c
│
├── lxy_put_signed_long()				core_put_signed_nbr.c
│   └── lxy_put_unsigned_long_base()	core_utils_put_nbr_to_base.c
│
├── lxy_put_ssize_t()					core_put_signed_nbr.c
│   └── lxy_put_size_t_base()			core_utils_put_nbr_to_base.c
│
├── lxy_put_hexa_lowercase()			core_put_hexa_lowercase.c
│   ├── lxy_put_trigger_hashflag()		core_put_absrtaction.c
│   └── lxy_put_unsigned_int_base()		core_utils_put_nbr_to_base.c
│
├── lxy_put_long_hexa_lowercase()		core_put_hexa_lowercase.c
│   ├── lxy_put_trigger_hashflag()		core_put_absrtaction.c
│   └── lxy_put_unsigned_long_base()	core_utils_put_nbr_to_base.c
│
├── lxy_put_long_long_hexa_lowercase()	core_put_hexa_lowercase.c
│   ├── lxy_put_trigger_hashflag()		core_put_absrtaction.c
│   └── lxy_put_size_t_base()			core_utils_put_nbr_to_base.c
│
├── lxy_put_pointer()					core_put_hexa_lowercase.c
│   ├── lxy_put_trigger_hashflag()		core_put_absrtaction.c
│   └── lxy_put_unsigned_long_base()	core_utils_put_nbr_to_base.c
│
├── lxy_put_hexa_upperrcase()			core_put_hexa_uppercase.c
│   ├── lxy_put_trigger_hashflag_up()	core_put_absrtaction.c
│   └── lxy_put_unsigned_int_base()		core_utils_put_nbr_to_base.c
│
├── lxy_put_long_hexa_upperrcase()		core_put_hexa_uppercase.c
│   ├── lxy_put_trigger_hashflag_up()	core_put_absrtaction.c
│   └── lxy_put_unsigned_long_base()		core_utils_put_nbr_to_base.c
│
└── lxy_put_long_long_hexa_upperrcase()	core_put_hexa_uppercase.c
    ├── lxy_put_trigger_hashflag_up()	core_put_absrtaction.c
    └── lxy_put_size_t_base()			core_utils_put_nbr_to_base.c

```

---

## Author

Lexxythelizard

42 Berlin login: lenivorb

private Github:	https://www.github.com/Lexxythelizard
