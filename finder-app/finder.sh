#! /bin/bash 

function usage_err(){
  echo "Use:"
  echo "$0 <filesdir> <searchstr>"
  echo ""
  echo "Where <filesdir> must be a valid directory"
  exit 1;
}

if [ "$#" != 2 ]; then
	usage_err
fi

filesdir=$1
searchstr=$2

test -d ${filesdir} || ( usage_err )
X=$(find ${filesdir}| tail -n +2 |wc -l)
Y=$(find ${filesdir} -type f -exec grep "${searchstr}" {} \; | wc -l)
MESSAGE="The number of files are ${X} and the number of matching lines are ${Y}"
echo ${MESSAGE}
