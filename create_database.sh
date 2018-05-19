#!/bin/bash

#создать пользователя
#sudo -u postgres createuser testUser
#создать базу пользователя 
#sudo -u postgres createdb -O testUser test

sudo -u postgres createuser $1
sudo -u postgres createdb -O $1 $2
