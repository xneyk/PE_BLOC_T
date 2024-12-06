#!/bin/bash
make
mkdir result

for i in {1..16}; do
   echo "[bash] starting round $i"
   ./data_generator.x 64 $((2 ** i)) > 2_$((i)).out
   ./program_tester.x 2_$((i)).out 64 $((2 ** i))
   rm 2_$((i)).out
   mv *.out ./result
   echo "[bash] finished round $i"
done

make clean