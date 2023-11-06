python -c 'import numpy; print(numpy.__version__)'
if [ $? -eq 0 ]; then
    echo "Numpy is already installed upgrading it"
    pip install numpy --upgrade
else
    echo "Numpy is not installed, initializing install"
    pip install numpy
fi
