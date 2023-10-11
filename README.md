Simple_shell is a group project done by Ron and Sefakor.
This repository contains the files of the project, and will be compiled on Ubuntu 20.04 LTS using gcc.
The editors allowed for this project are; vi, emacs and vim.
The betty-style.pl and betty-doc.pl will be used to check for betty style on the codes.
The goal is to develop functionalities similar to those found in the sh shell.
The shell whould work like this in interactive mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
But would work in non-interactive mode like this:
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
