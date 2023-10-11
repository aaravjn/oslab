python -c 'import numpy; print(numpy.__version__)'
if [ $? -eq 0 ]; then
    echo "Numpy is already installed"
else
    echo "Numpy is not installed, initializing install"
    pip install numpy
fi
