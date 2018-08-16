# Git Tutorial

`git` is one of the most common and popular versioning systems in the world.
You are already familiar with it from ECE281, so this should be simple. There
are only a couple of commands for you to learn (and you can only use these)

Only use these commands:

- `clone`: make a copy of a repository located in the internet/cloud
- `pull`: update your local repo with any changes in the repo in the cloud. This is necessary when working in a group or making changes via web browser to bitbucket.
- `status`: are there untracked changes in your local repo?
- `add`: gather up files in your local repo that have changed and you want to save those changes
- `commit`: after files have been added, bundle of them together with a description of the changes
- `push`: send a commit of changes to the repo in the cloud
- `log`: displays your commit history

Although the Codecademy.com lesson showed you more, in this case, **more is not
better!**

## `.gitignore`

CCS is a standard *horrible* IDE that we use. Unfortunately it generates a lot
of files we don't care about and we don't want that junk in our repo.

```bash
# Ignore everything
*
# ok, now we need to bring identify what we want to track
# let's start with:
# - assembly files
# - C files
# - Markdown files and jpg/png images
!.gitignore
!*.c
!*.h
!*.asm
!*.md
!*.jpg
!*.png
```

Further documentation on `git` is available [here](https://git-scm.com/docs/gitignore).

# Steps

1. Honestly, the easiest thing to do is go to the interweb (bitbucket) and in your browser, click on the (+) symbol on the lefthand side to create a new repo
1. You should see something like this below: ![](new-repo.png)
    1. Make sure the repo address is set to `https`, 10th CS blocks `ssh` (port 22)
1. Now Open up gitbash
1. Set some git properties by running these commands:
    1. `git config --global user.name "First Last"`
        1. Stores your name as a property to be used for each commit
    1. `git config --global user.email first.last@usafa.edu`
        1. Stores your email as a property to be used for each commit
1. Navigate to the directory where you want to store you projects
1. Next do: `git clone https://walchko@bitbucket.org/walchko/382-walchko.git`
    1. Change the repo address to the one **you** just created
1. Within this repo, create `.gitignore` like the one above
1. Ok, let's check the status of the repo
    1. Type `git status`
    1. This should show a list of files as untracked. The `.gitignore` should be listed there
1. Let's add the file
    1. Type `git add .gitignore`
        1. If you have lots of files, you can use wild cards like `*.c` to add all C files, `*.py` to add all python files (*not this class*), etc.
1. Let's make our first commit.
    1. Type `git commit -m "first commit"`
    1. Should see some data about the change listed
1. Let's look at our commit history.
    1. Type `git log`
    1. This displays all of the commits we've ever made to the repo
    1. Let's make a change to a file in our repo
1. Let's check the status now
    1. Type `git status`
    1. Everything should be up do date now

## Working with Bitbucket from the Browser

If you create, add or modify a file from the browser (remember you are modifying the repo in the cloud, not on your computer), so you should always do `git pull` first to update your local repo on your laptop. If you don't and you make changes to the same file on your computer, git doesn't know what changes you really want. It just knows two files are different and the cloud and your computer repos are out of sync!

This is also a good reason for branching, which we won't do in the class. But, if you have many different people working on the same code, you will create different branches so things can be merged back together cleanly. I would keep this in mind for capstone, but no one ever uses it primarily because our IT infrastructure is crap because of 10th CS.

## Oops!

Honestly, be careful with Google. If you wildly throw `git` commands at your system you will break it. If your *buddy* tells you to do something you don't understand, you could break your repo. **If you break your repo**, then it is up to you to fix it. Everything you need for the class is above, you should **never** need to come to an instructor because *your repo is broken*. On the positive side, if you break it, you will learn a lot about `git` trying to fix it!

---

# Advance `git` Stuff

**Ignore everything below for this class.** However, if you want to know more or want a little tutorial on advance features you are not allowed to use in this class, then proceed with caution.

## Adding a Remote

We want to share our work with the world!  Let's create a repository on Github.

- Go to http://www.github.com
- At the top right, there's an icon that looks like a book with a +-sign on it - click it!
- Give your repository a name - let's call ours **pong**
- Let's give it a description
    - I'll put "Capt B's pong game!"
- Leave the rest of the settings as their defaults
- Click create repository!
- We've create a repository, now we need to **push** our work to it.
- The page for your repo should give you a URL.
    - Mine is https://github.com/toddbranch/pong.git
- Type `git remote`
    - This shouldn't display anything - we haven't added any remote locations for our code yet!
- Type `git remote add origin "YOUR URL!"`
    - If you mess up the URL:
        - You can remove the remote by `git remote rm origin`
        - Now, add it again with the correct URL
- Type `git remote -v`
    - You should see origin - we just added it!
    - The `-v` tack means verbose - it will show us the names of the remotes and their URL
- Type `git branch`
    - You should see a single branch - master - because we haven't added any other branches yet.
- Type `git push origin master`
    - This tells git to push the master branch of our repo to the remote location called origin.
- You should be prompted for your username and password
- After entering that, you should see a bunch of files getting sent to Github!
- Go to https://github.com/YOUR_USER_NAME/YOUR_REPOO_NAME
    - Mine is at https://github.com/toddbranch/pong
    - Your first open source repo is being hosted on github!  Awesome!

## If You Added a README.md on the Github Website

Git is going to complain because your local repo and the repo on Github (origin) are different.  It wants you to pull in the new changes from Github before pushing your new changes.

- Let's pull in the new files from Github
    - Type `git pull origin master`
        - This is telling github to pull the master branch from origin
- Commit if you need to
- Now, we can push all our new changes back to Github!
    - Type `git push origin master`
- It should work now!

## Deleting a Repo

So you put a git repo where you didn't want one.  Maybe you put your whole hard drive under version control.  What next?

git keeps all of its files in a .git directory - to delete the repo, we just have to remove that: `rm -rf .git`.  This says remove the git directory and everything inside of it and don't ask me to verify deletes.

## Cloning

So you've got your repo created and being hosted on github.  What if you want to work on your files on a different computer?  You should clone (duplicate) your repository!

- Note the URL of the repo on github
- Navigate to the directory you want to clone into
- Type `git clone REPO_URL`
- Now you've got a copy of the repo in a new location!
- After you've made changes:
    - Push them back to the repo on Github via `git push origin master`

## Forking

You see some code you'd like to modify for your own purposes - you should fork your own copy!

- Navigate to the github page of the repo you're interested in
- In the top right corner, there's a button labeled fork - click it!
- Now you have your own copy in your git account
- Time to clone it to your local machine!  (see Cloning section)

## Branching

What if we want to maintain different versions of our code?  Say we want to store a version for required, B, and A functionality.  Or maybe we've got a piece of functionality going and we want to add a new feature without breaking existing code.  These are use cases for branches!

I'll use the "add a new feature" in my example.  Imagine we have our robot navigating the maze using IR sensors.  But we want to add a sonar feature to increase accuracy without breaking functionality of our working code.

- Let's take a look at our existing branches
    - Type `git branch`
        - This shows all of the branches in our repo
        - It should just list the master branch at this point
- Let's create a "sonar-feature" branch in which to add sonar support
    - Type `git branch sonar-feature`
- Let's make sure it was added
    - Type `git branch`
        - This should list two branches: master and sonar-feature
        - Master should have a * next to it - this means master is the branch we're currently developing in
- Let's switch to using our sonar-feature branch
    - Type `git checkout sonar-feature`
        - This switches our development to the sonar-feature branch
- Let's make sure we've switched
    - Type `git branch`
        - The sonar-feature branch should now be starred
- Now we can make and commit changes to our sonar-feature branch without impacting our master branch!  Great success!
- We can always checkout our master branch if we want to run our earlier code version!
