#!/usr/bin/sh
# run as root!

# config
src=lua-5.2.1

# download
apt-get install libreadline6-dev libncurses5-dev
wget -c http://www.lua.org/ftp/$src.tar.gz

# install
tar zxvf $src.tar.gz
cd $src
make linux

# clean
cd ..
rm -f $src.tar.gz
rm -fr $src

# response
echo '\n\n\n\n'
echo '========================================'
echo '|    Lua is installed successfully!    |'
echo '========================================'
