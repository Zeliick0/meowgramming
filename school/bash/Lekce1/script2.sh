#!/bin/bash

function sqr() {
    echo $(( $1 * $1 ))
}

read -p "Input the first value: " a
read -p "Input the second value: " b

sum=$[ $a + $b ]
sub=$[ $a - $b ]
mult=$[ $a * $b ]
div=$[ $a / $b ]

echo "Sum is: $sum"
echo "Substraction is: $sub"
echo "Multiplication is: $mult"
echo "Division is: $div"
echo "Number 1 squared is $(sqr $a)"
echo "Number 2 squared is $(sqr $b)"

