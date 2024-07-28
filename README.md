#Simple Version Control System (VCS)

This project is a simple version control system similiar to 'git' with minimal functionality using C. It allows to initialize a repo, add files, commit changes, and checkout different versions of files. Note that is designed to work on Linux systems.

## Features

- Initialize a new VCS repo
- Add files to the repo
- Commit changes with messages
- View commit logs
- Checkout specific versions of files

## System requirements

- Linux OS
- `gcc` for compiling the source code

### Getting started

### installation 

1. Clone the repo :
     ```sh
     git clone https://github.com/nikhilmb002/Simple-VCS.git
     cd Simple-VCS/vcs
     ```

2. Compile the source code :
   ```sh
   make
   ```

3. Add the compiled `vcs` to bashrc:
   ```sh
   alias vcs ='cd /path/to/vcsdir ;./vcs'
   ```

### Usage

1. **Initialize a new repos : **
   ```sh
   vcs init
   ```
2. **Add files to the repo : **
   ```sh
   vcs add <filename>
   ```
3. **Commit changes with a msg : **
   ```sh
   vcs commit <filename> <commit_msg>
   ```
4. **View Commit logs : **
   ```sh
   vcs log
   ```
5. **Checkout a specific version of a file : **
   ```sh
   vcs checkout <filename> <version_number>
   ```

### Example 

```sh
#Initialize the repo
vcs init

#Add a file to the repo
cat ex.txt > "abcd"
vcs add ex.txt

#Commit the changes
vcs commit ex.txt "initial commit"

#Modify the file
cat ex.txt > "abcdefgh"

#Commit the changes
vcs commit ex.txt "added more content"

#View commit logs
vcs log

#Checkout a specific version of the file
vcs checkout ex.txt 1

