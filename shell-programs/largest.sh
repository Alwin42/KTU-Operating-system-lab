echo "Enter Three Numbers"
echo "Enter the first number"
read n1
echo "Enter the second number"
read n2
echo "Enter the third number"
read n3

if [ $n1 -gt $n2 ]; then
        if [ $n1 -gt $n3 ]; then
                echo "first number is largest "
        else 
                echo "third number is largest"
        fi

elif [ $n2 -gt $n1 ]; then 
        if [ $n2 -gt $n3 ]; then 
                echo "second number is largest"
        else 
                echo "third number is largest"
        fi
else 
                echo "third number is largest"
        
fi

