#!/bin/bash

set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

YELLOW=$(tput setaf 190)
WHITE=$(tput setaf 7)
POWDER_BLUE=$(tput setaf 153)
RED=$(tput setaf 1)

trap 'last_command=$current_command; line_number=$LINENO; current_command=$BASH_COMMAND' DEBUG
trap 'printf "${RED}ERROR: \"${last_command}\" command failed with exit code $?.${WHITE}\n"' ERR

cd $SCRIPT_DIR

if [ "$1" == "--tests" ]; then

    printf "\n"
    printf "${YELLOW}[RUNNING TESTS]${WHITE}\n"
    printf "\n"

    TESTS=(Tokenizer Translate SymbolTable)

    for test in ${TESTS[@]}; do
        printf "${YELLOW}${test} Tests \n======================================================${WHITE}\n\n"
        if [ ! -d $SCRIPT_DIR/Tests/$test/Build ]; then
            mkdir $SCRIPT_DIR/Tests/$test/Build
        fi
        cd $SCRIPT_DIR/Tests/$test/Build
        cmake ..
        make
        ./${test}Tests
    done

fi

printf "\n"
printf "${YELLOW}[BUILDING ASSEMBLER]${WHITE}\n"
printf "\n"

if [ ! -d Build ]; then
    mkdir $SCRIPT_DIR/Build
fi

cd $SCRIPT_DIR/Build
cmake ..
make

printf "\n"

printf "${POWDER_BLUE}[SUCCESS]
================================================================================\n
All tests passed. Build successful. Exectuable can be found in
the Build folder located in the source directory. Assembler takes
three command line arguments, ./Whuty6502Assembler arg1 arg2, where
arg1 is the source code file and arg2 is the name of the output
file that is generated.\n${WHITE}"

printf "\n"
