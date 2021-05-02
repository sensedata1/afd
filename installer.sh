#!/bin/bash

source afd_venv/bin/activate
LAST_AUDIOTOOLS_FILE='lib/python3.7/site-packages/audiotools/wavpack.py'

if [ ! -f $LAST_AUDIOTOOLS_FILE ]; then
cd audiotools-3.1.1/
make install
fi

pip install --upgrade pip

pip install --upgrade setuptools
pip install -r requirements.txt
pip install eyed3
pip install colors.py
pip install SpeechRecognition
pip install pydub
pip install watchdog

