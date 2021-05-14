#!/usr/bin/env bash


TOOLSPATH="/Library/Developer/CommandLineTools"
BASEDIR=$(dirname $0)
AFDPATH="/usr/local/bin/afd"

echo $BASEDIR
cd $BASEDIR
clear
echo "Installing AudioFormatDetective..."
sleep 2
echo "Checking for OSX CommandLineTools..."
sleep 2

if [[ $(xcode-select -p) != ${TOOLSPATH} ]]
    then
        echo "No installation of CommandLineTools found, prompting to install..."
        sleep 2
        xcode-select --install
        echo ""
        echo ""
        clear
        echo "Pausing for CommandLineTools installation, please click the Install button on the popup"
        read -n 1 -s -r -p "Press any key to continue once the installation is complete"
    else
        echo "CommandLineTools found, proceeding..."
        sleep 2
        echo ""
        echo "make version = " $(make --version)
        sleep 2
fi

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

if [[ $(which afd) == $AFDPATH ]]
    then
        echo "*************************************************************"
        echo "*************** Installation succeeded!" ********************"
        echo "*************************************************************"
        echo ""
        sleep 2
        echo "*************************************************************"
        echo "**   To use AudioFormatDetective, locate afd.command on    **"
        echo "**   the Desktop and double click to open. Alternatively   **"
        echo "**   open a terminal window, and type: afd                 **"
        echo "*************************************************************"
    else
        echo "Arse! There was a problem with the installation, please call technical support :P"
fi

