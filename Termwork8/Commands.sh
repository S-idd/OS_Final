#!/bin/bash

echo "The Current Working Directory Is : "

pwd

echo "Enter The Directory Name To Change As Current Working Directory : "

read d1

cd $d1

mkdir OS_LAB

echo "OS_LAB Folder Created "

echo "Enter The Name Of Directory To Be Removed : "

read d2

rmdir $d2

echo "Enter The Source File Name : "

read f1

echo "Enter The Destination File Name : "

read f2

cp $f1 $f2

echo "File Copied Sucessfully"

mv $f1 $f2 OS_LAB

echo "Both The File Moved To The OS_LAB Folder "

ls -l OS_LAB

cd OS_LAB

echo "Enter The File Name To Remove : "

read f 

rm $f

echo "File $f Removed Succesfully"

cd ..

echo "Moved Back To Parent Directory"



