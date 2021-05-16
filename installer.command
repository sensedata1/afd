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
echo "Installing audiotools..."
tar -xvzf audiotools-3.1.1.tar.gz
pushd audiotools-3.1.1/
make install clean BATCH=yes
popd
clear
echo "Installing pip packages..."
pip3 install --upgrade pip --quiet
pip3 install --upgrade setuptools --quiet
pip3 install -r requirements.txt --quiet
#pip3 install --quiet eyed3 colors.py SpeechRecognition pydub watchdog


cat << EOF > /usr/local/bin/afd
source ${BASEDIR}/venv/bin/activate
python3 ${BASEDIR}/AudioFormatDetectiveIMAP2.py
EOF

cat << EOF > /usr/local/bin/afd-lite
source ${BASEDIR}/venv/bin/activate
python3 ${BASEDIR}/AudioFormatDetectiveIMAP.py
EOF

cat << EOF > ~/Desktop/afd.command
afd
EOF

chmod a+x ~/Desktop/afd.command
chmod a+x /usr/local/bin/afd
chmod a+x /usr/local/bin/afd-lite

if [[ $(which afd) == $AFDPATH ]]
    then
        clear
        echo "*************************************************************"
        echo "*************** Installation succeeded! *********************"
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

