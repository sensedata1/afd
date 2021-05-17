#!/usr/bin/env bash

clear
echo "Pulling image..."
OUT=$(docker pull sensedata1/afd:latest)
echo "${OUT}"
if [[ ${OUT} == *"up to date"* || *"newer image"* ]]; then
    echo
    read -p "Drop your AJ downloads folder here... " AJTEMP
    echo ${AJTEMP}
    docker run --rm \
           -v "${AJTEMP}":/AJTEMP \
           -it sensedata1/afd:latest
else
    echo "Image pull unsuccessful, exiting"
    exit
fi
