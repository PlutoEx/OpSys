mkdir week1
mkdir week10

echo "TEXT 2" > ./week1/file.txt
link ./week1/file.txt ./week10/_ex2.txt

find . -inum $(ls -i ./week1/file.txt | awk '{print $1}') > ex2.txt
find . -inum $(ls -i ./week1/file.txt | awk '{print $1}') -exec rm {} \;