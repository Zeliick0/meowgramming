#!/bin/bash
echo "Today is $(date +%A)"

echo -n "Mnau? " 
read ans

if [ $ans = "meow" ] || [ $ans = "nya" ]; then
    echo "Yippie ^~^"
elif [ $ans = "woof" ]; then
    echo "Not a cat? :c"
else
    echo "Nyooo T-T"
fi

echo "What's the letter: "
read letter
if  whoami | grep -q "$letter"; then
    echo "The user: $(whoami) has that letter"
else
    echo "The user doesn't have that letter"
fi

