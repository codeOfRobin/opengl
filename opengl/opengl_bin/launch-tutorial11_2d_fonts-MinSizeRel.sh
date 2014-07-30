#!/bin/sh
bindir=$(pwd)
cd /Users/robinmalhotra2/Developer/opengl/OpenGL-tutorial_v0014_21/tutorial11_2d_fonts/
export DYLD_LIBRARY_PATH=:$DYLD_LIBRARY_PATH

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		 -batch -command=$bindir/gdbscript  /Users/robinmalhotra2/Developer/opengl/opengl/opengl_bin/MinSizeRel/tutorial11_2d_fonts 
	else
		"/Users/robinmalhotra2/Developer/opengl/opengl/opengl_bin/MinSizeRel/tutorial11_2d_fonts"  
	fi
else
	"/Users/robinmalhotra2/Developer/opengl/opengl/opengl_bin/MinSizeRel/tutorial11_2d_fonts"  
fi
