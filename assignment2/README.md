# **Operating systems and networks**
## **Assignment 2:** Implementing CShell

**P Shiridi kumar**
**2021121005**
***
- Assignment Directory structure and contents:
    ```
        2021121005_Assignment2
        ├─ README.md
        ├─ cd.c
        ├─ delete_comm.c
        ├─ echo.c
        ├─ headers.h
        ├─ history.c
        ├─ ls.c
        ├─ main.c
        ├─ makefile
        ├─ pinfo.c
        ├─ prompt.c
        ├─ prompt.h
        ├─ pwd.c
        ├─ repeat.c
        ├─ split.c
        └─ syscom.c
    ```
- To execute the shell compile the makefile by opening the terminal and then type make in the terminal.
- After succesfully compiling the makefile type ./a.out the terminal to run the shell.

- Functionalities and commands implemented in the assignment:
    - **cd(user defined,cd.c)** : used to change the directory for a given symbolic path or regular path. if no path is given the shell will cd to home directory.
    
    - **ls(user defined,ls.c)** : Displays the list of files and directories for a given directory(if no path is given it will display for cwd). Implemented with two different flags -l and -a and also a combination of both(-l used for displaying the detailed stats about the file and directory and -a  for displaying the names of the files including hidden files and .files)

    - **echo(user defined,echo.c)** : Prints the given argument into terminal

    - **pinfo(user defined,pinfo.c)** : Displays the process info for a given pid(pid,exec path,vitual memory,status).If no pid is given it displays the current executing process info.

    - **Made System commands to run  both in background and foregorund(syscom.c)**:eg(gedit ,gedit &,emacs ,emacs &,vi ,vi &)

    - **Exit status of a backgorund process is disaplayed whenever it ends**

    - **repeat (user defined,repeat.c):** repeats a specified command for n number of times(parameters are n and specified command its parameters)

    - **History (user defined,history.c)** :Displays the latest n commands(n<=20) entered across all sessions of the shell. by default if no parameter is passed it displays latest 20 commands enteres in the shell ,if n is specified it displays latest n commands.

    - **NOTE:** **Executing the shell for the first time itself will create a history2021121005osn.txt file in
    the originl home directory of the executing system and any file with the same name might get replaced.**

    - **Libraries used**:
        ```
        stdio.h
        unistd.h
        stdlib.h
        fcntl.h
        limits.h
        string.h
        dirent.h
        sys/stat.h
        sys/wait.h
        ```

