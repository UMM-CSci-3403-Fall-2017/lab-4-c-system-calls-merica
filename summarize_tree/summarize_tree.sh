#!/bin/bash

#the directory that contain the files

directories=$1
homedir=$(pwd)

#changing into the directories
cd $directories

#Returns the amount of files
regular_files=$(find -type f | wc -l)

#Returns the amount of directories
dir_number=$(find -type d | wc -l)

#going back to the home directory
cd $homedir

echo "There were $dir_number directories."
echo "There were $regular_files regular files."
