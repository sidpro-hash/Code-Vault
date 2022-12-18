clear
echo "entered name or number printed below"
arr=("$@")
for i in `seq 0 1 $#`;
do
	echo ${arr[i]} 
done
echo "arguments:$@  total argumentd: $#"
sleep 1
