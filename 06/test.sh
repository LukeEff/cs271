!# /bin/bash

make clean
make

echo "Testing incorrect num of arguments: 0 args:"
./main

echo "Testing incorrect num of arguments: 3 args:"
./main arg0 arg1 arg2

echo "Testing too many instructions (please set MAX_INSTRUCTIONS to small num)"
#./main Pong.asm

echo "Testing cannot find file:"
./main missing-file.404

echo "Testing invalid label:"
#./main invalid-label.asm

echo "Testing symbol already exists:"
#./main symbol-exists.asm

echo "Testing invalid a instruction:"
./main invalid-a-instruction.asm
