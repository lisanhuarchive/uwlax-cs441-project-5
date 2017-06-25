#!/bin/bash

TNUM=4
LNUM=1
for ((d=1; d <= $TNUM; d++))
do
    LEVELDIR=level$LNUM
    fname=setup-$LEVELDIR.sh
    if [ -e $LEVELDIR ] ; then
        echo "Directory does exists already: $LEVELDIR"
    elif [ -e $fname ] ; then
        sh $fname
    else
        echo "Filename does not exist: $fname"
    fi
    LNUM=$(($LNUM + 1))
done
