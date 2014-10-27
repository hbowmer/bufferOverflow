bufferOverflow
==============

A project I wrote my Senior year at Wake Forest for my CSC 348: Network Security class. The project was aimed at exposing students to the process of using buffer overflow manipulation to carry out a variety of commands. Descriptions of each file is listed below.

**Important Details**
This exercise in breaching computer security was performed on a Debian-installed, AMD64 server on the Wake Forest network. AMD64 and Debian have security mechanisms built in that make buffer overflow attacks difficult. For the purpose of this project, several of these security mechanisms were disabled. First, Debian's address space randomization measure randomizes the starting position of the heap and stack. Change this feature by executing this command as root on your machine.

    # /sbin/sysctl -w kernel.randomize_va_space_=0

Debian also uses exec-shield to make the stack non-executable. This would render this exercise pointless, so it must be disabled. Additionally, Debian adds guard variables to functions with vulnerable objects that are checked when a function exists. To disable these features, a program must be compiled with them turned off. This can be done with the following command.

    $ gcc -fno-stack-protector -z execstack program.c

**skipLine.c**

This program changes the return address of the stack to skip the instruction "x = 1", so when the project terminates x is still assigned to 0.

**jumpShell.c**

This program jumps to shell code by changing the return address of the stack to the address of malicious amdshellcode (also included in this repository) to execute the "ls" command.

**overflowBuffer.c**

overflowBuffer.c is a more realistic rendition of the buffer overflow exploit. It works by placing the shell code and address in the array "largeString" and then copying the contents of "largeString" to the array "buffer".

**exploitBuffer1.c / exploitBuffer2.c / vulnerable.c**

This portion of the project explores the concept that there are usually two files involved in a buffer overflow exploit: one program with a vulnerability and another malicious program that seeks to exploit it. In this case, vulnerable.c contains a simple buffer overflow problem. The program reads the contents of a file "badfile" into the array "str" using the strcpy() function. Since strcpy() does not perform bounds checking, buffer overflows can occur. exploitBuffer.c creates the "badfile" filling it with malicious shell code. exploitBuffer1.c simply executes the "ls" command, while exploitBuffer2.c creates a shell the attacker can use. 
