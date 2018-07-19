#!/usr/bin/env python3
from subprocess import check_output  # call command line
import os              # make directories, change current dir, etc
import platform        # macOS or windows
import shutil          # move and delete files/folders
from glob import glob  # get contents of folder
from jinja2 import Environment, FileSystemLoader  # html templating

devnull = open(os.devnull, 'w')


def run(cmd):
    # given a command string, it runs it
    cmds = cmd.split()
    return check_output(cmds)


def mkdir(path):
    try:
        os.mkdir(path)
    except FileExistsError:
        # folder was already created ... it's ok
        pass


def pandoc(file, dest, template=None, format='html', to_main=None):
    # need to keep track of folder stucture for navigation bar across
    # the top of the page
    if to_main is None:
        to_main = '.'

    split = file.split('.')

    # files should have an extention, but directories don't
    if len(split) == 2:
        f, ext = split
        ext = ext.lower()

        if ext == 'md':
            if format == 'pdf':
                run('pandoc {}.md -V geometry:margin=1in -s -o {}.pdf'.format(f, f))
                shutil.move(f + '.pdf', dest + '/' + f + '.pdf')
                print(">> Made {}".format(f + '.pdf'))

            elif format == 'html':
                if template is None:
                    raise Exception("*** You need to pass a template to convert Markdown to HTML ***")

                # creates the html5 from markdown and sets pandoc.css to look pretty!
                html = run('pandoc -c pandoc.css -t html5-smart {0}.md'.format(f, f))
                # print('*'*40)
                # print(html.decode('utf8'))
                # print('*'*40)
                html = template.render(info=html.decode('utf8'), path=to_main)
                with open(dest + '/' + f + '.html', 'w') as fd:
                    fd.write(html)
                print(">> Made {}".format(f + '.html'))

            else:
                print("*** Invalid Format: {} ***".format(format))

        elif ext == 'html':
            print("left over html:", file)

        # these are other file types we just want to copy
        elif ext in ['pdf', 'pptx', 'ppt', 'png', 'jpg', 'c', 'asm', 'xlsx', 'gif', 'h', 'txt', 'css']:
            path = dest + '/' + file
            print('>> Copying file {}'.format(file))
            shutil.copy(file, path)

        else:
            print("*** Unknown format: {} ***".format(file))
            print("*** Maybe add them above into file types to move ***")
            raise Exception()

    # let's handle directories
    elif len(split) == 1:
        # this must be a directory, let's change into it
        print('==[{:15}] ==============================='.format(file))

        # make the destination path have the same folder
        path = dest + '/' + file
        mkdir(path)

        # change into it, get the files and recursively call pandoc
        os.chdir(file)
        files = glob('*')
        for f in files:
            pandoc(f, '../' + dest + '/' + file, template, format, to_main=to_main + '/..')
        os.chdir('../')
    else:
        print('***********************************')
        print('*** Unknown Error: {}'.format(split))
        print('***********************************')
        # raise Exception()

def main():
    # delete the old website so we don't miss anything when building
    print('Cleaning out old html ------------------')
    shutil.rmtree('html')
    os.mkdir('html')

    # change into source and recursively build website
    os.chdir("source")
    files = glob("*")

    # don't try to build html from the template, we use it another way!
    files.remove('template.jinja2')
    template = Environment(loader=FileSystemLoader('.'), trim_blocks=True).get_template('template.jinja2')

    # Do something special for the syllabus page
    files.remove('index.md')
    # creates the html5 from markdown and sets pandoc.css to look pretty!
    html = run('pandoc -s --toc -c pandoc.css index.md -t html5-smart')
    html = template.render(info=html.decode('utf8'), path='.')
    with open('../html' + '/index.html', 'w') as fd:
        fd.write(html)
    print(">> Made Syllabus")

    # for each file/directory in sourece build it into pdf or copy it
    for f in files:
        pandoc(f, '../html', template, 'html')

    # make a pdf of the syllabus
    pandoc('index.md', '../html', format='pdf')

    # done
    os.chdir('../')


if __name__ == "__main__":
    # this is a problem on macOS, where these stupid os files get found
    os.system("find . -type f -name '.DS_Store' -exec rm {} +")
    main()
