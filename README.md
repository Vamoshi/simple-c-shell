
# Simple Shell Program in C

This is a simple shell program implemented in C. The program reads user input, tokenizes the command, and uses `fork()` and `execvp()` system calls to execute the command. The current time is displayed before each command prompt.

## Features

- Displays the current time before each command prompt.
- Supports basic shell commands like `ls`, `pwd`, etc.
- Exits when the user types `exit`.
- Handles child process creation and execution using `fork()` and `execvp()`.
- Error handling for unknown commands and unsuccessful child process creation.

## Prerequisites

Ensure that GCC (GNU Compiler Collection) is installed on your system.

### Installing GCC

#### On Linux:

**Ubuntu** or **Debian-based** systems:

```bash
sudo apt update
sudo apt install gcc
```

**Fedora**, **RHEL**, or **CentOS**:

```bash
sudo dnf install gcc
```

**Arch Linux**:

```bash
sudo pacman -S gcc
```

To verify the installation:

```bash
gcc --version
```

#### On Windows:

To install GCC on Windows, you can use [MinGW](http://www.mingw.org/) (Minimalist GNU for Windows) or [Cygwin](https://www.cygwin.com/). 

**MinGW Installation Steps**:
1. Download the MinGW installer from the [MinGW website](http://www.mingw.org/).
2. Run the installer and select the `gcc` package.
3. Follow the prompts to complete the installation.
4. Add the path to MinGW (`C:\MinGW\bin`) to your system’s PATH environment variable:
   - Right-click on `This PC` or `Computer` > `Properties` > `Advanced system settings` > `Environment Variables`.
   - Find the `Path` variable in `System variables`, click `Edit`, and add `C:\MinGW\bin`.

To verify the installation:

```bash
gcc --version
```

**Cygwin Installation**:
1. Download and run the Cygwin installer from [Cygwin’s official site](https://www.cygwin.com/).
2. During installation, select the `gcc-core` package.
3. Follow the steps to complete the installation.
4. Add the Cygwin `bin` directory (e.g., `C:\cygwin64\bin`) to your PATH environment variable.

## Building the Program

Clone the repository and navigate to the directory containing the source file. Use GCC to compile the program:

```bash
gcc -o simple_shell simple_shell.c
```

This will create an executable file named `simple_shell`.

## Running the Program

### On Linux or macOS:

Run the compiled program using:

```bash
./simple_shell
```

### On Windows:

Run the compiled program using:

```bash
simple_shell.exe
```

If you encounter issues with `fork()` or `execvp()` on Windows, consider running the program in a Linux environment using [Windows Subsystem for Linux (WSL)](https://docs.microsoft.com/en-us/windows/wsl/) or using a virtual machine with Linux installed.

## Usage

- The program displays the current time before each command prompt.
- Type any valid shell command and press Enter to execute it.
- To exit the shell, type `exit` and press Enter.

## References

- [GeeksforGeeks - Array of Strings in C](https://www.geeksforgeeks.org/array-of-strings-in-c/)
- [Stack Overflow - Split String into Tokens](https://stackoverflow.com/questions/15472299/split-string-into-tokens-and-save-them-in-an-array)
- [Tutorials Point - Local Time Function](https://www.tutorialspoint.com/c_standard_library/c_function_localtime.htm)
- [Execvp Documentation](https://support.sas.com/documentation/onlinedoc/ccompiler/doc/lr2/execvp.htm)

For more details, check out the comments and links within the code.

## License

This project is licensed under the MIT License.
