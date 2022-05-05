read -p " Enter the name of the file " name
ls -l | grep $name | awk '{print $1,$9}'
