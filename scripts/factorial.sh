clear
read -p "enter any number to find factorial : " x
result=1
i=1
for i in `seq 1 1 $x`;
do
	result=$(( $result*$i ))
done
echo "your answer is here :"$result
echo "Goodby"
sleep 2 
