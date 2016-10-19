# Final-Project
The final project source code

Github cheat sheet, to help you guys with the commands in command prompt/terminal
## [Github Cheatsheet](https://services.github.com/kit/downloads/github-git-cheat-sheet.pdf)

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

Once you are ready to merge your work with the master branch, first merge the master branch into **your branch**. To do this make sure you are in your branch and run
```sh
git merge master
```
If there are any merge conflicts, git will notify you. You can go into the offending file and correct the conflict. Once you have corrected everything you can commit the fix to your branch. Once the merge from master is successful please use Githubs pull request feature, located on the main page of the **repository**. This will notify everyone that you are ready to merge into master and allow someone else to **OK** your merge. 

#### Note
```sh
git reset
```
May be used to undo an erroneous commit, but very careful with how you use it, specially if you use it with the --hard flag. Make sure you read on how git reset works before using it as it can potentially destroy any work you have done.


