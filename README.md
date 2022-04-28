# 6502 Assembler

Basic 6502 Assembler. Needs plenty of work still :)   

# How To Build  
See [Build Instructions](Documentation/BuildInstructions.md)  

# TODO List
- [X] Convert non instruction set instructions (Labels)
  - [X] Handle own line labels with colons (ie LOOP:)
  - [X] Have translate look in labels for string that follows a branch instruction
  - [X] Correct labels having wrong value pair (fix program counter incrementation)
- [ ] Syntax Checking
  - [ ] Parentheses
  - [ ] Brackets
- [ ] More Tests
- [X] Documentation
  - [X] Building
  - [X] Usage
- [X] Build Scripts
  - [X] Build Script for Tests
  - [X] Build Script That Builds Assembler and Tests

# Resources Used  

[6502.org](http://www.6502.org/tutorials/6502opcodes.html)  
[Easy 6502](https://skilldrick.github.io/easy6502/)
