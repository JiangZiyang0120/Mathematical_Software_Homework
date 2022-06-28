#! /bin/bash

# pull the blog from remote repo
# and get the return string
information=`git pull origin main`

# if there is nothing changed
# we needn't to operate

if [ "$information" = "已经是最新的。" ]; then
	echo "There isn't uploaded blog in the remote repo"
	exit 0
else
	# else we need to move the changed file into ./ directory
	# the blog file dire is ./blog_updating and ./blog_completing
	for direc in $(ls); do
		if [ -d $direc ]; then
			echo "in directory $direc, file:"
			for file in ./$direc/*; do
				echo -n "$file; "
			done
			mv ./$direc/* ./
			rm -rf ./$direc
			echo "moved successfully"
		fi
	done

	echo "blog source uploaded successfully"
fi

exit 0
