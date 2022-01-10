#!/bin/bash

compile_program()
{
    make -C $1 re --silent
    make -C $1 clean  --silent
}

printTestName()
{
    TEST_NAME=${1:1}
    echo 
    echo "|>>>> $TEST_NAME <<<<|"   echo
}

isTestName()
{
    LINE=$1
    if [ "${LINE::1}" == "#" ]
    then
        return 1
    else
        return 0
    fi
}

do_tests()
{
    PROGRAM_NAME=$1
    TEST_FILE="./inputs_to_test"
    TEST_NO=1
    TOTAL_NUMBER_OF_TESTS=$(cat "$TEST_FILE" | wc -l)
    while [ $TEST_NO -le $TOTAL_NUMBER_OF_TESTS ]
    do
        INPUT_TO_TEST=$(sed -n "${TEST_NO}p" $TEST_FILE)
        isTestName "$INPUT_TO_TEST"
        if [ $? -eq 1 ]
        then
            printTestName "$INPUT_TO_TEST"
        else
            echo -n "Test Line: $TEST_NO -- "
            echo "Input: \""$INPUT_TO_TEST"\""
            ./$PROGRAM_NAME "$INPUT_TO_TEST"
        fi
        TEST_NO=$((TEST_NO + 1))
    done

}

PROGRAM_ROOT_DIR="./"
PROGRAM_NAME="convert"

compile_program $PROGRAM_ROOT_DIR
chmod 755 $PROGRAM_NAME
do_tests "$PROGRAM_NAME"