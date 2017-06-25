#!/bin/bash
LEVELDIR=level3

if [ -e $LEVELDIR ] ; then
    echo "The Level Directory already exists: $LEVELDIR"
    exit -1
fi

mkdir -m 755 $LEVELDIR
cd $LEVELDIR

#
# Create a welcoming file
#
echo "Welcome" > welcome.txt
chmod 777 welcome.txt

#
# Create some filled binary files
#
CURLEVEL=1
for ((d=1; d <= 5; d++))
do
    #
    # Create a subdirectoyr for a few more files
    #
    dname="subdir$CURLEVEL"
    if   (($d % 3 == 0))  ; then
        mkdir -m 700 $dname
    elif (($d % 3 == 1))  ; then
        mkdir -m 705 $dname
    else
        mkdir -m 750 $dname
    fi

    #echo "Entering subdirectory: $dname"
    cd $dname
    CURLEVEL=$(($CURLEVEL + 1))

    #
    # Create some files in this directory
    #
    FSIZE=$((11 * $d))
    TSIZE=$FSIZE
    NFILES=$((1 + $d))
    for ((i=1; i < $NFILES; i++))
    do
        #sleep $(($d % 2 + 1))
        fname="test-$TSIZE.dat"
        cmd="dd if=/dev/zero of=$fname bs=1k count=$TSIZE status=none"
        $cmd

        FSIZE=$(( $FSIZE * 7))
        TSIZE=$(( $FSIZE - $i))

        if  (($i % 3 == 0))  ; then
            chmod 755 $fname
        elif  (($i % 3 == 1))  ; then
            chmod 752 $fname
        else
            chmod 625 $fname
        fi
    done

    if   (($d % 2 == 0))  ; then
        cd -
    fi

done


exit 0

#dd if=/dev/zero of=file_to-create bs=1k count=1000

