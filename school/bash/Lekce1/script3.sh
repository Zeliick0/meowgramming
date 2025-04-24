#!/bin/bash

pass="727w"

until [ "$pass" == "$input" ];
do
    read -sp "Input your password: " input
    if [ "$pass" == "$input" ]; then
        echo -e "\n Spravne heslo!~"
    else 
        echo -e "\n Chybne heslo GRR"
    fi
done
