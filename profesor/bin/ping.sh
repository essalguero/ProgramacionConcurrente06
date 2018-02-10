#!/bin/bash

HOSTS=$(cat host_file)

for HOST in $HOSTS
do

	ping $HOST -c 1
done
