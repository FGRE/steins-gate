#!/bin/bash
../nptools/nsbcompile2 $1
../nptools/npaextract nss.npa SteinsGate
mv ${1::-3}"nsb" nss/0_boot.nsb
mv ${1::-3}"map" nss/0_boot.map
mv nss.npa nss.npa.bak
../nptools/npapack nss
rm -fr nss
LANG=ja_JP.UTF-8 wine STEINSGATE.exe
mv nss.npa.bak nss.npa
