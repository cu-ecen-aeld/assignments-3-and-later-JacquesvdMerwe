filesdir=$1
searchstr=$2

if ! [ -n "$filesdir" ] || ! [ -n "$searchstr" ]
then
    echo "USAGE: finder [directory] [search_string]"
    exit 1
fi

if ! [ -d "$filesdir" ]; then
    echo "Invalid file directory"
    exit 1
fi

x=$(grep -R $searchstr $filesdir -c | wc -l | tr -d ' ')
y=$(grep -R $searchstr $filesdir | wc -l | tr -d ' ')

echo "The number of files are ${x} and the number of matching lines are ${y}"
