
read -p "Enter the filename " name
read -p "Permission Give or Take ? + or - ?" order
read -p "Which permission ?" Type
read -p "User , Group ,Other ? u/g/o ?" class

if [ $order == "+" ]
then 
	chmod $class$order$Type $name
fi
if [ $order == "-" ]
then 
	chmod $class$order$Type $name
fi
