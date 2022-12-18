clear
read -p "enter your age here:" age
if [ "$age" -ge 18 ]
then
	echo "your eligible for Trump meet"
elif [ "$age" -gt 10 ] && [ "$age" -lt 15 ]
then
	echo "your are Teenage"
else
	echo "your are not eligible"
fi
read -s -p "enter your password: " pass
echo ""
read -s -p "re-enter your password: " repass
echo ""
if [ "$pass" == "$repass" ]
then
	echo "pass matched..."
elif [[ "$pass" > "$repass" ]]
then
	echo "second match is Too small"
else
	echo "second match is Too large" 
fi
sleep 1
