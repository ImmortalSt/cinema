for i in $(find -name "*.c"); do
	path=${i::-2}
	if [ $path == "./main" ]; then
		continue
	fi
	echo $path
	gcc -c -Wall -Werror -g -fpic $path.c -o $path.o
done;


includes=""
for i in $(find -name "*.o"); do
    includes+="$i "
done;
gcc -g main.c -o main $includes