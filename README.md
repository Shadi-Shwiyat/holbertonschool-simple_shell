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
| <pre>[shell.c](shell.c)</pre> | <pre>Entry point;</pre> | <pre>Main loop, recieve input from the Command Line Interface<br>parse and execute it.</pre> |
| <pre>[tokenizers.c](tokenizers.c)</pre> | <pre>char **hsh_tokenizer();<br>char **tokenizer_path();</pre> | <pre>Split the input string into a array of tokens.<br>Split the environment variable PATH into an array of tokens.</pre> |
| <pre>[validators.c](validators.c)</pre> | <pre>char *validate_input();<br>int validate_spaces();</pre> | <pre>Validate if PATH exists<br>Validate spaces, tabs and line breaks.</pre> |
| <pre>[exe_command.c](exe_command.c)</pre> | <pre>int hsh_execute();<br>int hsh_execute_builtins();</pre> | <pre>Fork process and replace the child with a new program.<br>Choose from an array of builtin functions.</pre> |
| <pre>[builtins.c](builtins.c)</pre> | <pre>int hsh_cd();<br>int hsh_setenv();<br>int hsh_unsetenv();<br>int hsh_env();<br>int hsh_exit();</pre> | <pre>Change directory.<br>Change or add and environment variable.<br>Delete an environment variable from the environment.<br>Print the environment variables list.<br>Terminate the main loop and exit the shell.</pre> |
| <pre>[the_helpers.c](the_helpers.c)</pre> | <pre>void sigintH();<br>char *str_concat();<br>void *_realloc();</pre> | <pre>Handles SIGINT (CTRL + C).<br>Concatenate two strings.<br>Reallocate a memory block.</pre> |

## System and Library calls

## Installation

## Example of Use

## Authors
