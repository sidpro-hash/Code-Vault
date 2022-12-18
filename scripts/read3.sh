read -p " Enter the name of the file " name
if [ -e $name ]
then
   	ls -l $name
else
    	echo "File doesn’t exist"
fi
