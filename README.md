# VCS-1
<img align="right" src=https://www.sundance.com/wp-content/uploads/docs/sundance_logo_105.png>
This repository stores the VCS-1 source code and documentation.

# Directory structure
[See the repository structure](https://github.com/SundanceMultiprocessorTechnology/VCS-1/blob/master/directorySctructure.md)

## VCS-1 documentation
All the pdf documents can be found in the [Documentation](https://github.com/SundanceMultiprocessorTechnology/VCS-1/tree/master/Documents) folder. There is also relevant information inside each one of the repository folder and in the [wiki](https://github.com/SundanceMultiprocessorTechnology/VCS-1/wiki).

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
$ cd $HOME/Development
$ git clone https://github.com/SundanceMultiprocessorTechnology/VCS-1.git
```

OR using ssh
```
$ cd $HOME/Development
$ git clone git@github.com:SundanceMultiprocessorTechnology/VCS-1.git
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
