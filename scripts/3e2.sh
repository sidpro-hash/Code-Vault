user=`who | awk '{print $2}' `
if [ $user = ":0" ]
then 
	x=`finger  $2  |  head  -n  3`
	echo "$x  \n"
fi
