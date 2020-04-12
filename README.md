[![Bash Shell](https://badges.frapsoft.com/bash/v1/bash.png?v=103)](https://github.com/ellerbrock/open-source-badges/)
![GitHub contributors](https://img.shields.io/github/contributors/emmanavarro/simple_shell?style=plastic)

![simple](https://user-images.githubusercontent.com/60374349/79060145-12505c00-7c47-11ea-8eaf-d625418da2ca.png)

At its base, a shell is simply a macro processor that executes commands. The term macro processor means functionality where text and symbols are expanded to create larger expressions.

A Unix shell is both a command interpreter and a programming language. As a command interpreter, the shell provides the user interface to the rich set of GNU utilities. The shell is a program that takes commands from the keyboard and gives them to the operating system to perform On most Linux systems a program called bash (which stands for Bourne Again **Shell**, an enhanced version of the original Unix shell program, sh, written by Steve Bourne) acts as the shell program. [1](http://linuxcommand.org/lc3_lts0010.php)

This project is about building a simpler version of the Unix shell using the C programming language.

## :heavy_check_mark:Requirements
* All your files will be compiled on Ubuntu 14.04 LTS
* Your C programs and functions will be compiled with gcc 4.8.4
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to

## ⚙Compilation 

Your shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c`

## 📑Testing

Shells may be used interactively or non-interactively. In interactive mode, they accept input typed from the keyboard. When executing non-interactively, shells execute commands read from a file.

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
## 🚀Authors

**Laura Villan** ![GitHub followers](https://img.shields.io/github/followers/laucavv?label=Follow&style=social)
![Twitter Follow](https://img.shields.io/twitter/follow/laucavv23?label=%40laucavv23&style=social)

**Emma Navarro Millán** ![GitHub followers](https://img.shields.io/github/followers/emmanavarro?label=Follow&style=social)
![Twitter Follow](https://img.shields.io/twitter/follow/Ayy_Emma?label=%40Ayy_Emma&style=social)
