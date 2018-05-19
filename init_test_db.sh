#!/bin/bash

sudo psql -h localhost -U $1 -d $2 -a -f test-data/ADD_TEST_PROBLEM_TO_DB.sql
