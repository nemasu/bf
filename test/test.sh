#!/bin/bash

pushd test &> /dev/null
echo -n "Test 1: "
test=`../bf test1.bf`
if [ "$test" == "Hello World!" ];
then
	echo "Pass"
else
	echo "Fail"
	return -1;
fi


echo -n "Test 2: "
test=`echo "1234" | ../bf test2.bf`
if [ "$test" == "1234" ];
then
	echo "Pass"
else
	echo "Fail"
	return -1;
fi
popd &> /dev/null
