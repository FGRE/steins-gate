#!/bin/bash
if [ "$#" -ne 1 ]
then
    echo "usage: $0 <script.nss>"
    exit 1
fi
../nptools/nsbcompile2 $1
../nptools/npaextract nss.npa SteinsGate
mv ${1::-3}"nsb" nss/0_boot.nsb
mv ${1::-3}"map" nss/0_boot.map
mv nss.npa nss.npa.bak
../nptools/npapack nss
rm -fr nss
echo "TEST OUTPUT:" >> debug.out
../nptools/npcrypt "debug.out" "debug.out"
LANG=ja_JP.UTF-8 wine STEINSGATE.exe
mv nss.npa.bak nss.npa
../nptools/npcrypt "debug.out" "debug.out"
cat debug.out
rm debug.out
