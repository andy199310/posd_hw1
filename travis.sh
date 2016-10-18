#!/bin/sh
cd build
./posd_hw1 | tee output.txt
echo "Program Ended!"
count=$(grep 'There were no test failures' output.txt | wc -l)
if [ "$count" -eq "0" ];
  then
    echo "Error!"
    exit -1;
fi
echo "Success!"
exit 0
