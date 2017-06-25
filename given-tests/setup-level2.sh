#!/bin/bash
LEVELDIR=level2

if [ -e $LEVELDIR ] ; then
    echo "The Level Directory already exists: $LEVELDIR"
    exit -1
fi

mkdir -m 755 $LEVELDIR

touch $LEVELDIR/hello.txt
chmod 600 $LEVELDIR/hello.txt
echo "Hello World" > $LEVELDIR/hello.txt

touch $LEVELDIR/empty.txt
chmod 624 $LEVELDIR/empty.txt

mkdir -m 700 $LEVELDIR/emptydir

