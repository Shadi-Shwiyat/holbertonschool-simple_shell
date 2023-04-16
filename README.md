# Simple Shell

![simple shell](https://user-images.githubusercontent.com/118314635/230169165-29ce26e8-8524-4e78-9f4d-6bd767c0465a.png)

# Table of Contents
- [Description](#description)
- [File Structure](#file-structure)
- [System and Library calls](#system-and-library-calls)
- [Installation](#installation)
- [Example of Use](#example-of-use)
- [Authors](#authors)

## Description
This simple shell was created by Rob Farley and Shadi Shwiyat as a project for Holberton School of Computer Science.
It is a simple UNIX command interpreter written in the C programming language. The program uses bash commands it retrieves from the command line interface (CLI) that are inputed by the user.
The shell can be run in interactive and non interactive mode as shown below.

## File Structure
This table give a brief description of the files used for the simple shell to work, click on the names to get the source code.

| File | Content | Description |
| --- | --- | --- |
| <pre>[shell.h](shell.h)</pre> | <pre>Header of the project</pre> | <pre>Contains the structures, prototypes, macros and<br>external variables of the project.</pre> |
| <pre>[shell.c](shell.c)</pre> | <pre>int main.c;</pre> | <pre>Main loop, recieve input from the Command Line Interface<br>parse and execute it.</pre> |
| <pre>[tokenizers.c](tokenizers.c)</pre> | <pre>char **hsh_tokenizer();<br>char **tokenizer_path();</pre> | <pre>Split the input string into a array of tokens.<br>Split the environment variable PATH into an array of tokens.</pre> |
| <pre>[validators.c](validators.c)</pre> | <pre>char *validate_input();<br>int validate_spaces();</pre> | <pre>Validate if PATH exists<br>Validate spaces, tabs and line breaks.</pre> |
| <pre>[exe_command.c](exe_command.c)</pre> | <pre>int hsh_execute();<br>int hsh_execute_builtins();</pre> | <pre>Fork process and replace the child with a new program.<br>Choose from an array of builtin functions.</pre> |
| <pre>[builtins.c](builtins.c)</pre> | <pre>int hsh_cd();<br>int hsh_setenv();<br>int hsh_unsetenv();<br>int hsh_env();<br>int hsh_exit();</pre> | <pre>Change directory.<br>Change or add and environment variable.<br>Delete an environment variable from the environment.<br>Print the environment variables list.<br>Terminate the main loop and exit the shell.</pre> |
| <pre>[the_helpers.c](the_helpers.c)</pre> | <pre>char *str_concat();<br>void *_realloc();</pre> | <pre>Concatenate two strings.<br>Reallocate a memory block.</pre> |

## System and Library calls
This table lists all the System calls `2` and Library calls `3` used in this project, you could read more by clicking on their respective manual pages. 

| Name | Manual page | Brief description |
| --- | --- | --- |
| `access` | <pre>[man 2 access](https://man7.org/linux/man-pages/man2/access.2.html)</pre> | access() function checks whether the calling process can access the file pathname.  If pathname is a symbolic link, it is dereferenced. |
| `chdir` | <pre>[man 2 chdir](https://man7.org/linux/man-pages/man2/chdir.2.html)</pre> | chdir() function changes the current working directory of the calling process to the directory specified in one of its parameters. |
| `execve` | <pre>[man 2 execve](https://man7.org/linux/man-pages/man2/execve.2.html)</pre> | execve() function allows a process to execute another program. |
| `exit` | <pre>[man 3 exit](https://man7.org/linux/man-pages/man3/exit.3.html)</pre> | exit() function causes normal process termination. |
| `fork` | <pre>[man 2 fork](https://man7.org/linux/man-pages/man2/fork.2.html)</pre> | fork() function creates a new process by duplicating the calling process. The new process is referred to as the child process. The calling process is referred to as the parent process. |
| `free` | <pre>[man 3 free](https://man7.org/linux/man-pages/man3/malloc.3.html)</pre> | free() function frees the memory space from the heap, which must have been returned by a previous call to malloc(), calloc(), or realloc(). |
| `getcwd` | <pre>[man 3 getcwd](https://man7.org/linux/man-pages/man3/getcwd.3.html)</pre> | getcwd() function copies an absolute pathname of the current working directory. |
| `getenv` | <pre>[man 3 getenv](https://man7.org/linux/man-pages/man3/secure_getenv.3.html)</pre> | getenv() function searches the environment list to find the requested environment variable. |
| `getline` | <pre>[man 3 getline](https://man7.org/linux/man-pages/man3/getline.3.html)</pre> | getline() function reads an entire line from input, storing the address of the buffer containing the text into a pointer. |
| `isatty` | <pre>[man 3 isatty](https://www.man7.org/linux/man-pages/man3/isatty.3.html)</pre> | isatty() function tests whether a file descriptor refers to a terminal. |
| `malloc` | <pre>[man 3 malloc](https://man7.org/linux/man-pages/man3/malloc.3.html)</pre> | malloc() function dynamically allocates a single large block of memory with the specified size. |
| `perror` | <pre>[man 3 perror](https://man7.org/linux/man-pages/man3/sys_nerr.3.html)</pre> | perror() function produces a message on standard error describing the last error encountered during a call to a system or library function. || `strtok` | <pre>[man 3 strtok](https://man7.org/linux/man-pages/man3/strtok.3.html)</pre> | strtok() function breaks a string into a sequence of zero or more nonempty tokens. |
| `waitpid` | <pre>[man 2 waitpid](https://man7.org/linux/man-pages/man2/wait.2.html)</pre> | waitpid() function suspends execution of the calling thread until a child specified by pid argument has changed state. |
| `fprintf` | <pre>[man 3 fprintf](https://man7.org/linux/man-pages/man3/printf.3.html)</pre> | fprintf() function sends formatted output to a stream. |
| `setenv` | <pre>[man 3 setenv](https://man7.org/linux/man-pages/man3/setenv.3.html)</pre> | setenv() function adds a variable to the environment. |
| `unsetenv` | <pre>[man 3 unsetenv](https://man7.org/linux/man-pages/man3/setenv.3.html)</pre> | unsetenv() function deletes a variable from the environment. |
| `write` | <pre>[man 2 write](https://man7.org/linux/man-pages/man2/write.2.html)</pre> | write() function writes to a file descriptor. |

## Installation
First, clone this repository to your local machine:

```
$ git clone https://github.com/Shadi-Shwiyat/holbertonschool-simple_shell.git
```

Then, go to the repository folder:

```
$ cd holbertonschool-simple_shell
```

Compile it with the following command:

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

Now you can run the shell in interactive mode:

```
$ ./hsh
```

Or you can run it in non-interactive mode:

```
$ echo "ls -la" | ./hsh
```

## Example of Use
Interactive mode:
```
$ ./hsh
#$ ls
AUTHORS              exe_command.c         hsh     shell.c         README.md     validators.c
builtins.c  the_helpers.c  shell.h  man_1_simple_shell  tokenizers.c
#$ pwd
/root/holbertonschool-simple_shell
#$ exit
$
```

```
$ ./hsh
#$ ls -la
total 72
drwxr-xr-x  3 root root   232 Aug  7 23:01 .
drwxr-xr-x 14 root root  4096 Aug  8 12:22 ..
-rw-r--r--  1 root root   216 Aug  7 19:00 AUTHORS
-rw-r--r--  1 root root  4215 Aug  7 23:00 builtins.c
-rw-r--r--  1 root root  2456 Aug  7 23:00 executors.c
drwxr-xr-x  8 root root   201 Aug  7 23:00 .git
-rw-r--r--  1 root root  1567 Aug  7 23:00 the_helpers.c
-rwxr-xr-x  1 root root 22744 Aug  7 23:01 hsh
-rw-r--r--  1 root root  1919 Aug  7 23:00 shell.h
-rw-r--r--  1 root root  1782 Aug  7 23:00 shell.c
-rw-r--r--  1 root root  3703 Aug  7 18:58 man_1_simple_shell
-rw-r--r--  1 root root    29 Aug  7 18:36 README.md
-rw-r--r--  1 root root  2517 Aug  7 23:00 tokenizers.c
-rw-r--r--  1 root root  1749 Aug  7 23:00 validators.c
#$ exit
$ 
```

Non-interactive mode:
```
$ echo "env" | ./hsh
HOSTNAME=380dba7ae1b2
LANGUAGE=en_US:en
PWD=/root/holbertonschool-simple_shell
TZ=America/Los_Angeles
HOME=/root
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm
LESSOPEN=| /usr/bin/lesspipe %s
SHLVL=0
LC_ALL=en_US.UTF-8
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
OLDPWD=/
_=./hsh
$
```

## Authors
| [<img src="https://github.com/Shadi-Shwiyat.png" width=90><br><sub> Shadi Shwiyat </sub>](https://github.com/Shadi-Shwiyat) | [<img src="https://github.com/Nomad-Rob.png" width=90><br><sub> Robert Farley </sub>](https://github.com/Nomad-Rob) |
| :---: | :---: |

[Back to top](#simple-shell)<!--@Shadi-Shwiyat-->

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=60&section=footer"/>
</p>
