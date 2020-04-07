# Simple shell

This project is about building a simpler version of the Unix shell using the C programming language.

## Requirements
* All your files will be compiled on Ubuntu 14.04 LTS
* Your C programs and functions will be compiled with gcc 4.8.4
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to

## Compilation

Your shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c`

## Testing

Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
And also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Authors

**Laura Villan**

- Twitter: [@laucavv23](https://twitter.com/laucavv23)
- Github: [@laucavv](https://github.com/laucavv)

**Emma Navarro Millán**

- Twitter: [@Ayy_Emma](https://twitter.com/Ayy_Emma)
- Github: [@emmanavarro](https://github.com/emmanavarro)