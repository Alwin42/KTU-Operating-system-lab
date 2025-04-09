echo "Enter the number of terms"
read n
a=0 , b=1
i=2
echo "$a"
echo "$b"
for ( i=0 ; i<n-2 ; i++)
        do
        c = $((a+b))
        echo "$c"
        a = $b
        b = $c
        done
