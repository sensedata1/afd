#!/bin/bash -x


tar -xvzf audiotools-3.1.1.tar.gz
cd audiotools-3.1.1/ || exit
make install
cd .. || exit
rm -rf audiotools-3.1.1

python -m venv venv
source venv/bin/activate

clear
echo "Installing pip packages..."
pip install --upgrade pip
pip install --upgrade setuptools
pip install -r requirements.txt

echo "Done!"
