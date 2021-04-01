#!/bin/bash

## Print colors
DEFAULT="\e[0m"
BOLD="\e[1m"
DIM="\e[2m"
UNDLN="\e[4m"
SHINE="\e[5;37m"
RODE="\e[9;37m"

BLACK="\e[30m"
RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
MAGEN="\e[35m"
CYAN="\e[36m"
WHITE="\e[1;37m"
## !Print colors

EXIT_FAILURE=84
EXIT_SUCCESS=0

function display_testFailure()
{
    echo -e $RED "TEST FAILURE" $DEFAULT
    return $EXIT_FAILURE
}

function display_testSuccess()
{
    echo -e $RED "TEST FAILURE" $DEFAULT
    return $EXIT_SUCCESS
}

function make_test()
{
    echo -e $YELLOW "TEST:" $DEFAULT "$1"
    OUTPUT_1="./file_output_1"
    OUTPUT_2="./file_output_2"

    CMD_1=$( $2 2> "$OUTPUT_1" )
    CMD_2=$( $3 2> "$OUTPUT_2" )

    diff --color=always $OUTPUT_1 $OUTPUT_2 > /dev/null
    RETURN_VAL=$?
    rm $OUTPUT_1 $OUTPUT_2
    if (( $RETURN_VAL != 0 )); then
        display_testFailure
        return $EXIT_SUCCESS
    fi

    if [ "$CMD_1" == "$CMD_2" ]; then
        display_testSuccess
        return $EXIT_SUCCESS
    else

        $2 &>> $OUTPUT_1
        $3 &>> $OUTPUT_2

        # diff --color=always $OUTPUT_1 $OUTPUT_2
        rm $OUTPUT_1 $OUTPUT_2

        display_testFailure
        return $EXIT_FAILURE
    fi

}
