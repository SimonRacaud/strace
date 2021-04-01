#!/bin/bash

# tests to be launched at the root of the project

EXIT_FAILURE=84
EXIT_SUCCESS=0

if !(test -f "./strace") ; then
    exit $EXIT_FAILURE
fi


./tests/executables.sh

return $?
