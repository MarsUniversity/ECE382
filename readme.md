# ECE 382

The website is built using [pandoc](http://pandoc.org/no) and [nodejs](https://nodejs.org/en/). We are also using a templating system (probably not necessary) called `ejs` which is found on [npm](https://www.npmjs.com/). Finally, we are using [Bootstrap](http://getbootstrap.com/) to produce a nice HTML5 navigation bar across the top of the page.

- `build.js` builds the website and dumps the html files into the folder `html`
- `deploy.sh` performs the process of copying the website to `gh-pages` branch of
the git repo and publishes the updated website.

## Setup Github

You will probably have to create a `gh-pages` branch in your repo. Then double
check in the setting for the repo, that source for the webpage is the
`gh-pages` branch.

# Build and Test Locally

First you need to install:

1. gitbash
1. node
1. pandoc
1. basictex (if we have latex equations or you are building pdfs)

## Build

1. Open a terminal window and navigate to the repo
1. run: `npm install` to get some libraries downloaded to `node_modules` folder
    1. This installs ejs, you only have to do this once
1. run: `./build.js`
1. Look in the `html` folder and the website should be there

During the build process, you should see something like this:

```bash
kevin@Dalek ece382 $ build.js
-------------------------------------------
Searching: source
-------------------------------------------
Searching: source/admin
Wrote: html/admin/c_style_guide.html
Wrote: html/admin/course_goals.html
Wrote: html/admin/course_letter.html
-------------------------------------------
Searching: source/admin/final_resources
Copied: html/admin/final_resources/ADC10AE0.jpg
Copied: html/admin/final_resources/ADC10CTL0_1.jpg
Copied: html/admin/final_resources/ADC10CTL0_2.jpg
Copied: html/admin/final_resources/ADC10CTL0_3.jpg
Copied: html/admin/final_resources/ADC10CTL1_1.jpg
Copied: html/admin/final_resources/ADC10CTL1_2.jpg
...
```
