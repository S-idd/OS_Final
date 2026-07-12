#!/bin/bash

echo "Enter The directory Name To Count The Number Of Files : "

read d1

fc=$(find "$d1" -type f | wc -l)

echo "Number Of Files In The $d1 Are $fc"

echo "Enter The Folder Name To Count The Number Of Nested Folder : "

read d2

dc=$(find "$d2" -type d | wc -l)

echo "Total Sub - Directores In $d2 : $dc"

echo "Enter File Name To Change Permission"

read f

chmod u+x,g+w "$f"

ls -l "$f"

echo "Perimission Changed Succesfully"

