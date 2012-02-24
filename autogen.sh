#!/bin/sh

function run() {
	echo -ne "$1..."
	if $*; then
		echo "ok";
	else
		echo "bad";
	fi
}

run aclocal
run libtoolize --automake -c
run automake --foreign -a -c
run autoheader
run autoconf

./configure $*

