#!/bin/bash

if [ $( basename $(pwd) ) != test ] ; then
   cd test;
fi
PROG=../sudoku

for TEST in test-*.txt ; do
    SOLUTION=$(echo "$TEST" | sed -e 's/test/solution/')
    if cat "$TEST" | $PROG | tail -n +19 | diff - "$SOLUTION" ; then
	echo "Test $TEST OK"
    else
	echo "Test $TEST FAIL"
    fi
done

