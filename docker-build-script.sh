#!/bin/bash


tar -xvzf audiotools-3.1.1.tar.gz
cd audiotools-3.1.1/ || exit
make install
cd .. || exit
rm -rf audiotools-3.1.1

pip install --upgrade setuptools
pip install -r requirements.txt
pip install SpeechRecognition
pip install pydub
#pip install pyinstaller

#echo "Cleaning up installation artefacts.."
#pyinstaller --onefile AudioFormatDetectiveCON.py
#rm -rf /venv
#rm -rf __pycache__
#rm -rf /build
#rm AudioFormatDetectiveCON.spec
#rm -rf /Test
#rm requirements.txt
#rm help.spec

echo "Done!"
