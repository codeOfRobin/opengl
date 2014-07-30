#!/bin/sh
bindir=$(pwd)
cd /Users/robinmalhotra2/Developer/opengl/OpenGL-tutorial_v0014_21/tutorial09_vbo_indexing/
export DYLD_LIBRARY_PATH=:$DYLD_LIBRARY_PATH

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		 -batch -command=$bindir/gdbscript  /Users/robinmalhotra2/Developer/opengl/opengl/opengl_bin/MinSizeRel/tutorial09_vbo_indexing 
	else
		"/Users/robinmalhotra2/Developer/opengl/opengl/opengl_bin/MinSizeRel/tutorial09_vbo_indexing"  
	fi
else
	"/Users/robinmalhotra2/Developer/opengl/opengl/opengl_bin/MinSizeRel/tutorial09_vbo_indexing"  
fi
