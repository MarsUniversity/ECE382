# ECE 382

The website is built using [pandoc](http://pandoc.org/no) and [nodejs](https://nodejs.org/en/). We are also using a templating system (probably not necessary) called ejs which is found on [npm](https://www.npmjs.com/). Finally, we are using [Bootstrap](http://getbootstrap.com/) to produce a nice HTML5 navigation bar across the top of the page.

- `build.py` builds the website and dumps the html files into the folder `html`
- `deploy.py` performs the process of copying the website to `gh-pages` branch of
the git repo and publishes the updated website.

## Setup Github

You will probably have to create a `gh-pages` branch in your repo. Then double
check in the setting for the repo, that source for the webpage is the
`gh-pages` branch.

# Setup Computer

First you need to install:

1. gitbash
1. python 3
1. pandoc
1. basictex (if we have latex equations or you are building pdfs)
    1. Right now the only pdf I create is the syllabus

# Build and Deploy

1. Open a terminal window and navigate to the repo
1. [*Only do once*] You  need to install some python libraries:
    1. `pip3 install -U jinja2`
1. run: `./build.py`
1. Look in the `html` folder and the website should be there.
1. Once you are happy with everything, then `publish.py`

During the build process, you should see something like this:

```bash
kevin@Dalek ece382 $ ./build.py
Cleaning out old html ------------------
>> Made Syllabus
==[labs           ] ===============================
>> Made index.html
==[lab1           ] ===============================
>> Made index.html
==[lab2           ] ===============================
>> Made index.html
==[lab3           ] ===============================
>> Copying file arrayScreenShot.gif
>> Made index.html
>> Copying file ir_sensor.jpg
>> Copying file irWave.gif
>> Copying file lab-setup.png
>> Copying file Lab5_test.xlsx
>> Copying file launchpadSetup.jpg
>> Copying file schematic.jpg
>> Copying file start3.c
>> Copying file start3.h
>> Copying file test3.c
==[lab4           ] ===============================
>> Made index.html
>> Copying file lab-setup.png
>> Copying file servo.jpg
>> Copying file servos.png
==[lessons        ] ===============================
==[lsn1           ] ===============================
>> Made index.html
>> Copying file Lsn1.pptx
==[lsn13          ] ===============================
>> Made index.html
>> Copying file Lsn13.pptx
==[lsn14-15       ] ===============================
>> Made index.html
>> Made logic_analyzer.html
>> Copying file logic_analyzer_1.jpg
>> Copying file logic_analyzer_2.jpg
>> Copying file logic_analyzer_3.jpg
>> Copying file logic_analyzer_4.jpg
>> Copying file logic_analyzer_5.jpg
>> Copying file logic_analyzer_6.jpg
>> Copying file logic_analyzer_7.jpg
>> Copying file Lsn14-15.pptx
...
```
