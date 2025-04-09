echo "Enter the number"
read n

if [ $n -lt 0 ]; then
    echo "Negative number"
elif [ $n -gt 0 ]; then
    echo "Positive number"
else
    echo "Number is zero"
fi

