#!/bin/bash

# tests to be launched at the root of the project

source "./tests/generic_tests.sh"

TEST_NAME="strace on simple executable"

TEST_FILE="./tests/samples/executable"

EXPECTED="strace $TEST_FILE"

MY_RESULT="./strace $TEST_FILE"

make_test "$TEST_NAME" "$EXPECTED" "$MY_RESULT"

echo "---"

TEST_NAME="strace on nanotekspice executable"

TEST_FILE="./tests/samples/nanotekspice"

EXPECTED="strace $TEST_FILE"

MY_RESULT="./strace $TEST_FILE"

make_test "$TEST_NAME" "$EXPECTED" "$MY_RESULT"

echo "---"

TEST_NAME="strace on my_sokoban executable"

TEST_FILE="./tests/samples/my_sokoban"

EXPECTED="strace $TEST_FILE"

MY_RESULT="./strace $TEST_FILE"

make_test "$TEST_NAME" "$EXPECTED" "$MY_RESULT"

echo "---"

TEST_NAME="strace on ls executable"

TEST_FILE="./tests/samples/ls"

EXPECTED="strace $TEST_FILE"

MY_RESULT="./strace $TEST_FILE"

make_test "$TEST_NAME" "$EXPECTED" "$MY_RESULT"

echo "---"