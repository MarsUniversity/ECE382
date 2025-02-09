#!/usr/bin/env python3
from subprocess import check_output
import platform
import os
import tempfile
import shutil
import sys

devnull = open(os.devnull, 'w')

def run(cmd):
    # given a command string, it runs it
    cmds = cmd.split()
    return check_output(cmds)


REMOTE = "git@github.com:MarsUniversity/ece382.git"
REPO = "github.com/MarsUniversity/ece382"
BRANCH = "gh-pages"
FOLDER = "html"

tmp = tempfile.mkdtemp()

# recursively copy everything to the tmp directory
# make a new git repo and push everything to the branch
# this will make github display the webpages
shutil.copytree('html', tmp + '/html')

os.chdir(tmp + '/html')

print('====================')
print('    Redoing git')
print('====================')
sys.stdout.flush()  # have to do this for windoze, it sucks!!

run('git init')
run('git add *')
run('git commit -m "Deploying-to-{}:{}"'.format(REPO, BRANCH))


print('====================')
print('    git push')
print('====================')
sys.stdout.flush()  # have to do this for windoze, it sucks!!

run('git push --force {} master:{}'.format(REMOTE, BRANCH))
sys.stdout.flush()  # have to do this for windoze, it sucks!!

# from glob import glob
# print(os.getcwd())
# for g in glob('*'):
#     print(g)
