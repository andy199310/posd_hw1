#!/bin/sh
cd build
./posd_hw1 | tee output.txt
echo "Program Ended!"
tail output.txt
count=$(grep 'There were .* failures' output.txt | wc -l)
if [ "$count" -ne "0" ];
  then
    echo "Error!"
    exit -1;
fi
echo "Success!"
exit 0
