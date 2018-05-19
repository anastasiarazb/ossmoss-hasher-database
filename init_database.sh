#!/bin/bash

#psql -h <host> -U <user> -d <database> -a -f CREATE_DATABASE_OBJECTS.sql

psql -h localhost -U $1 -d $2 -a -f CREATE_DATABASE_OBJECTS.sql
