#!/bin/bash

python3 -m venv venv
source venv/bin/activate

cd audiotools-3.1.1/
make install

cd ..

pip install --upgrade pip

pip install --upgrade setuptools
pip install -r requirements.txt
pip install eyed3
pip install colors.py
pip install SpeechRecognition
pip install pydub
pip install watchdog

