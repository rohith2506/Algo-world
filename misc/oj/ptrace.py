import os
import sys
import subprocess

os.chroot("/tmp/temp_usr")
proc = subprocess.Popen(['python', 'test.py'],stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
stddata = proc.communicate('2')
print stddata[1]
