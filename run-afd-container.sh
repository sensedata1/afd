#!/usr/bin/env bash

clear
OUT=$(docker pull sensedata1/afd:latest)
echo "${OUT}"
if [[ ${OUT} == *"up to date"* ]]; then
    echo
    read -p "Drop your AJ downloads folder here... " AJTEMP
    echo ${AJTEMP}
    docker run \
           -v "${AJTEMP}":/AJTEMP \
           -it sensedata1/afd:latest
else
    echo "Image pull unsuccessful, exiting"
    exit
fi
