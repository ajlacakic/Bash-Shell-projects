names :

Hannan Foco
Ajla Cakic

list of files:
11advanced.c
11basic.c
12advanced.c
12basic.c
12inter.c
13additionaly.c
13.advanced.c
13basic.c
colored_shell.c


Project: Shell -Theoretical part
Provide a concise and descriptive answer to the following questions.
Question 1.5.1: The following actions, do they require the OS to use kernel mode
or
user mode is sufficient? Explain:
● Starting a new process:
This action requires the OS to use kernel mode because it involves allocating
system
resources such as memory, CPU time, and file descriptors, which can only be
done by
the kernel. The kernel manages process creation, scheduling, and memory
allocation,
which all require privileged access that is only available in kernel mode.
● Multiplying two floating numbers stored in an application’s memory.
This action can be performed in user mode. Arithmetic operations like
multiplication
can be executed entirely within the user-space application without needing kernel

inter-
vention. User mode is sufficient as long as the operation involves only accessing

and
manipulating data within the application's memory space.
● Writing the results of the multiplication to a temporary log file on disk.
● This action requires the OS to use kernel mode. Writing to a file on disk involves

in-
teracting with hardware devices and managing file system operations, which are

privi-

leged tasks handled by the kernel. The kernel provides system calls like write() to

fa-
cilitate file I/O operations, ensuring data integrity and managing access

permissions.

Question 1.5.2: Explain the purpose of a system call. Describe how control passes
to
the kernel when executing a system call.
The purpose of a system call is to provide a controlled mechanism for user-space

ap-
plications to request services or resources from the operating system. These

services
may include tasks such as I/O operations, process management, memory

manage-
ment, and file system access.When executing a system call, control passes to the

ker-
nel through a software interrupt or trap instruction triggered by the user-space

applica-
tion. The process typically involves the following steps:

• Triggering the System Call: The user-space application makes a system call by
invoking a special function provided by the operating system, such as write() or
fork().
• Context Switch to Kernel Mode: Upon receiving the system call, the CPU
switches from user mode to kernel mode. This transition involves a privilege level
change, allowing the kernel to access privileged resources and perform privileged
operations.
• System Call Handling: The kernel identifies the requested system call and
executes the corresponding kernel routine to fulfill the requested service. This

may involve accessing hardware devices, managing system resources, or inter-
acting with other parts of the operating system.

• Returning to User Mode: After completing the system call, the kernel prepares
the return values (if any) and switches the CPU back to user mode. The control
returns to the user-space application, which continues its execution from the
point of the system call.
When a user-space application wants to write data to a file, it invokes the write()
system

call. The CPU switches to kernel mode, and the kernel handles the write

operation, en-
suring proper access permissions and managing file system buffers. Once the

write op-
eration is completed, control returns to the user-space application, allowing it to

contin-
ue its execution.

Question 1.5.3: Consider a parent process P that has forked a child process C in
this
program.
A. In the given scenario, when a child process is forked from a parent process, it

essen-
tially creates a copy of the parent's memory space. This means that the child

process
inherits the values of variables from the parent at the time of forking. However, any

sub-
sequent changes made by the parent process after forking will not affect the child

process.
So, if the value of variable a in the parent process is 6, and then a child process is
forked, the child process will still have the original value of a, which is 5, because it

in-
herited this value when it was forked from the parent. Therefore, when the child

process
prints the value of a, it will indeed be 5.
B. When a file descriptor (fd) is closed in the parent process after forking, it means
that
the associated file or resource is no longer available for reading or writing. The
child
process inherits all open file descriptors from the parent at the time of forking.
However,
since the parent closes the file descriptor immediately after forking, the child
process
will find that the file descriptor is already closed when it attempts to read from it.
Attempting to read from a closed file descriptor will result in failure, as the file

descrip-
tor is no longer valid for reading. The operating system will return an error

indicating

that the file descriptor is invalid or that the file is not open. Therefore, any attempt
by
the child process to read from the file descriptor will not succeed.



• Assignment Outline:
Implemented basic shell functionality, alongside with instructions as : simulating
prompt, file operations (ls, mkdir, uptime, sl) with redirecting output to a text file
and a variation of the sl command which is different from the original one.
Implemented system calls : fork(), wait(), exec(), vfork(), execl() and a fork bomb.



• Compilation Instructions:
To compile the shell program, use the following commands:
gcc -Wall -o shell first.c
./shell
our task compilation:
1.1 basic : gcc -Wall -o first 11basic.c
./first
1.1 advanced : gcc -Wall -o first 11advanced.c
./first
1.2 basic: gcc -Wall -o second 12basic.c
./second ls
./second mkdir newdir
./second uptime
./second sl //train animation with system() command
1.2 intermediate: gcc -Wall -o second 12inter.c
./second ls -a
./second mkdir newdirectory -p
./second uptime
./second sl // custom sl that launched rocket
1.2 advanced: gcc -Wall -o second 12advanced.c
./second ls >file.txt
./second uptime > file3.txt
./second sl >file4.txt // custom sl that prints train sound and redirects output to a
file

1.3 basic:gcc -Wall -o third 13basic.c
./third //prints also timestamp
1.3 advanced : gcc -Wall -o third 13advanced.c
./third
1.3 additional :gcc -Wall -o bomb 13additionaly.c
./bomb
1.4 Compile the colored shell program using GCC, with warnings enabled (-Wall), and
name the output executable "simple_shell" (-o simple_shell). Then, execute the
"simple_shell" program by typing ./simple_shell.
This process creates a custom shell interface with colored prompts and user input.
