#!/bin/bash
python setup.py build
sudo python setup.py install
python test.py
