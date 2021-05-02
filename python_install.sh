wget https://www.python.org/ftp/python/3.8.6/Python-3.8.6.tgz
tar -xzf Python-3.8.6.tgz
cd Python-3.8.6
./configure –enable-optimizations
make -j 4
sudo make install
