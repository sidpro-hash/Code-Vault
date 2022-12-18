clear
echo "enter word to find: "
read word
echo "enter file name if in dir than dir also :"
read dire
word_count=`grep -c $word $dire`
echo $word_count
sleep 2
