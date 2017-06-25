#!/bin/bash

TNUM=4
LNUM=1
for ((d=1; d <= $TNUM; d++))
do
    LEVELDIR=level$LNUM
    if [ -e $LEVELDIR ] ; then
        rm -rf $LEVELDIR
    fi
    LNUM=$(($LNUM + 1))
done
