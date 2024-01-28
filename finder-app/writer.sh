# writefile=$1
# writestr=$2

# if ! [ -n "$writefile" ] || ! [ -n "$writestr" ]
# then
#     echo "USAGE: writer [write_file] [value_to_write]"
#     exit 1
# fi
# 
# directory=$(dirname $writefile)
# mkdir -p $directory
# 
# echo $writestr > $writefile
