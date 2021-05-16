#!/bin/bash


tar -xvzf audiotools-3.1.1.tar.gz
cd audiotools-3.1.1/ || exit
make install
cd .. || exit
rm -rf audiotools-3.1.1

python -m venv venv
source venv/bin/activate

clear
echo "Installing pip packages..."
pip install --upgrade pip --quiet
pip install --upgrade setuptools --quiet
pip install -r requirements.txt --quiet

echo "Done!"
