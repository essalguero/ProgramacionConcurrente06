#!/bin/bash

HOSTS=$(cat host_file)

for HOST in $HOSTS
do
	echo $HOST
	scp -r ~/.ssh $HOST:~/
	scp -r host_file $HOST:~/
	scp -r ping.sh $HOST:~/
	ssh $HOST sh ~/ping.sh

done
