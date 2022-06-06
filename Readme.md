# UNIX System File Calls
## Command Line Based User Interface Program
### Description

The repo contains three header files :
- files.h : File Handling
- pipes.h : Pipe Handling 
- directory.h : Directory Handling

And a main c file(main.c) to execute the program as a whole.
### Usage
Compile the main.c file
```sh
gcc -o main main.c
```
The command line syntax to execute the program is as follows:
```sh
./main <Type of file> <Operation> <Parameters>
```
Where , 
<Type of file> = file , pipe , directory
#### <Operation>
##### File Operation
- create : Create New File 
    - < Parameter > : < File Name > < Permissions >
- open / close : Open or Close a file.
    - < Parameters > : <File Name> < Mode (read/write) >
- write : Write data to a file.
    - < Parameter > : < File Name > < Index of Starting> <Size> / <Content >
- read : Read data from a file.
    - < Parameter > : < File Name > < Index of Starting > < Size >
- chmod : Change permissions of a file
    - < Parameters>: < file name > < New Permissions >
- info : Print imformation related to the file.
    - < Parameter >: < file name >
##### Pipes OPeration
- pipe : Create a unamed/named pipe
    - < Parameter > : unnamed/named <name_of_pipe>
##### Directory Operation
- create : Create new directory
    - < Parameter > : create < File name > < Permission >
- chmod : Change directory permission
    - < Parameter > : < file name > < New Permission >
- info : Print imformation related to the directory.
    - < Parameter >: < file name >
## System Calls implemented 
| Task | System Call(s) Used |
|---|---|
| Files | `creat`, `open`, `close`,`write`,`read`,`chmod`,`stat` , `lseek` |
|Pipes| `pipe`, `mknod` |
| Directory | `mkdir`, `chmod`, `stat` |
| Advanced System Calls | `dup` (`dup2`), `pipe`, `unlink` |

## Author
    Name: Abhigyan Mishra
    Roll Number: 01
    M.Sc. Computer Science
    Department of Computer Science, University of Delhi

