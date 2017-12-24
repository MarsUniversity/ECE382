# ECE 382

The website is built using [travis-ci](https://travis-ci.org), [pandoc](http://pandoc.org/no) and [nodejs](https://nodejs.org/en/). We are also using a templating system (probably not necessary) called ejs which is found on [npm](https://www.npmjs.com/). Finally, we are using [Bootstrap](http://getbootstrap.com/) to produce a nice HTML5 navigation bar across the top of the page.

- `build.js` builds the website
- `.travis.yml` the setup file for travis-ci and tells it how to build the website
- `deploy.sh` performs the process of copying the website to `gh-pages` and publishes the updated website.

## Setup Github

You will probably have to create a `gh-pages` branch. Then double check in the setting for the repo, that source is the `gh-pages branch`.

## Travis-CI

Grant access to your github repo so travis can clone and build it. You will also need to grant access for travis to write back to the repo under the `gh-pages` branch.

### Grant Push Access

- Generate a [Personal Access Token](https://help.github.com/articles/creating-a-personal-access-token-for-the-command-line/) on github, make sure to select **public_repo**.
- Add it to your travis account settings by setting [environment variable](https://docs.travis-ci.com/user/environment-variables#Defining-Variables-in-Repository-Settings) called GITHUB_TOKEN with a value of the personal access token (lots of numbers)

# Build Locally

First you need to install:

1. gitbash
1. node
1. pandoc
1. basictex (if we have latex equations or you are building pdfs)

## Build

1. Open a terminal window and navigate to the repo
1. run: `npm install`
    1. This installs ejs, you only have to do this once or again to update the library 
1. run: `node build.js`
1. Look in the `html` folder and the website should be there
