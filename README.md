# VCS-1
This repository stores the VCS-1 source code.

# Directory structure
[DirectoryStructure](https://github.com/SundanceMultiprocessorTechnology/VCS-1/blob/master/directorySctructure.md)

# Managing the Repository
## Meeting the requirements
```
$ sudo apt update
$ sudo apt upgrade -y
$ sudo apt install tree git -y
$ mkdir -p $HOME/Development
```
## Clone
using https
```
$ git clone https://github.com/SundanceMultiprocessorTechnology/VCS-1.git
```

using ssh
```
$ cd $HOME/Development
$ git@github.com:SundanceMultiprocessorTechnology/VCS-1.git
```

## update
```
$ cd $HOME/Development/VCS-1
$ git pull
```

## commit (only available to authorised users)
```
$ cd $HOME/Development/VCS-1
$ ./push.sh
```


2019 (c) GPLv3 - Sundance Multiprocessor Technology Ltd.
