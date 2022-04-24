# Usage
First, read [Build Instructions](BuildInstructions.md) to generate the assembler.  

# The Executable
An executable called *Whuty6502Assembler* will be in the Build/ folder of the root directory.  

# Assembling

*Note*: You **MUST** be in the Build/ folder for the following steps

The executable ***./Whuty6502Assembler*** takes three command line arguments.  
- ./Whuty6502Assembler
- Source Code File (ie. test.asm)
- Output file name (ie. test)

# Example

Lets say we have a test file called ***test.asm*** that looks like this:
```asm
LDA #$01
STA $0200
LDA #$05
STA $0201
LDA #$08
STA $0202
```
*Credit [Easy 6502](https://skilldrick.github.io/easy6502/) for the sample code*

***
To assemble this program, run: 
```commandline
./Whuty6502Assembler test.asm test
```
***

This will create the binary file ***test*** and put it in the Build/ directory.

Here is the output of ***test***:
```
10101001
00000001
10001101
00000010
10101001
00000101
10001101
00000001
00000010
10101001
00001000
10001101
00000010
00000010
```