#!/bin/bash
if [ "$#" -ne 2 ]
then
    echo "usage: $0 <script.nss> [0=fgre | 1=nitroplus]"
    exit 1
fi
../nptools/nsbcompile2 $1
../nptools/nsbcompile2 "tests/libtest.nss"
../nptools/npaextract nss.npa SteinsGate
mv tests/libtest.nsb nss/
mv tests/libtest.map nss/
mv ${1::-3}"nsb" nss/0_boot.nsb
mv ${1::-3}"map" nss/0_boot.map
mv nss.npa nss.npa.bak
../nptools/npapack nss
rm -fr nss
echo "TEST OUTPUT:" >> debug.out
../nptools/npcrypt "debug.out" "debug.out"
if [ "$2" -eq 1 ]
then
    LANG=ja_JP.UTF-8 wine STEINSGATE.exe
else
    gdb --args ./steins-gate --script="$1" --debug=1
fi
mv nss.npa.bak nss.npa
../nptools/npcrypt "debug.out" "debug.out"
cat debug.out
rm debug.out
