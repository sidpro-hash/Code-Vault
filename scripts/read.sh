clear
read -p "enter username:" name
read -s -p "enter password:" pass
echo ""
echo "your username $name"
echo "your password $pass"
echo "now enter your friends nmes:"
read -a names
echo "${names[0]},${names[1]},${names[2]},${names[3]}"
echo "fro restricted input"
read -n 6 lol
echo ""
echo "$lol"
echo "without variable "
read 
echo "$REPLY"
sleep 2
