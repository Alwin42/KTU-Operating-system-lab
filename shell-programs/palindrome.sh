echo "palindrome"
echo -n "Enter the string : "
read S
rev="$(rev <<< "$S")"
if [ $rev == $S ]
then 
        echo "Palindrome"
else
        echo "Not palindrome "
fi
