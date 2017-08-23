#!/bin/bash

grep 'error' -ir ./*/*/*log* | grep -v 'error_scripts' | grep -v 'Off-axis error'
