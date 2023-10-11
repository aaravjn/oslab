current_python_version=$(python3 --version)
expected_version="Python 3.6.0"

echo $current_python_version

if [ "$current_python_version" != "$expected_version" ]; then
	echo Version did not match
	sudo apt-get install python3.6

 else
	echo Version matched!

 fi
