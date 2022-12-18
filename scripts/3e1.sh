read -p "enter file name " File
l=temp.txt
if [ -f "$File" ]
then
	cat $File | tr "[A-Z]" "[a-z]"|cat >> $l
	cp $l $File
	rm $l
	cat $File
else
	echo "file does not exist"
fi
