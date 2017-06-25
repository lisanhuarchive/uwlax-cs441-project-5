#!/bin/bash
LEVELDIR=level4

if [ -e $LEVELDIR ] ; then
    echo "The Level Directory already exists: $LEVELDIR"
    exit -1
fi

mkdir -m 755 $LEVELDIR
cd $LEVELDIR

#
# Create a welcoming file
#
echo "These test you ability to deal with links. Have fun" > welcome.txt
chmod 777 welcome.txt

#
# Create some directories
#

#
# -- Level 1
#
mkdir -m 755 subdir_1
cd subdir_1
mkdir -m 755 subdir_1_1
dd if=/dev/zero of=subfile_1_2.dat  bs=1k count=3 status=none
cd subdir_1_1
dd if=/dev/zero of=subfile_1_1_1.dat  bs=1k count=2 status=none
cd ..
cd ..
ln -s subdir_1/subdir_1_1 alink_1_1
ln -s subdir_1/subfile_1_2.dat alink_1_2.dat
#ln -s subdir_1/subfile_1_3.dat abadlink_1_2.dat

#
# -- Level 2
#
mkdir -m 755 subdir_2
cd subdir_2
ln -s ../subdir_2 subdir_2_1
dd if=/dev/zero of=subfile_2_2.dat  bs=1k count=3 status=none
mkdir -m 755 subdir_2_3
cd subdir_2_3
dd if=/dev/zero of=subfile_2_3_1.dat  bs=1k count=2 status=none
cd ..
cd ..

#
# -- Level 3
#
mkdir -m 755 subdir_3
cd subdir_3
mkdir -m 755 subdir_3_1
dd if=/dev/zero of=subfile_3_2.dat  bs=1k count=3 status=none
cd subdir_3_1
ln -s ../../subdir_3 subdir_3_1_1
dd if=/dev/zero of=subfile_3_1_2.dat  bs=1k count=3 status=none
ln -s ../subfile_3_2.dat subfile_3_1_3.dat
cd ..
cd ..
