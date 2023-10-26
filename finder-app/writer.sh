#! /bin/bash 

function usage_err(){
  echo "Use:"
  echo "$0 <writefile> <writestr>"
  echo ""
  echo "Where <filesdir> must be a valid directory"
  exit 1;
}

if [ "$#" != 2 ]; then
	usage_err
fi

writefile=$1
writestr=$2

writeparentdir=$(dirname "${writefile}")
test -d "${writeparentdir}" || mkdir -p "${writeparentdir}"

echo ${writestr} > "${writefile}" || ( echo "cannot create ${writefile}"; exit 1)
