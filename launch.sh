#!/bin/bash

build="build"

if [ -e $build ]
then
	if [ -e $build/Makefile ]
	then
		echo "cd $build && make"
		cd $build && make
	else
		echo "cd $build && cmake .."
		cd $build && cmake ..
		echo "make"
		make
	fi
else
	echo "mkdir -p $build && cd $build"
	mkdir -p $build && cd $build
	echo "cmake .."
	cmake ..
	echo "make"
	make
fi
echo "./convexHull"
./convexHull
echo "cd ../scripts"
cd ../scripts
echo "python3 graph.py"
python3 graph.py
