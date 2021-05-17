#!/usr/bin/env bash

docker pull sensedata1/afd:latest
if [[ $? == 0 ]];
then
    read -p "Drop your AJ downloads folder here... " AJTEMP
    echo ${AJTEMP}
    docker run \
           -v "${AJTEMP}":/AJTEMP \
           -it sensedata1/afd:latest
    #       python AudioFormatDetectiveIMAP2CON.py
else
    echo "Image pull unsuccessful, exiting"
    break
fi
