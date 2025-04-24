#!/bin/bash

read -p "Zadej nazev souboru: " soubor
echo -e "\nVyber jednu z moznosti nabidky: "

select volba in vytvor odstran ukonci
do
    case $volba in 
        vytvor)
            touch $soubor;
            chmod 777 $soubor;;
        odstran)
            rm -rf $soubor;;
        ukonci)
            exit;;
        *) echo "\nNeplatna moznost ";;
    esac
done
