#!/bin/bash

read -p "What size do you want the data set to be? " set_length

make
mkdir result

echo "[bash] Generating the input data..."
./data_generator.x $set_length > data.inp
echo "[bash] Input data generated succesfully!"
echo "[bash] Starting executions to collect results"
./program_tester.x data.inp $set_length
echo "[bash] Results colleted succesfully!"
rm data.inp
mv *.out ./result

make clean