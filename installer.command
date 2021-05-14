#!/usr/bin/env bash

BASEDIR=$(dirname $0)

echo $BASEDIR
cd $BASEDIR
python3 -m venv venv
source venv/bin/activate
tar -xvzf audiotools-3.1.1.tar.gz
pushd audiotools-3.1.1/
make install
popd

pip3 install --upgrade pip
pip3 install --upgrade setuptools
pip3 install -r requirements.txt
pip3 install eyed3
pip3 install colors.py
pip3 install SpeechRecognition
pip3 install pydub
pip3 install watchdog

cat << EOF > /usr/local/bin/afd
source ${BASEDIR}/venv/bin/activate
python3 ${BASEDIR}/AudioFormatDetectiveIMAP2.py
EOF

cat << EOF > ~/Desktop/afd.command
afd
EOF

chmod a+x ~/Desktop/afd.command
chmod a+x /usr/local/bin/afd

clear
echo "*************************************************************"
echo "**   To use AudioFormatDetective, locate afd.command on    **"
echo "**   the Desktop and double click to open. Alternatively   **"
echo "**   open a terminal window, and type: afd                 **"
echo "*************************************************************"
