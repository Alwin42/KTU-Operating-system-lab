echo "Linear Search "
echo "Enter the size of the array: "
read n
echo "Enter the elements: "

        for (( i=0 ; i<n ; i++ ))
        do
        read a[$i]
        done
echo -n "Enter the element to search : "
read x
 for (( i=0 ; i<n ; i++ ))
        do
        if [ $[a[$i]] -eq $x ]
        then break
        fi
done
if [ $i -eq $n ]
        then 
        echo "Element not found"
else 
        echo "Element found at index $i"
fi

