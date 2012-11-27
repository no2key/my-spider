#!/usr/bin/sh
# run as root!
src=lua-5.2.1
apt-get install libreadline6-dev libncurses5-dev
wget -c http://www.lua.org/ftp/$src.tar.gz
tar zxvf $src.tar.gz
cd $src
make linux
cd ..
rm -f $src.tar.gz
rm -fr $src
echo '\n\n\n\n'
echo '========================================'
echo '|    Lua is installed successfully!    |'
echo '========================================'
