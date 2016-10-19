# Final-Project
The final project source code

Github cheat sheet, to help you guys with the commands in command prompt/terminal
## [Github Cheatsheet](https://services.github.com/kit/downloads/github-git-cheat-sheet.pdf)

### Get Started
First, download git for windows/mac/linux depending on your operating system. I recommend the command line version (Git Bash for windows) but the GUI version should work as well, though the follow will not apply to the GUI.

Now open a command prompt or terminal and **cd** to a directory you want to work in. Use the following command to create the project folder:
```sh
git clone https://github.com/COP3503-UF-Project-Team-3/Final-Project
```
This will create a folder named "Final-Project".

Next, **cd** into the "Final-Project" folder. Now you will set your username and email in git using:
```sh
git config --global user.name USERNAME
git config --global user.email EMAIL@DOMAIN.WHATEVER
```
Where USERNAME can be anything you want and the EMAIL must be the same email you used to register with Github.

Now you can create your own branch and commit to it and do all sorts of cool stuff. Continue reading for some more tips.
### Best Practice
Create your own branch to work on and commit to that instead of commiting directly to master. To create your own branch use:
```sh
git checkout -b BRANCHNAME
```
Where **BRANCHNAME** is whatever you want. Then commit normally to your branch. You can check your current branch with any of the two commands:
```sh
git branch
git status
```
If you wish to return to the master branch just use:
```sh
git checkout master
```
Your work will remain in your branch which you switch to by using the same command with your branch name instead of master.

After you have some work and some commits you can push your branch to the repository using:
```sh
git push origin BRANCHNAME
```
Where BRANCHNAME is the name of your branch or what ever branch you want to upload.

Once you are ready to merge your work with the master branch, first pull the master branch and merge the master branch into **your branch**. To do this make sure you are in **your branch** and run:
```sh
git pull master
```
This will pull the latest version of master and try to merge it into your branch. If there are any merge conflicts, git will notify you. You can go into the offending file and correct the conflict. Once you have corrected everything you can commit the fix to your branch. Once the merge from master is successful please use Githubs pull request feature, located on the main page of the **repository**. This will notify everyone that you are ready to merge into master and allow someone else to **OK** your merge. 

#### Note
```sh
git reset
```
May be used to undo an erroneous commit, but very careful with how you use it, specially if you use it with the --hard flag. Make sure you read on how git reset works before using it as it can potentially destroy any work you have done. 

