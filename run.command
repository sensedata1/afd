#!/bin/bash

SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
#echo $SCRIPTPATH

echo activating venv...
sleep 1
source $SCRIPTPATH/afd_venv/bin/activate
echo python3 directory = $(which python3)
python3 $SCRIPTPATH/AudioFormatDetective7LLZwm.py
