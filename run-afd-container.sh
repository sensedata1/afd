#!/usr/bin/env bash
#read -p "Drop downloads folder here" AJTEMP
docker run \
       -v \
       /Users/blordnew/Downloads/AJ\ TEMP\ DOWNLOADS:/AJTEMP \
       -it sensedata1/afd:latest \
       python AudioFormatDetectiveIMAP2CON.py

