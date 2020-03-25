#!/bin/bash
echo " "
echo "Run example in debug mode"
time ./example_debug &> /dev/null
echo " "
echo "Run example in release mode"
time ./example_release &> /dev/null
